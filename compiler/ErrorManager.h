//
// Created by allan guigal on 14/03/2022.
//

#ifndef COMPILER_ERRORMANAGER_H
#define COMPILER_ERRORMANAGER_H

class ErrorManager {

public:
    void throwSemanticError(antlr4::Token* symbol, string message);

};

#endif //COMPILER_ERRORMANAGER_H