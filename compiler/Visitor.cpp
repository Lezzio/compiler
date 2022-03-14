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

antlrcpp::Any Visitor::visitAffectation1(ifccParser::Affectation1Context *context)
{
    // TODO:: affect in symbole table
    // declaration + affectation
    string newVariableName = context->VAR()[0]->getText();
    string existingVariableName = context->VAR()[1]->getText();



    // TODO:: getInfo first variable; save second and get address
    int addressCopy = 0;
    int address = 0;

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
    string last_tmp = visitChildren(context).as<string>();
    
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

    string last_tmp = visitChildren(context).as<string>();
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
}

antlrcpp::Any Visitor::visitCharexpr(ifccParser::CharexprContext *context)
{
}

antlrcpp::Any Visitor::visitRelationalexpr(ifccParser::RelationalexprContext *context)
{
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
    if(eax.used){
        edx.used = true;
        edx.name = address;
        cout << "   movl	" << address << "(%rbp), %edx\n";
        return string("%edx");

    } else {
        eax.used = true;
        eax.name = address;
        cout << "   movl	" << address << "(%rbp), %eax\n";
        return string("%eax");

    }
}

antlrcpp::Any Visitor::visitMultplicationexpr(ifccParser::MultplicationexprContext *context)
{
}

antlrcpp::Any Visitor::visitAdditiveexpr(ifccParser::AdditiveexprContext *context)
{

    string exprLeft =visit(context->expression()[0]).as<string>();
    string exprRight =visit(context->expression()[1]).as<string>();

    if(!eax.used){
        //TODO: à voir avec le prof
    }

    //TODO create temp var 
    string address = "0";

    if(context->op->getText() == "+"){
        if(edx.used){
            cout << "   addl   $edx, $eax";
        } else {
            cout << "   addl   " << address << "(%rbp), %eax\n";
        }
    } else {
        if(edx.used){
            cout << "   addl   $edx, $eax";
        } else {
            cout << "   subl   " << address << "(%rbp), %eax\n";
        }
    }

    cout << "   movl	$eax, " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitBitsexpr(ifccParser::BitsexprContext *context)
{
}

antlrcpp::Any Visitor::visitConstexpr(ifccParser::ConstexprContext *context)
{
    int value = stoi(context->CONST()->getText());
    //TODO create temp var 
    string address = "0";

    cout << "   movl	$" << value << ", " << address << "(%rbp) \n";

    return address;
}

antlrcpp::Any Visitor::visitEqualityexpr(ifccParser::EqualityexprContext *context)
{

}

antlrcpp::Any Visitor::visitType(ifccParser::TypeContext *context)
{
    return visitChildren(context);
}
