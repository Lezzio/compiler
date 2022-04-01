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
    //TODO:: arg to disable warnings

    bool arm = false;

    stringstream in;
    if (argn == 2) {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
    } else if (argn == 3) {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
        if (string(argv[2]) == "-ARM"){
            arm = true;
        } else {
            cerr << "Option " << argv[2] << " unknown : try -ARM instead " << endl;
        }
    } else {
        cerr << "usage: ifcc path/to/file.c [-ARM]" << endl;
        exit(1);
    }

    ANTLRInputStream input(in.str());
    
    ifccLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    auto * syntaxErrorListener =  new SyntaxErrorListener();
    ifccParser parser(&tokens);
   // Ref<ANTLRErrorStrategy> errorStrategyRef = make_shared<ErrorStrategy>();
   // parser.setErrorHandler(errorStrategyRef);
   // parser.addErrorListener(syntaxErrorListener);
    tree::ParseTree *tree = parser.axiom();
    if (parser.getNumberOfSyntaxErrors() != 0) {
        cerr << "error: syntax error during parsing" << endl;
        exit(1);
    }
    if(lexer.getNumberOfSyntaxErrors() != 0){
        exit(1);
    }

    /*SymbolTable *symbolTable = new SymbolTable();
    ErrorManager *errorManager = new ErrorManager();
    //CodeGenVisitor v;
    Visitor *visitor = new Visitor(symbolTable, errorManager);
    visitor->visit(tree);
    //symbolTable->print_dictionary();
    delete symbolTable;

    cout << endl;
    cout << endl;*/

    AstVisitor v;

    Prog * prog = v.visit(tree);
    vector<CFG *> cfgs;
    cfgs = prog->linearize();


    //TODO : get from ifcc options
    for(CFG * cfg : cfgs){
        if (arm){   //ARM
            cfg->gen_asm_ARM(cout);
        } else {    //x86
            cfg->gen_asm_x86(cout);
        }

    }
    delete (syntaxErrorListener);
    delete (prog);
    return 0;
}
