//
// Created by allan guigal on 14/03/2022.
//

#include "SyntaxErrorListener.h"
#include "ErrorManager.h"
#include "Error.h"

SyntaxErrorListener::SyntaxErrorListener() = default;

void SyntaxErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
const std::string &msg, std::exception_ptr e) {
    cout << "Syntax error" << endl;
    auto * error = new Error(msg, line);
    ErrorManager::getInstance()->addError(error);
}