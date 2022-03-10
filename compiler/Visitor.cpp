#include "Visitor.h"
using namespace std;

Visitor::Visitor() :
    edx {"", false}, eax{"", false}
{
}

Visitor::~Visitor() {}

antlrcpp::Any Visitor::visitAxiom(ifccParser::AxiomContext *ctx)
{ 
    return visitChildren(ctx);
} 

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context)
{
    cout << ".text\n"
            ".globl main\n"
            " main: \n"
            "   pushq %rbp\n"
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
    string newVariableName = context->VAR()->getText();
    //TODO:: declare variable in symbole table

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation1(ifccParser::Affectation1Context *context)
{
    //TODO:: affect in symbole table
    //declaration + affectation 
    string newVariableName = context->VAR()[0]->getText();
    string existingVariableName = context->VAR()[1]->getText();
    
    //TODO:: getInfo first variable; save second and get address
    int addressCopy = 0;
    int address = 0;

    cout << "   movl	" << addressCopy <<"(%rbp), %eax \n"
            "   movl     %eax, " << address <<"(%rbp)\n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation2(ifccParser::Affectation2Context *context)
{
    //TODO:: affect in symbole table
    //declaration + affectation

    string newVariableName = context->VAR()->getText();
    int variableValue = stoi(context->CONST()->getText());

    //TODO:: recup l'address
    int address = 0;
    cout << "   movl	$"<< variableValue << ", " << address << "(%rbp) \n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitAffectation3(ifccParser::Affectation3Context *context)
{
    //TODO:: affect in symbole table
    //affectation 

    string variableName = context->VAR()[0]->getText();
    string copyVariableName =  context->VAR()[1]->getText();

    //TODO:: getInfo first variable; save second and get address
    int addressCopy = 0;
    int address = 0;

    cout << "   movl	"<<addressCopy<<"(%rbp), %eax \n"
            "   movl     %eax, "<<address<<"(%rbp)\n";

    return visitChildren(context);        

}

antlrcpp::Any Visitor::visitAffectation4(ifccParser::Affectation4Context *context)
{
    //TODO:: affect in symbole table
    //affectation

    string variableName = context->VAR()->getText();
    //TODO:: get variable in symbole table 
    int newVariableValue = stoi(context->CONST()->getText());
    //TODO:: get address variable 
    int address = 0;

    cout << "   movl	$"<<newVariableValue<<", "<<address<<"(%rbp) \n";

    return visitChildren(context);
}

antlrcpp::Any Visitor::visitRet1(ifccParser::Ret1Context *context)
{
    int retval = stoi(context->CONST()->getText());
    cout << " 	movl	$"<<retval<<", %eax\n"
		    "   popq %rbp #restore %rbp from the stack\n"
		    " 	ret\n";

    return 0;
}

antlrcpp::Any Visitor::visitRet2(ifccParser::Ret2Context *context)
{
    int address = 0; //TODO:: get variable address in symbol
    cout << "   movl	"<<address<<"(%rbp), %eax\n"
	        "   popq %rbp\n"
		    "   ret\n";
    return 0;
}

antlrcpp::Any Visitor::visitType(ifccParser::TypeContext *context)
{
    return visitChildren(context);
}