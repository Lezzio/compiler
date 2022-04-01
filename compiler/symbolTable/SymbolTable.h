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
    bool doesSymbolExist(Symbol * symbol);
    bool doesSymbolExist(string code);
    bool doesSymbolExist(string identn, int level);
    Symbol * returnSymbol(string name, int level);
    Symbol * returnParameter(string name, int level);
    /**
     * Add a symbol to the table
     * @return the address or -1 if the symbol couldn't be added (e.g already exists)
     */
    int addSymbol(const string& symbolName, const string& symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst);
    /**
     * Declare a new symbol in the table
     * @return true or false whether the symbol already existed or not
     */
    bool declareSymbol(const string& symbolName, const string& symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst);
    int assignSymbol(Symbol * symbol);
    int getAddressSymbol(string name, int level);
    int getOffsetType(TypeSymbol typeSymbol);
    void print_dictionary();
    int defFunction(string name, TypeSymbol typeSymbol);
    bool defParameter(const string& name, string scope, TypeSymbol typeSymbol);

    string current_function;
    static int staticIndex;
    //TODO: reset when change function
    int highestIndex;
    static int staticTempIndex;

protected :
    map<string, Symbol *> table;
};

#endif // SYMBOLTABLE_H