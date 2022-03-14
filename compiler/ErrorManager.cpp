//
// Created by allan guigal on 14/03/2022.
//

#include "ErrorManager.h"

void ErrorManager::throwSemanticError(antlr4::Token *symbol, int message) {
    cout << "Syntax error at " + symbol->getLine() + " " + message;
}