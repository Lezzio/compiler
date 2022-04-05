//
// Created by allan guigal on 28/03/2022.
//

#ifndef COMPILER_ERRORMANAGER_H
#define COMPILER_ERRORMANAGER_H

#include "Error.h"
#include <vector>
#include <iostream>

using namespace std;

class ErrorManager {

public:
    ErrorManager();
    static ErrorManager * getInstance();
    void addError(Error * error);

private:
    static ErrorManager * INSTANCE;
    vector<Error *> errors;

};


#endif //COMPILER_ERRORMANAGER_H