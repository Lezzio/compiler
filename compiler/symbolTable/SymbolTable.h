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
    bool doesSymbolExist(Symbol *symbol);
    bool doesSymbolExist(string code);
     bool doesSymbolExist(string identn, int level);
    Symbol * returnSymbol(string name, int level);
    Symbol * returnParameter(string name, int level);
    int addSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst);
    int declareSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst);
    int assignSymbol(Symbol * symbol);
    int getAddressSymbol(string name, int level);
    int getOffsetType(TypeSymbol typeSymbol);
    int defFunction(string name, TypeSymbol typeSymbol);
    int defParameter(string name, TypeSymbol typeSymbol);

    void print_dictionary();

    string current_function; 
    static int staticIndex;
    //TODO: reset when change function
    int higherIndex;
    static int staticTempIndex;

protected :
    map<string, Symbol *> table;
};

#endif // SYMBOLTABLE_H