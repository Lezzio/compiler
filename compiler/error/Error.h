//
// Created by allan guigal on 28/03/2022.
//

#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H

#include <string>

using namespace std;

class Error {

public:
    Error(string message, unsigned long line);
    string message;
    unsigned long line;

};


#endif //COMPILER_ERROR_H
