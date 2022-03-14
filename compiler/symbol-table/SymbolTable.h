#if ! defined ( SYMBOLTABLE_H )
#define SYMBOLTABLE_H

#include <map>
#include "Symbol.h"
using namespace std;

class SymbolTable 
{
public :

    //lookup 
    //insert
    
    SymbolTable(){ index = 0;};
    ~SymbolTable();
    bool doesSymbolExist(string ident);
    Symbol * returnSymbol(string name);
    bool addSymbol(string symbolName, int levelSymbol, int type, int address, int additional);
    void print_dictionary();

    static int index;

protected :
    map<string, Symbol *> table;
};

#endif // SYMBOLTABLE_H