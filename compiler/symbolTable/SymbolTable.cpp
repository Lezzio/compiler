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

/**
 * @brief Method which creates and adds a symbol to the symbol table
 * 
 * @param symbolName : the name of the new symbol to add
 * @param symbolScope : the scope of the new symbol
 * @param typeSymbol : the type
 * @param additional : additional information as for instance in case of a array the number of elements it contains
 * @param state : DECLARED, ASSIGNED...
 * @param isConst : bool, symbol is a const or not
 * @return int : return the address of the new symbol 
 */
int SymbolTable::addSymbol(const string &symbolName, Scope * symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol state, bool isConst) {
    
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

/**
 * @brief Method which declares a symbol (save the memory space for the new symbol) 
 * 
 * @param symbolName : the name of the new symbol to add
 * @param symbolScope : the scope of the new symbol
 * @param typeSymbol : the type
 * @param additional : additional information as for instance in case of a array the number of elements it contains
 * @param state : DECLARED, ASSIGNED...
 * @param isConst : bool, symbol is a const or not 
 * @return true : if the symbol doesn't exists in the table (haven't been declared already)
 * @return false : if the symbol exists already in the symbol table -> error case
 */
bool SymbolTable::declareSymbol(const string &symbolName, Scope *symbolScope, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {
    
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

/**
 * @brief Method which assigns a symbol in the symbol table which means it gives it an fixed address in the table
 * 
 * @param symbol : symbol to assign
 * @return int : the symbol address
 */
int SymbolTable::assignSymbol(Symbol *symbol) {
    symbol->setStateSymbol(ASSIGNED);
    staticIndex += getOffsetType(symbol->getTypeSymbol());
    highestIndex = staticIndex;
    symbol->setIndex(staticIndex);
    return symbol->getAddress();
}

/**
 * @brief Method which creates a function in the symbol table  
 * 
 * @param name : name of the function
 * @param typeSymbol : type of the return
 * @return int : value which permits to know if the adding succeed or not
 */
int SymbolTable::defFunction(const string& name, TypeSymbol typeSymbol) {
    
    auto *newSymbol = new Symbol(name, &GLOBAL_SCOPE, DECLARATION_INDEX, typeSymbol, 0, FUNCTION, false);
    if (!doesSymbolExist(newSymbol)) {
        this->symbolTable[newSymbol->getName()][GLOBAL_SCOPE.getCurrentLevel()] = newSymbol;
        return 0;
    }
    delete newSymbol;
    return -1;
}

/**
 * @brief Method which creates a parameter in the symbol table  
 * 
 * @param name : name of the parameter
 * @param scope : scope of the parameter in the program
 * @param typeSymbol : type of the parameter 
 * @return true : adding succeed
 * @return false : adding failed (symbol alreay exists in the symbol table)
 */
bool SymbolTable::defParameter(const string& name, Scope *scope, TypeSymbol typeSymbol) {
    auto *newSymbol = new Symbol(name, scope, DECLARATION_INDEX, typeSymbol, 0, PARAMETER, false);
    if (!doesSymbolExist(newSymbol, true)) {
        this->symbolTable[newSymbol->getName()][GLOBAL_SCOPE.getCurrentLevel()] = newSymbol;
        return true;
    }
    delete newSymbol;
    return false;
}

/**
 * @brief Method which permits to print the content of symbol table 
 * 
 */
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
 * @brief Method which permits to know if a symbol exist or not at the time in the symbol table
 * 
 * @param symbol : symbol to check
 * @param scopedCurrent : bool telling if the scope is current
 * @return true : symbol exists in the symbol table
 * @return false : symbol doesn't exist in the symbol table
 */
bool SymbolTable::doesSymbolExist(Symbol *symbol, bool scopedCurrent) {
    return doesSymbolExist(symbol->getName(), symbol->getScope(), scopedCurrent);
}

/**
 * @brief Method which permits to know if a symbol exist or not at the time in the symbol table
 * 
 * @param name : name of the symbol to check
 * @param scope : scope when the method is called
 * @param scopedCurrent : bool telling if the scope is current
 * @return true : symbol exists in the symbol table
 * @return false : symbol doesn't exist in the symbol table
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

/**
 * @brief Method which gives in function of a type the offset to apply on the address in the symbol table
 * 
 * @param typeSymbol : type we want to know the offset to apply
 * @return int : the offset to apply
 */
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

/**
 * @brief lookup function 
 * 
 * @param name : name of the symbol to lookup
 * @param scope : scope when the method is called
 * @return Symbol* 
 */
Symbol *SymbolTable::lookupParameter(const string& name, Scope *scope) {
    //cout << "LOOKING UP PARAMETER HENCE SYMBOL" << endl;
    return lookupSymbol(name, scope);
}

/**
 * @brief Destroy the Symbol Table:: Symbol Table object
 * 
 */
SymbolTable::~SymbolTable() {
    for (const auto& firstPair : symbolTable) {
        for (const auto secondPair: firstPair.second) {
            delete secondPair.second;
        }
    }
}