#if !defined ( SYMBOL_H )
#define SYMBOL_H

#include "typeSymbol.h"
#include "stateSymbol.h"
#include <string>

using namespace std;

class Symbol {
public:
    Symbol();

    Symbol(string name, int level, int index, TypeSymbol typeSymbol, int additional,
           StateSymbol stateSymbol, bool isConst);

    ~Symbol();

    void setLevel(int l);

    void setName(string name);

    void setTypeSymbol(TypeSymbol typeSymbol);

    void setAdditional(int additional);

    void setStateSymbol(StateSymbol stateSymbol);

    int getLevel() const;

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

protected:
    string name;
    int level;
    int index;
    const string scope = "LOCAL";
    TypeSymbol typeSymbol;
    int additional;
    StateSymbol stateSymbol;
    bool isConst;
};

#endif // SYMBOL_H  