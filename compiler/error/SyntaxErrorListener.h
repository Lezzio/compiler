//
// Created by allan guigal on 14/03/2022.
//

#ifndef COMPILER_ERRORMANAGER_H
#define COMPILER_ERRORMANAGER_H

#include <string>
#include "antlr4-runtime.h"

using namespace std;
using namespace antlr4;

class SyntaxErrorListener : public BaseErrorListener {

public:
    void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                     const std::string &msg, std::exception_ptr e);

};

#endif //COMPILER_ERRORMANAGER_H