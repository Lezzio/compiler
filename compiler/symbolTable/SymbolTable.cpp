#include "SymbolTable.h"
#include <iostream>
#include <string>

#define DECLARATION_INDEX 1

using namespace std;

int SymbolTable::staticIndex = 0;
int SymbolTable::staticTempIndex = 0;

Scope GLOBAL_SCOPE = Scope("GLOBAL");

SymbolTable::SymbolTable() {
    current_function = "";
    highestIndex = 0;
}

int SymbolTable::addSymbol(const string &symbolName, Scope * symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst) {
    int index = staticIndex + getOffsetType(typeSymbol);
    auto *newSymbol = new Symbol(symbolName, symbolScope, index, typeSymbol, additional, state, isConst);
    if (!doesSymbolExist(newSymbol)) {
        this->symbolTable[newSymbol->getName()][symbolScope->getCurrentLevel()] = newSymbol;
        staticIndex = index;
        highestIndex = index;
        return newSymbol->getAddress();
    } else {
        cout << "Error detected can't declare symbol twice ADD_SYMBOL" << endl;
    }
    delete newSymbol;
    return -1;
}

bool SymbolTable::declareSymbol(const string &symbolName, Scope *symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {

    auto *newSymbol = new Symbol(symbolName, symbolScope, DECLARATION_INDEX, typeSymbol, additional, stateSymbol, isConst);

    if (!doesSymbolExist(newSymbol)) {
        this->symbolTable[newSymbol->getName()][symbolScope->getCurrentLevel()] = newSymbol;
        //print_dictionary();
        return true;
    } else {
        //Error, can't declare a symbol twice
        //ErrorManager::getInstance()->addError(new Error());
        cout << "Error detected can't declare symbol twice DECLARE_SYMBOL" << endl;
    }
    delete newSymbol;
    return false;
}

int SymbolTable::assignSymbol(Symbol *symbol) {
    symbol->setStateSymbol(ASSIGNED);
    staticIndex += getOffsetType(symbol->getTypeSymbol());
    highestIndex = staticIndex;
    symbol->setIndex(staticIndex);
    return symbol->getAddress();
}

int SymbolTable::defFunction(const string& name, TypeSymbol typeSymbol) {
    auto *newSymbol = new Symbol(name, &GLOBAL_SCOPE, DECLARATION_INDEX, typeSymbol, 0, FUNCTION, false);
    if (!doesSymbolExist(newSymbol)) {
        this->symbolTable[newSymbol->getName()][GLOBAL_SCOPE.getCurrentLevel()] = newSymbol;
        return 0;
    }
    delete newSymbol;
    return -1;
}

bool SymbolTable::defParameter(const string& name, Scope *scope, TypeSymbol typeSymbol) {
    auto *newSymbol = new Symbol(name, scope, DECLARATION_INDEX, typeSymbol, 0, PARAMETER, false);
    if (!doesSymbolExist(newSymbol)) {
        this->symbolTable[newSymbol->getName()][GLOBAL_SCOPE.getCurrentLevel()] = newSymbol;
        return true;
    }
    delete newSymbol;
    return false;
}


void SymbolTable::print_dictionary() {
    cout << endl << "***   Actual Symbol Table   ***" << endl;
    cout
            << "-------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "|   Index   ;    Name   ;   Scope name   ;   Scope context   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | " << endl;
    cout
            << "-------------------------------------------------------------------------------------------------------------"
            << endl;

    for (const auto& firstPair : symbolTable) {
        for (const auto secondPair: firstPair.second) {
            std::stringstream context;
            auto levelContext = secondPair.second->getScope()->levelContext;
            std::copy(levelContext.begin(), levelContext.end(), std::ostream_iterator<int>(context, " "));

            cout << "|  " << secondPair.second->getIndex() << "  ;  " << secondPair.second->getName() << "  ;  "
                 << secondPair.second->getScope()->name << "  ;  " << "-" << context.str()
                 << to_string(secondPair.second->getTypeSymbol()) << "  ;  "
                 << to_string(secondPair.second->getAdditional()) << "  ;  " << to_string(secondPair.second->getStateSymbol())
                 << "  ;  " << to_string(secondPair.second->getIsConst()) << "  | " << endl;
        }
    }

    cout
            << "------------------------------------------------------------------------------------------------------------"
            << endl;
}

/**
 * @brief
 *
 * @param ident
 * @return true if symbol exists in the symbolTable
 * @return false else
 */
bool SymbolTable::doesSymbolExist(Symbol *symbol) {
    return doesSymbolExist(symbol->getName(), symbol->getScope());
}

/**
 * @brief
 *
 * @param name
 * @return true if symbol exists in the symbolTable
 * @return false else
 */
bool SymbolTable::doesSymbolExist(const string& name, Scope *scope) {
    return lookupSymbol(name, scope) != nullptr;
}

int SymbolTable::getOffsetType(TypeSymbol typeSymbol) {
    switch (typeSymbol) {
        case INT:
            return 4;
        case INT8_T:
        case CHAR :
            return 1;
        default:
            cerr << "Error" << endl;
            exit(1);
    }
}

/**
 * @brief 
 *  Finds the symbol from the identificator functionName if existing.
 *  Returns nullptr else.
 *
 * @param name 
 * @return SYMBOL 
 */
Symbol *SymbolTable::lookupSymbol(const string& name, Scope *scope) {
    print_dictionary();
    auto matchedMap = symbolTable.find(name);
    if (matchedMap != symbolTable.end()) {
        auto levelContext = scope->levelContext;
        for (auto it = levelContext.rbegin(); it != levelContext.rend(); ++it) {
            int level = *it;
            auto symbol = matchedMap->second.find(level);
            return symbol->second;
        }
    }
    cout << "lookupSymbol # THE SYMBOL IS NULL" << endl;
    return nullptr;
}

Symbol *SymbolTable::lookupParameter(const string& name, Scope *scope) {
    return lookupSymbol(name, scope);
}

SymbolTable::~SymbolTable() {
    for (const auto& firstPair : symbolTable) {
        for (const auto secondPair: firstPair.second) {
            delete secondPair.second;
        }
    }
}