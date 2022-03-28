//
// Created by allan guigal on 14/03/2022.
//

#include "SyntaxErrorListener.h"

void SyntaxErrorListener::throwSemanticError(Token* symbol, string message) {
    cout << "Syntax error at " << symbol->getLine() << " " << message;
}

void SyntaxErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
const std::string &msg, std::exception_ptr e) {
    cout << "Syntax error" << endl
}