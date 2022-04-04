#include "SymbolTable.h"
#include <iostream>
#include <string>
#include <iterator>

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
    //cout << "ADD SYMBOL name = " << symbolName << " scope current level = " << symbolScope->getCurrentLevel() << endl; debug
    int index = staticIndex + getOffsetType(typeSymbol);
    if(additional != 0){
        index =staticIndex + additional;
    }
    auto *newSymbol = new Symbol(symbolName, symbolScope, index, typeSymbol, additional, state, isConst);
    if (!doesSymbolExist(newSymbol, true)) {
        this->symbolTable[newSymbol->getName()][symbolScope->getCurrentLevel()] = newSymbol;
        staticIndex = index;
        highestIndex = index;
        return newSymbol->getAddress();
    } else {
        //cout << "Error detected can't declare symbol twice ADD_SYMBOL" << endl; debug
    }
    delete newSymbol;
    return -1;
}

bool SymbolTable::declareSymbol(const string &symbolName, Scope *symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {
    //cout << "DECLARE SYMBOL name = " << symbolName << " scope current level = " << symbolScope->getCurrentLevel() << endl; debug
    auto *newSymbol = new Symbol(symbolName, symbolScope, DECLARATION_INDEX, typeSymbol, additional, stateSymbol, isConst);

    if (!doesSymbolExist(newSymbol, true)) {
        this->symbolTable[newSymbol->getName()][symbolScope->getCurrentLevel()] = newSymbol;
        return true;
    } else {
        //Error, can't declare a symbol twice
        //ErrorManager::getInstance()->addError(new Error());
        //cout << "Error detected can't declare symbol twice DECLARE_SYMBOL" << endl; debug
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
    //cout << "DEF FUNCTION name = " << name << " global scope level = " << GLOBAL_SCOPE.getCurrentLevel() << endl; debug
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
    if (!doesSymbolExist(newSymbol, true)) {
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
    cout << "|   Index   ;    Name   ;   Scope name   ;   Scope table level   ;   Scope current level   ;   Scope context   ;   Type   ;   Additional   ;    State    ;    IsConst   | " << endl;
    cout
            << "-------------------------------------------------------------------------------------------------------------"
            << endl;

    for (const auto& firstPair : symbolTable) {
        for (const auto secondPair: firstPair.second) {
            cout << "|  " << secondPair.second->getIndex() << "  ;  " << firstPair.first << "  ;  "
                 << secondPair.second->getScope()->name << "  ;  " << "TL=" << secondPair.first << "  ;  CL=" << secondPair.second->getScope()->getCurrentLevel()
                 << "  ;  Ctx=" << secondPair.second->getScope()->getLevelContextAsString() << "  ;  "
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
bool SymbolTable::doesSymbolExist(Symbol *symbol, bool scopedCurrent) {
    return doesSymbolExist(symbol->getName(), symbol->getScope(), scopedCurrent);
}

/**
 * @brief
 *
 * @param name
 * @return true if symbol exists in the symbolTable
 * @return false else
 */
bool SymbolTable::doesSymbolExist(const string& name, Scope *scope, bool scopedCurrent) {
    //Create a new scope scoped to the current scope level instead of using the whole level context
    if (scopedCurrent) {
        vector<int> currentLevelScope;
        currentLevelScope.push_back(scope->getCurrentLevel());
        scope = new Scope(scope->name);
        scope->levelContext = currentLevelScope;
    }
    return lookupSymbol(name, scope) != nullptr;
}

int SymbolTable::getOffsetType(TypeSymbol typeSymbol) {
    switch (typeSymbol) {
        case INT64_T:
            return 8;
        case INT:
            return 4;
        case INT8_T:
        case CHAR :
            return 1;
        default:
            cerr << "Error in getOffsetType" << endl;
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
<<<<<<< HEAD
Symbol *SymbolTable::returnSymbol(const string& name, const string& scope) {
    string code = Symbol::getAssociatedCode(name, scope);
    //print_dictionary();
    //cout << "code = " << code << endl;
    if (table.find(code) != table.end())
        return table.find(code)->second;
    //cout << "returnSymbol# THE SYMBOL IS NULL" << endl;
    return nullptr;
}

Symbol *SymbolTable::returnParameter(const string& name, const string& scope) {
    string code = Symbol::getAssociatedCode(name, scope);
    //cout << "code = " << code << endl;
    //print_dictionary();
    if (table.find(code) != table.end())
        return table.find(code)->second;
    //cout << "THE SYMBOL IS NULL" << endl;
    return nullptr;
=======
Symbol *SymbolTable::lookupSymbol(const string& name, Scope *scope) {
    //cout << "SYMBOL LOOK UP name = " << name << " scope context = " << scope->getLevelContextAsString() << endl;
    auto matchedMap = symbolTable.find(name);
    //cout << "lookup point #1" << endl;
    if (matchedMap != symbolTable.end()) {
        auto levelContext = scope->levelContext;
        //cout << "lookup point #2" << endl;
        /*
        for (const auto& pair : matchedMap->second) {
            cout << "Registered scope level : " << pair.first << endl;
        }
        for (const auto& firstPair : levelContext) {
            cout << "Scope level context : " << firstPair << endl;
        }*/
        for (auto it = levelContext.rbegin(); it != levelContext.rend(); ++it) {
            int level = *it;
            //cout << "Lookup for " << name << " iteration for level = " << level;
            auto symbolIt = matchedMap->second.find(level);
            if (symbolIt != matchedMap->second.end()) {
                return symbolIt->second;
            }
        }
    }
    //cout << "lookupSymbol # THE SYMBOL IS NULL" << endl;
    return nullptr;
}

Symbol *SymbolTable::lookupParameter(const string& name, Scope *scope) {
    //cout << "LOOKING UP PARAMETER HENCE SYMBOL" << endl;
    return lookupSymbol(name, scope);
>>>>>>> 31890d3689b716173009da9eab3a21c7624eb27b
}

SymbolTable::~SymbolTable() {
    for (const auto& firstPair : symbolTable) {
        for (const auto secondPair: firstPair.second) {
            delete secondPair.second;
        }
    }
}