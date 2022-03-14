#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

//#include "CodeGenVisitor.h"
#include "Visitor.h"
#include "symbol-table/SymbolTable.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
  //TODO:: arg to disable warnings
  stringstream in;
  if (argn==2)
  {
     ifstream lecture(argv[1]);
     in << lecture.rdbuf();
  }
  else
  {
      cerr << "usage: ifcc path/to/file.c" << endl ;
      exit(1);
  }
  
  ANTLRInputStream input(in.str());

  ifccLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();

  ifccParser parser(&tokens);
  tree::ParseTree* tree = parser.axiom();

  if(parser.getNumberOfSyntaxErrors() != 0)
  {
      cerr << "error: syntax error during parsing" << endl;
      exit(1);
  }

<<<<<<< HEAD
  //SymbolTable * symbolTable = new SymbolTable();
  //CodeGenVisitor visitor;
  Visitor * visitor = new Visitor();
  visitor->visit(tree);

=======
  SymbolTable * symbolTable = new SymbolTable();
  //CodeGenVisitor v;
  Visitor v;
  v.visit(tree);
  delete symbolTable;
>>>>>>> 17dd292dde7ae8385224e75f584962af7ce0d398
  return 0;
}