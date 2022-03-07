#if ! defined ( SYMBOLTABLE_H )
#define SYMBOLTABLE_H

#include <map>
#include <string>
using namespace std;

const string Type[] = { "INTEGER", "ARGUMENT", "FONCTION", "VARIABLE", "TABLEAU" };

struct SYMBOL {
    string name;
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
    bool addSymbol(string symbolName, int levelSymbol, int type, int address, int additional);
    void print_dictionary();

protected :
    map<string, SYMBOL> table;

};

#endif // SYMBOLTABLE_H