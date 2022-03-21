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
    bool doesSymbolExist(string identn, int level);
    Symbol * returnSymbol(string name, int level);
    int addSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst);
    int getAddressSymbol(string name, int level);
    void print_dictionary();

    static int staticIndex;

protected :
    map<string, Symbol *> table;
};

#endif // SYMBOLTABLE_H