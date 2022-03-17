#include "Visitor.h"
using namespace std;

Visitor::Visitor() : edx{"", false}, eax{"", false}
{
}

Visitor::~Visitor() {}

antlrcpp::Any Visitor::visitAxiom(ifccParser::AxiomContext *ctx)
{
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context)
{
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

antlrcpp::Any Visitor::visitBlock(ifccParser::BlockContext *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatements1(ifccParser::Statements1Context *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatements2(ifccParser::Statements2Context *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatement1(ifccParser::Statement1Context *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatement2(ifccParser::Statement2Context *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitStatement3(ifccParser::Statement3Context *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    return visitChildren(context);
}

/**
* Visit affection following the pattern type VAR '=' VAR
*/
antlrcpp::Any Visitor::visitAffectation1(ifccParser::Affectation1Context *context)
{
    // TODO:: affect in symbole table
    // declaration + affectation

    //type newVariableName = existingVariableName;
    string newVariableName = context->VAR()[0]->getText();
    string existingVariableName = context->VAR()[1]->getText();

    //Verify that existingVariableName exists in the symbol table and is ASSIGNED
    

    //Verify that newVariable does not exists in the symbol table and is not const


    // TODO:: getInfo first variable; save second and get address
    int addressCopy = 0;
    int address = 0;
    
    //SymbolTable.

    cout << "   movl	" << addressCopy << "(%rbp), %eax \n"
                                            "   movl     %eax, "
         << address << "(%rbp)\n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation2(ifccParser::Affectation2Context *context)
{
    // TODO:: affect in symbole table
    // declaration + affectation

    string newVariableName = context->VAR()->getText();
    int variableValue = stoi(context->CONST()->getText());

    // TODO:: recup l'address
    int address = 0;
    cout << "   movl	$" << variableValue << ", " << address << "(%rbp) \n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation3(ifccParser::Affectation3Context *context)
{
    // TODO:: affect in symbole table
    // affectation

    string variableName = context->VAR()[0]->getText();
    string copyVariableName = context->VAR()[1]->getText();

    // TODO:: getInfo first variable; save second and get address
    int addressCopy = 0;
    int address = 0;

    cout << "   movl	" << addressCopy << "(%rbp), %eax \n"
                                            "   movl     %eax, "
         << address << "(%rbp)\n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation4(ifccParser::Affectation4Context *context)
{
    // TODO:: affect in symbole table
    // affectation

    string variableName = context->VAR()->getText();
    // TODO:: get variable in symbole table
    int newVariableValue = stoi(context->CONST()->getText());
    // TODO:: get address variable
    int address = 0;

    cout << "   movl	$" << newVariableValue << ", " << address << "(%rbp) \n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation5(ifccParser::Affectation5Context *context)
{
    // TODO:: affect in symbole table
    // declaration + affectation
    string newVariableName = context->VAR()->getText();
    int last_tmp = visitChildren(context);
    cout << "   movl	" << last_tmp << "(%rbp), %eax\n";
        // TODO:: get address variable
    
    int address = 0;
    cout << "   movl	%eax," << address << "(%rbp) \n";

    return 0;

}

antlrcpp::Any Visitor::visitAffectation6(ifccParser::Affectation6Context *context)
{
     // TODO:: affect in symbole table
    // affectation
    string newVariableName = context->VAR()->getText();

    int last_tmp = visitChildren(context);
    cout << "   movl	" << last_tmp << "(%rbp), %eax\n";
        // TODO:: get address variable
    int address = 0;
    cout << "   movl	%eax," << address << "(%rbp) \n";

    return 0;
}

antlrcpp::Any Visitor::visitRet1(ifccParser::Ret1Context *context)
{
    int retval = stoi(context->CONST()->getText());
    cout << " 	movl	$" << retval << ", %eax\n"
                                        "   popq %rbp #restore %rbp from the stack\n"
                                        " 	ret\n";

    return 0;
}

antlrcpp::Any Visitor::visitRet2(ifccParser::Ret2Context *context)
{
    int address = 0; // TODO:: get variable address in symbol
    cout << "   movl	" << address << "(%rbp), %eax\n"
                                        "   popq %rbp\n"
                                        "   ret\n";
    return 0;
}

antlrcpp::Any Visitor::visitMultvariables(ifccParser::MultvariablesContext *context)
{
    //TODO : symbol table 
    string newVariableName = context->VAR()->getText();

    return visit(context->variables());
}

antlrcpp::Any Visitor::visitVariable(ifccParser::VariableContext *context)
{
     //TODO : symbol table 
    string newVariableName = context->VAR()->getText();

    return 0;
}

antlrcpp::Any Visitor::visitUnaryexpr(ifccParser::UnaryexprContext *context)
{
    int expr =visit(context->expression());

    //TODO create temp var 
    int address = 0;

    cout << "   movl " << expr << "(%rbp), %eax\n";
    if(context->op->getText() == "-"){
       cout << "   negl %eax\n";
    } else {
       cout << "   notl %eax\n";
    }

    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitCharexpr(ifccParser::CharexprContext *context)
{
    string variable = context->CHARACTER()->getText();
    char character = variable.substr(1,2)[0];
    int value = (int) character;
    
    //TODO: get address
    int address = 0;

    cout << "   movl	$" << value << ", " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitRelationalexpr(ifccParser::RelationalexprContext *context)
{
    int exprLeft = visit(context->expression(0));
    int exprRight = visit(context->expression(1));
    
    //opti : check if one expr is equal to 1
    int address = 0;

    cout << "   movl " << exprLeft << "(%rbp), %eax\n";
    cout << "   cmpl " << exprRight << "(%rbp), %eax\n";

    if (context->op->getText() == ">"){
        cout << "   setg    %al\n";

    } else if(context->op->getText() == ">="){
        cout << "   setge   %al\n";
    
    }else if(context->op->getText() == "<"){
        cout << "   setl    %al\n";
    
    }else {     //if(context->op->getText() == "<=")
        cout << "   setle   %al\n";
    
    }
    cout << "   movzbl  %al, %eax\n";
    cout << "   movl    %eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitBracketexpr(ifccParser::BracketexprContext *context)
{
    return visitChildren(context);
}

antlrcpp::Any Visitor::visitVarexpr(ifccParser::VarexprContext *context)
{
    string variable = context->VAR()->getText();
    //TODO: check existence and get adress

    int address = 0;
    return address;
}

antlrcpp::Any Visitor::visitMultplicationexpr(ifccParser::MultplicationexprContext *context)
{

    int exprLeft = visit(context->expression()[0]);
    int exprRight = visit(context->expression()[1]);
    
    //opti : check if one expr is equal to 1
    int address = 0;
    
    cout << "   movl " << exprLeft << "(%rbp), %eax\n";
    if(context->op->getText() == "*"){
        cout << "   imul " << exprRight << "(%rbp), %eax\n";
        cout << "   movl    %eax, " << address << "(%rbp) \n";
        //result = leftExpr * rightExpr;
    }else {
        cout << "   idivl " << exprRight << "(%rbp), %eax\n";
        if (context->op->getText() == "/"){
            //result = leftExpr / rightExpr;
            cout << "   movl    %eax, " << address << "(%rbp) \n";
        }else{
            cout << "   movl    %edx, " << address << "(%rbp) \n";
            //result = leftExpr % rightExpr;
        }   
    }
     
     return address;
}

antlrcpp::Any Visitor::visitAdditiveexpr(ifccParser::AdditiveexprContext *context)
{
    int exprLeft =visit(context->expression()[0]);
    int exprRight =visit(context->expression()[1]);

    //opti : check if one expr is equal to 0

    //TODO create temp var 
    int address = 0;

    if(context->op->getText() == "+"){
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   addl " << exprRight << "(%rbp), %eax\n";
    } else {
       cout << "   movl " << exprLeft << "(%rbp), %eax\n";
       cout << "   subl " << exprRight << "(%rbp), %eax\n";
    }

    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitBitsexpr(ifccParser::BitsexprContext *context){
    int exprLeft = visit(context->expression(0));
    int exprRight = visit(context->expression(1));

    //TODO: new tmp
    int address = 0;

    if(context->op->getText() == "|"){
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   orl " << exprRight << "(%rbp), %eax\n";
    }else if (context->op->getText() == "&"){
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   andl " << exprRight << "(%rbp), %eax\n";
    }else{
        cout << "   movl " << exprLeft << "(%rbp), %eax\n";
        cout << "   xorl " << exprRight << "(%rbp), %eax\n";
    }

    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitConstexpr(ifccParser::ConstexprContext *context)
{
    int value = stoi(context->CONST()->getText());
    //TODO create temp var 
    int address = 0;

    cout << "   movl	$" << value << ", " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitEqualityexpr(ifccParser::EqualityexprContext *context)
{
    int exprLeft = visit(context->expression(0));
    int exprRight = visit(context->expression(1));

     //TODO: new tmp
    int address = 0;

    cout << "   movl " << exprLeft << "(%rbp), %eax\n";
    cout << "   cmpl " << exprRight << "(%rbp), %eax\n";
    if(context->op->getText() == "=="){
       cout << "   sete %al\n";
    } else {
       cout << "   setne %al\n";
    }

    cout << "   movzbl  %al, %eax\n";
    cout << "   movl	%eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitType(ifccParser::TypeContext *context)
{
    return visitChildren(context);
}
