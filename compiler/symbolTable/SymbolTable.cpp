#include "SymbolTable.h"
#include <iostream>
#include <string>
#include "../error/ErrorManager.h"

#define DECLARATION_INDEX -1

using namespace std;

int SymbolTable::staticIndex;
int SymbolTable::staticTempIndex = 0;

SymbolTable::SymbolTable() {
    staticIndex = 0;
    current_function = "";
}

int SymbolTable::addSymbol(const string &symbolName, int symbolLevel, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {
    int index = staticIndex + getOffsetType(typeSymbol);
    Symbol *newSymbol = new Symbol(symbolName, symbolLevel, index, typeSymbol, additional, stateSymbol, isConst);
    if (!doesSymbolExist(newSymbol)) {
        this->table.insert(pair<string, Symbol *>(newSymbol->getCode(), newSymbol));
        staticIndex = index;
        return newSymbol->getAddress();
    } else {
        cout << "Error detected can't declare symbol twice ADD_SYMBOL" << endl;
    }
    delete newSymbol;
    return -1;
}

bool SymbolTable::declareSymbol(const string &symbolName, int symbolLevel, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {

    Symbol *newSymbol = new Symbol(symbolName, symbolLevel, DECLARATION_INDEX, typeSymbol, additional, stateSymbol, isConst);

    if (!doesSymbolExist(newSymbol)) {
        this->table.insert(pair<string, Symbol *>(newSymbol->getCode(), newSymbol));
        print_dictionary();
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
    symbol->setLevel(staticIndex);

    return symbol->getAddress();
}

int SymbolTable::defFunction(string name, TypeSymbol typeSymbol)
{
    int level = 0;
    string nameSymbol = name;
    if(level != -1){
        nameSymbol = name + "_" + to_string(level);
    }

    Symbol * symbolToAdd = new Symbol(-1, nameSymbol, typeSymbol, 0, FUNCTION, 0);

    if(!doesSymbolExist(nameSymbol,level)){
        this->table.insert(pair<string,Symbol *>(nameSymbol, symbolToAdd));
        return 0;
    }
    delete symbolToAdd;
    return -1;
}

int SymbolTable::defParameter(string name, TypeSymbol typeSymbol)
{
    int level = 0;
    string nameSymbol = name;
    if(level != -1){
        nameSymbol = name + "_"+current_function+"_" + to_string(level);
    }

    Symbol * symbolToAdd = new Symbol(-1, nameSymbol, typeSymbol, 0, PARAMETER, 0);

    if(!doesSymbolExist(nameSymbol,level)){
        this->table.insert(pair<string,Symbol *>(nameSymbol, symbolToAdd));
        return 0;
    }
    delete symbolToAdd;
    return -1;
}


void SymbolTable::print_dictionary() {
    cout << endl << "***   Actual Symbol Table   ***" << endl;
    cout
            << "-------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | " << endl;
    cout
            << "-------------------------------------------------------------------------------------------------------------"
            << endl;

    for (const auto myPair : table) {
        cout << "|  " << myPair.second->getIndex() << "  ;  " << myPair.second->getName() << "  ;  "
             << myPair.second->getScope() << "  ;  " << to_string(myPair.second->getTypeSymbol()) << "  ;  "
             << to_string(myPair.second->getAdditional()) << "  ;  " << to_string(myPair.second->getStateSymbol())
             << "  ;  " << to_string(myPair.second->getIsConst()) << "  | " << endl;
    }

    cout
            << "------------------------------------------------------------------------------------------------------------"
            << endl;
}

/**
 * @brief
 *
 * @param ident
 * @return true if symbol exists in the table
 * @return false else
 */
bool SymbolTable::doesSymbolExist(Symbol *symbol) {
    return doesSymbolExist(symbol->getCode());
}

/**
 * @brief
 *
 * @param ident
 * @return true if symbol exists in the table
 * @return false else
 */
bool SymbolTable::doesSymbolExist(string ident, int level) {
    string code = ident + "_" + to_string(level);
    return doesSymbolExist(code);
}

/**
 * @brief
 *
 * @param ident
 * @return true if symbol exists in the table
 * @return false else
 */
bool SymbolTable::doesSymbolExist(string code) {
    if (table.find(code) != table.end()) {
        return true;
    } else {
        return false;
    }
}

int SymbolTable::getAddressSymbol(string ident, int level) {
    ident = ident + "_" + to_string(level);
    if (table.find(ident) != table.end()) {
        return table.find(ident)->second->getAddress();
    } else {
        return 0;
    }
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
 *  Finds the symbol from the identificator name if existing.
 *  Returns nullptr else.
 *
 * @param name 
 * @return SYMBOL 
 */
Symbol *SymbolTable::returnSymbol(string name, int level) {
    string ident = name + "_" + to_string(level);

    if (table.find(ident) != table.end())
        return table.find(ident)->second;
    return nullptr;
}

Symbol *SymbolTable::returnParameter(string name, int level) {
    string ident = name + "_" + current_function + "_" + to_string(level);

    if (table.find(ident) != table.end())
        return table.find(ident)->second;
    return nullptr;
}

SymbolTable::~SymbolTable() {
    for (const auto myPair : table) {
        delete myPair.second;
    }
}