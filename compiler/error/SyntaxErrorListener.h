//
// Created by allan guigal on 14/03/2022.
//
#pragma once

#include <string>
#include "antlr4-runtime.h"

using namespace std;
using namespace antlr4;

class SyntaxErrorListener : public BaseErrorListener {

public:
    SyntaxErrorListener();
    void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                     const std::string &msg, std::exception_ptr e);

};