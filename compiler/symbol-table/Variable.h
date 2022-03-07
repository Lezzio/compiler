#if ! defined ( VARIABLE_H )
#define VARIABLE_H

#include <string>
#include "Type.h"
#include "Scope.h"

class Variable 
{
public :

    Variable();
    virtual ~Variable();

protected :
    string name;    
    Type type;
    Scope scope;
    int declarationLine;
    int usageLine;
    int address;
};

#endif // VARIABLE_H