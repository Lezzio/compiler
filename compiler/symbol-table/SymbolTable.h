#if ! defined ( SYMBOLTABLE_H )
#define SYMBOLTABLE_H

#include <map>
#include "string"
using namespace std;



struct SYMBOL {
    const string scope = "LOCAL";
    string type;
    int address;
    int additional;
} symbol;

class SymbolTable 
{
public :

    //lookup 
    //insert
    
    SymbolTable();
    virtual ~SymbolTable();
    bool doesSymbolExist(string ident);
    SYMBOL returnSymbol(string name);
    bool addSymbol(string type, int address, int additional);

protected :
    map<string, SYMBOL> table;

};

#endif // SYMBOLTABLE_H