#if ! defined ( SYMBOL_H )
#define SYMBOL_H

#include "typeSymbol.h"
#include "stateSymbol.h"
#include <string>
using namespace std;

class Symbol{
    public:
        Symbol();
        Symbol(int index,int level, string name, TypeSymbol typeSymbol, int additionnal, StateSymbol stateSymbol, bool isConst);
        ~Symbol();
        
        void setIndex(int index);
        void setName(string name);
        void setScope(string scope);
        void setTypeSymbol(TypeSymbol typeSymbol);
        void setAdditional(int additional);
        void setStateSymbol(StateSymbol stateSymbol);

        int getIndex();
        string getName();
        string getScope();
        TypeSymbol getTypeSymbol();
        int getAdditional();
        StateSymbol getStateSymbol();
        bool getIsConst();
        int getAddress();
        string getCode();
    
    protected:
        int index;
        int level;
        string name;
        const string scope = "LOCAL";
        TypeSymbol typeSymbol;
        int additional;
        StateSymbol stateSymbol;
        bool isConst;
};

#endif // SYMBOL_H  