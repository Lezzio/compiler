#if ! defined ( SYMBOLTABLE_H )
#define SYMBOLTABLE_H

#include <map>
#include "Scope.h"
#include "Symbol.h"
using namespace std;

extern Scope GLOBAL_SCOPE;

class SymbolTable
{
public :

    //lookup 
    //insert
    
    SymbolTable();
    ~SymbolTable();
    bool doesSymbolExist(Symbol * symbol);
    bool doesSymbolExist(const string& name, Scope *scope);
    Symbol * lookupSymbol(const string& name, Scope *scope);
    Symbol * lookupParameter(const string& name, Scope *scope);
    /**
     * Add a symbol to the symbolTable
     * @return the address or -1 if the symbol couldn't be added (e.g already exists)
     */
    int addSymbol(const string& symbolName, Scope * symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst);
    /**
     * Declare a new symbol in the symbolTable
     * @return true or false whether the symbol already existed or not
     */
    bool declareSymbol(const string& symbolName, Scope *symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst);
    int assignSymbol(Symbol * symbol);
    static int getOffsetType(TypeSymbol typeSymbol);
    void print_dictionary();
    int defFunction(const string& name, TypeSymbol typeSymbol);
    bool defParameter(const string& name, Scope *scope, TypeSymbol typeSymbol);

    string current_function; //TODO Check usage, maybe not needed anymore
    static int staticIndex;
    //TODO: reset when change function
    int highestIndex;
    static int staticTempIndex;

protected :
    map<string, map<int, Symbol *>> symbolTable;
};

#endif // SYMBOLTABLE_H