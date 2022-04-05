//
// Created by allan guigal on 05/04/2022.
//

#ifndef COMPILER_WARNING_H
#define COMPILER_WARNING_H

#include <string>

using namespace std;

class Warning {

public:
    Warning(string message, unsigned long line);
    string message;
    unsigned long line;

};


#endif //COMPILER_WARNING_H
