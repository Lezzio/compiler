#if !defined ( SYMBOL_H )
#define SYMBOL_H

#include "typeSymbol.h"
#include "stateSymbol.h"
#include <string>

using namespace std;

class Symbol {
public:
    Symbol();

    Symbol(string name, string scope, int index, TypeSymbol typeSymbol, int additional,
           StateSymbol stateSymbol, bool isConst);

    ~Symbol();

    void setName(string name);

    void setTypeSymbol(TypeSymbol typeSymbol);

    void setAdditional(int additional);

    void setStateSymbol(StateSymbol stateSymbol);

    string getName();

    string getScope();

    TypeSymbol getTypeSymbol();

    int getAdditional() const;

    StateSymbol getStateSymbol();

    bool getIsConst() const;

    int getAddress() const;

    string getCode();

    int getIndex() const;

    void setIndex(int index);

    static string getAssociatedCode(const string& name, const string& scope);

protected:
    string name;
    int index{};
    string scope;
    TypeSymbol typeSymbol;
    int additional{};
    StateSymbol stateSymbol;
    bool isConst{};
};

#endif // SYMBOL_H  