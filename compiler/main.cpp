#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

//#include "CodeGenVisitor.h"
#include "AstVisitor.h"
#include "symbolTable/SymbolTable.h"
#include "intermediateRepresentation/IR.h"
#include "ast/ast.h"
#include "error/SyntaxErrorListener.h"
#include "error/ErrorStrategy.h"
#include "BailErrorStrategy.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv) {

    bool arm = false;
    string outputFile;

    stringstream in;
    if (argn == 2) {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
    } else if (argn == 3) {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
        auto arg2 = string(argv[2]);
        if (arg2 == "-ARM") {
            arm = true;
        } else if (arg2.back() == 's') {
            outputFile = arg2;
        } else {
            cerr << "Option " << argv[2] << " unknown : try -ARM instead " << endl;
        }
    } else if (argn == 4) {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
        auto arg2 = string(argv[2]);
        auto arg3 = string(argv[3]);
        if (arg2.back() == 's' && arg3 == "-ARM") {
            outputFile = arg2;
            arm = true;
        } else {
            cerr << "Option " << argv[2] << " unknown : try -ARM instead " << endl;
        }
    } else {
        cerr << "usage: ifcc path/to/file.c [path/to/file.s] [-ARM]" << endl;
        exit(1);
    }

    ANTLRInputStream input(in.str());
    
    ifccLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    auto * syntaxErrorListener = new SyntaxErrorListener();
    ifccParser parser(&tokens);
   // Ref<ANTLRErrorStrategy> errorStrategyRef = make_shared<ErrorStrategy>();
   // parser.setErrorHandler(errorStrategyRef);
    parser.addErrorListener(syntaxErrorListener);
    tree::ParseTree *tree = parser.axiom();
    if (parser.getNumberOfSyntaxErrors() != 0) {
        cerr << "error: syntax error during parsing" << endl;
        exit(1);
    }
    if (lexer.getNumberOfSyntaxErrors() != 0) {
        exit(1);
    }

    AstVisitor v;

    Prog * prog = v.visit(tree);
    vector<CFG *> cfgs;
    cfgs = prog->linearize();

    ofstream srcFile(outputFile);

    for (CFG *cfg : cfgs) {
        if (arm) {  //ARM
            cfg->gen_asm_ARM(srcFile);
        } else {    //x86
            cfg->gen_asm_x86(srcFile);
        }
    }
    prog->symbolTable->warnUnusedSymbols();

    delete (syntaxErrorListener);
    delete (prog);
    return 0;
}
