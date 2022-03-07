#if ! defined ( SYMBOL_H )
#define SYMBOL_H

#include <string>
using namespace std;
        const string Type[] = { "INTEGER", "ARGUMENT", "FONCTION", "VARIABLE", "TABLEAU" };


class Symbol{
    public:
        Symbol(string name, string type, int address, int additionnal);
        ~Symbol();
        
        void setName(string name);
        void setScope(string scope);
        void setType(int type);
        void setAddress(int address);
        void setAdditional(int additional);

        string getName();
        string getScope();
        string getType();
        int getAddress();
        int getAdditional();
    
    protected:
        string name;
        const string scope = "LOCAL";
        string type;
        int address;
        int additional;
};

#endif // SYMBOL_H  