#include "CodeGenVisitor.h"
#include <string>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
	int retval = std::stoi(ctx->CONST()->getText());
	std::cout<<".globl	_main\n"
		" _main: \n"
		"   pushq %rbp #save %rbp on the stack\n"
		"   movq %rsp, %rbp #define %rbp for the current function\n"
		" 	movl	$"<<retval<<", %eax\n"
		"   popq %rbp #restore %rbp from the stack\n"
		" 	ret\n";

	return 0;
}