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
    
    SymbolTable();
    ~SymbolTable();
    bool doesSymbolExist(string ident);
    Symbol * returnSymbol(string name);
    bool addSymbol(string symbolName, int levelSymbol, int type, int additional);
    void print_dictionary();

    static int staticIndex;
    static int staticAddress;

protected :
    map<string, Symbol *> table;
};

#endif // SYMBOLTABLE_H