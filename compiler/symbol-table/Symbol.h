#if ! defined ( SYMBOL_H )
#define SYMBOL_H

#include <string>
using namespace std;

class Symbol{
    public:
        Symbol();
        Symbol(int index, string name, int type, int address, int additionnal);
        ~Symbol();
        
        void setName(string name);
        void setScope(string scope);
        void setType(int type);
        void setAddress(int address);
        void setAdditional(int additional);

        int getIndex();
        string getName();
        string getScope();
        string getType();
        int getAddress();
        int getAdditional();
    
    protected:
        int index;
        string name;
        const string scope = "LOCAL";
        string type;
        int address;
        int additional;
};

#endif // SYMBOL_H  