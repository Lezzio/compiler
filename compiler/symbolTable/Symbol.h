#if !defined ( SYMBOL_H )
#define SYMBOL_H

#include "typeSymbol.h"
#include "stateSymbol.h"
#include <string>
#include "Scope.h"

using namespace std;

class Symbol {
public:
    Symbol();

    Symbol(string name, Scope *scope, int index, TypeSymbol typeSymbol, int additional,
           StateSymbol stateSymbol, bool isConst);

    ~Symbol();

    void setName(string name);

    void setTypeSymbol(TypeSymbol typeSymbol);

    void setAdditional(int additional);

    void setStateSymbol(StateSymbol stateSymbol);

    string getName();

    Scope *getScope();

    TypeSymbol getTypeSymbol();

    int getAdditional() const;

    StateSymbol getStateSymbol();

    bool getIsConst() const;

    int getAddress() const;

    int getIndex() const;

    void setIndex(int index);

    void setParameters(const vector<TypeSymbol> &parameters, int number);
    
    int getNumberParameters() const;

    TypeSymbol getParameterType(int position) const;

protected:
    string name;
    int index{};
    Scope *scope;
    TypeSymbol typeSymbol;
    int additional{};
    StateSymbol stateSymbol;
    bool isConst{};

    vector<TypeSymbol> parameters;
    int number;
};

#endif // SYMBOL_H  