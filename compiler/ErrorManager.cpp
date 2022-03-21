//
// Created by allan guigal on 14/03/2022.
//

#include "ErrorManager.h"

void ErrorManager::throwSemanticError(Token* symbol, string message) {
    cout << "Syntax error at " << symbol->getLine() << " " << message;
}