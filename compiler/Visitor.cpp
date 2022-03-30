#include "Visitor.h"
#include <iostream>
#include "error/SyntaxErrorListener.h"

using namespace std;

Visitor::Visitor(SymbolTable *symbolTable) : edx{"", false}, eax{"", false} {
    this->symbolTable = symbolTable;
}

Visitor::~Visitor() {}

antlrcpp::Any Visitor::visitAxiom(ifccParser::AxiomContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context) {
    cout << ".text\n";
#ifdef __APPLE__
    cout << ".globl _main\n"
            " _main: \n";
#else
    cout << ".globl	main\n"
            " main: \n";
#endif
    cout << "   pushq %rbp\n"
            "   movq %rsp, %rbp\n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitBlock(ifccParser::BlockContext *context) {
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatement1(ifccParser::Statement1Context *context) {
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatement2(ifccParser::Statement2Context *context) {
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatement3(ifccParser::Statement3Context *context) {
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitDeclaration(ifccParser::DeclarationContext *context) {
    for (const auto var : context->IDENT()) {
        string newVariableName = var->getText();
        int level = 0;

        if (!this->symbolTable->doesSymbolExist(newVariableName)) {
            this->symbolTable->declareSymbol(newVariableName, level, INT, 0, DECLARED, 0);
        } else {
            //TODO:: gestion des erreurs
            cout << "variables : newVariableName already exist " << endl;
        }
    }
    return 0;
}

antlrcpp::Any Visitor::visitAffectation1(ifccParser::Affectation1Context *context) {
    // TODO:: affect in symbole table
    // declaration + affectation
    //type VAR '=' expression
    string newVariableName = context->IDENT()->getText();
    int level = 0;
    int address = 0;
    int last_tmp = visitChildren(context);
    if (!this->symbolTable->doesSymbolExist(newVariableName, level)) {
        address = this->symbolTable->addSymbol(newVariableName, level, INT, 0, ASSIGNED, 0);
    } else {
        //TODO:: gestion des erreurs
        cout << "affect 1: newVariableName already exist " << endl;
    }
    cout << "   movl	" << last_tmp << "(%rbp), %eax\n";
    // TODO:: get address variable


    cout << "   movl	%eax," << address << "(%rbp) \n";

    return 0;
}

antlrcpp::Any Visitor::visitAffectation2(ifccParser::Affectation2Context *context) {
    // TODO:: affect in symbole table
    // affectation
    //VAR '=' expression

    string newVariableName = context->IDENT()->getText();
    int level = 0;
    int address = 0;
    int last_tmp = visitChildren(context);
    cout << "   movl	" << last_tmp << "(%rbp), %eax\n";

    // si le symbole existe dans la symbolTable, on recupere son adresse
    Symbol *symbolReturned = this->symbolTable->returnSymbol(newVariableName, level);
    if (symbolReturned != nullptr) {
        if (symbolReturned->getStateSymbol() == ASSIGNED) {
            address = symbolReturned->getAddress();
        } else {
            address = this->symbolTable->assignSymbol(symbolReturned);
        }
    } else {
        //TODO:: gestion des erreurs
        cout << "affect 2: newVariableName does not exist " << endl;
    }

    // TODO:: get address variable
    cout << "   movl	%eax," << address << "(%rbp) \n";

    return 0;
}

/*
antlrcpp::Any Visitor::visitAffectation3(ifccParser::Affectation2Context *context) {
    // TODO:: affect in symbole table
    // affectation
    //VAR '=' expression

    if(context->LVALUE() != VAR()){
        //On récupère l'adresse tmp de expr
        //movq $-16, -72(%rbp)

        //Ensuite on cherche adresse de notre lvalue
        //movq %rbp, %rax
        //addq -72(%rbp), %rax
        //movq %rax, -72(%rbp)
        //
        //movq -72(%rbp), %rax
        //movq -64(%rbp), %r10
        //movq %r10, (%rax)
    }else{

        string newVariableName = context->VAR()->getText();
        int level = 0;
        int address = 0;
        int last_tmp = visitChildren(context);
        cout << "   movl	" << last_tmp << "(%rbp), %eax\n";

        // si le symbole existe dans la symbolTable, on recupere son adresse
        Symbol *symbolReturned = this->symbolTable->returnSymbol(newVariableName, level);
        if (symbolReturned != nullptr) {
            if (symbolReturned->getStateSymbol() == ASSIGNED) {
                address = symbolReturned->getAddress();
            } else {
                address = this->symbolTable->assignSymbol(symbolReturned);
            }
        } else {
            //TODO:: gestion des erreurs
            cout << "affect 2: newVariableName does not exist " << endl;
        }

        // TODO:: get address variable
        cout << "   movl	%eax," << address << "(%rbp) \n";
    }

    return 0;
}
*/

antlrcpp::Any Visitor::visitRet1(ifccParser::Ret1Context *context) {
    int retval = stoi(context->CONST()->getText());
    cout << " 	movl	$" << retval << ", %eax\n"
                                          "   popq %rbp #restore %rbp from the stack\n"
                                          " 	ret\n";

    return 0;
}

antlrcpp::Any Visitor::visitRet2(ifccParser::Ret2Context *context) {
    string variableName = context->IDENT()->getText();
    int level = 0;
    int address = 0;
    //TODO: Test existence

    Symbol *symbolReturned = this->symbolTable->returnSymbol(variableName, level);
    if (symbolReturned != nullptr && symbolReturned->getStateSymbol() == ASSIGNED) {
        address = symbolReturned->getAddress();
    } else {
        //TODO:: gestion des erreurs
        cout << "ret 2 : variableName does not exist " << endl;
    }

    cout << "   movl	" << address << "(%rbp), %eax\n"
                                        "   popq %rbp\n"
                                        "   ret\n";
    return 0;
}

antlrcpp::Any Visitor::visitUnaryexpr(ifccParser::UnaryexprContext *context) {
    int expr = visit(context->expression());

    //TODO create temp var 
    //TODO check if not necessary : int address = 0;
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    cout << "   movl " << expr << "(%rbp), %eax\n";
    if (context->op->getText() == "-") {
        cout << "   negl %eax\n";
    } else {
        cout << "   notl %eax\n";
    }

    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitCharexpr(ifccParser::CharexprContext *context) {
    string variable = context->CHARACTER()->getText();
    char character = variable.substr(1, 2)[0];
    int value = (int) character;

    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    cout << "   movl	$" << value << ", " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitRelationalexpr(ifccParser::RelationalexprContext *context) {
    int exprLeft = visit(context->expression(0));
    int exprRight = visit(context->expression(1));

    //opti : check if one expr is equal to 1
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    cout << "   movl " << exprLeft << "(%rbp), %eax\n";
    cout << "   cmpl " << exprRight << "(%rbp), %eax\n";

    if (context->op->getText() == ">") {
        cout << "   setg    %al\n";

    } else if (context->op->getText() == ">=") {
        cout << "   setge   %al\n";

    } else if (context->op->getText() == "<") {
        cout << "   setl    %al\n";

    } else {     //if(context->op->getText() == "<=")
        cout << "   setle   %al\n";

    }
    cout << "   movzbl  %al, %eax\n";
    cout << "   movl    %eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitBracketexpr(ifccParser::BracketexprContext *context) {
    return visit(context->expression());
}

antlrcpp::Any Visitor::visitVarexpr(ifccParser::VarexprContext *context) {
    string variable = context->IDENT()->getText();
    //TODO: check existence and get adress
    int address = 0;
    int level = 0;

    Symbol *symbolReturned = this->symbolTable->returnSymbol(variable, level);
    if (symbolReturned != nullptr && symbolReturned->getStateSymbol() == ASSIGNED) {
        address = symbolReturned->getAddress();
    } else {
        //TODO:: gestion des erreurs
        cout << "ret 2 : variableName does not exist " << endl;
    }

    return address;
}

antlrcpp::Any Visitor::visitMultplicationexpr(ifccParser::MultplicationexprContext *context) {

    int exprLeft = visit(context->expression()[0]);
    int exprRight = visit(context->expression()[1]);

    //opti : check if one expr is equal to 1
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    cout << "   movl " << exprLeft << "(%rbp), %eax\n";
    if (context->op->getText() == "*") {
        cout << "   imul " << exprRight << "(%rbp), %eax\n";
        cout << "   movl    %eax, " << address << "(%rbp) \n";
        //result = leftExpr * rightExpr;
    } else {
        cout << "   idivl " << exprRight << "(%rbp), %eax\n";
        if (context->op->getText() == "/") {
            //result = leftExpr / rightExpr;
            cout << "   movl    %eax, " << address << "(%rbp) \n";
        } else {
            cout << "   movl    %edx, " << address << "(%rbp) \n";
            //result = leftExpr % rightExpr;
        }
    }

    return address;
}

antlrcpp::Any Visitor::visitAdditiveexpr(ifccParser::AdditiveexprContext *context) {
    int exprLeft = visit(context->expression()[0]);
    int exprRight = visit(context->expression()[1]);

    //opti : check if one expr is equal to 0

    //TODO create temp var 
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    if (context->op->getText() == "+") {
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   addl " << exprRight << "(%rbp), %eax\n";
    } else {
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   subl " << exprRight << "(%rbp), %eax\n";
    }

    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitBitsexpr(ifccParser::BitsexprContext *context) {
    int exprLeft = visit(context->expression(0));
    int exprRight = visit(context->expression(1));

    //TODO: new tmp
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    if (context->op->getText() == "|") {
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   orl " << exprRight << "(%rbp), %eax\n";
    } else if (context->op->getText() == "&") {
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   andl " << exprRight << "(%rbp), %eax\n";
    } else {
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   xorl " << exprRight << "(%rbp), %eax\n";
    }

    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitConstexpr(ifccParser::ConstexprContext *context) {
    int value = stoi(context->CONST()->getText());
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);
    cout << "   movl	$" << value << ", " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitEqualityexpr(ifccParser::EqualityexprContext *context) {
    int exprLeft = visit(context->expression(0));
    int exprRight = visit(context->expression(1));

    //TODO: new tmp
    int level = 0;
    string name = "!temp" + to_string(SymbolTable::staticTempIndex++);
    int address = this->symbolTable->addSymbol(name, level, INT, 0, ASSIGNED, 0);

    cout << "   movl " << exprLeft << "(%rbp), %eax\n";
    cout << "   cmpl " << exprRight << "(%rbp), %eax\n";
    if (context->op->getText() == "==") {
        cout << "   sete %al\n";
    } else {
        cout << "   setne %al\n";
    }

    cout << "   movzbl  %al, %eax\n";
    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitType(ifccParser::TypeContext *context) {
    return visitChildren(context);
}