#include "Visitor.h"
using namespace std;

Visitor::Visitor() :
    edx {"", false}, eax{"", false}
{
}

antlrcpp::Any Visitor::visitAxiom(ifccParser::AxiomContext *ctx)
{ 
    return visitChildren(ctx);
} 

antlrcpp::Any Visitor::visitProg(ifccParser::ProgContext *context)
{
    cout << ".globl main\n"
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
    //TODO :: declare variable in symbole table
    string newVariableName = context->VAR()->getText();
    
}

antlrcpp::Any Visitor::visitAffectation1(ifccParser::Affectation1Context *context)
{
    //TODO :: affect in symbole table
    //declaration + affectation 
    

}

antlrcpp::Any Visitor::visitAffectation2(ifccParser::Affectation2Context *context)
{
    //TODO :: affect in symbole table
    //declaration + affectation

    string newVariableName = context->VAR()->getText();
    int variableValue = stoi(context->CONST()->getText());

    //TODO :: recup l'address
    int address = 0;
    cout << "   movl	$"<<variableValue<<", "<<address<<"(%rbp) \n";

    
}

antlrcpp::Any Visitor::visitAffectation3(ifccParser::Affectation3Context *context)
{
    //TODO :: affect in symbole table
}

antlrcpp::Any Visitor::visitAffectation4(ifccParser::Affectation4Context *context)
{
    //TODO :: affect in symbole table
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
    int address = 0; //TODO :: get variable address in symbol
    cout << " 	movl	"<<address<<"(%rbp), %eax\n"
	    "   popq %rbp #restore %rbp from the stack\n"
		" 	ret\n";
    return 0;
}

antlrcpp::Any Visitor::visitType(ifccParser::TypeContext *context)
{

}