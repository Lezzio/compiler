#include "Symbol.h"
#include <iostream>

#include <utility>

/**
 * @brief Construct a new Symbol:: Symbol object
 * 
 */
Symbol::Symbol() {}

/**
 * @brief Construct a new Symbol:: Symbol object
 * 
 * @param name : name of the symbol
 * @param scope : scope of the symbol
 * @param index : index (address) of the symbol in the symbol table
 * @param typeSymbol : type of the symbol
 * @param additional : additional informations
 * @param stateSymbol : state of the symbol
 * @param isConst : bool true if symbol is const, false otherwise
 */
Symbol::Symbol(string name, Scope *scope, int index, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst, unsigned long symbolLine) {
    this->name = std::move(name);
    this->scope = scope;
    this->index = index;
    this->typeSymbol = typeSymbol;
    this->additional = additional;
    this->stateSymbol = stateSymbol;
    this->isConst = isConst;
    this->symbolLine = symbolLine;
    this->number = 0;
}

/**
 * @brief Destroy the Symbol:: Symbol object
 * 
 */
Symbol::~Symbol() {}

/**
 * @brief Setter of name of symbol
 * 
 * @param name 
 */
void Symbol::setName(string name) {
    this->name = name;
}

/**
 * @brief Setter of type of symbol
 * 
 * @param typeSymbol 
 */
void Symbol::setTypeSymbol(TypeSymbol typeSymbol) {
    this->typeSymbol = typeSymbol;
}

/**
 * @brief Setter of additional of symbol
 * 
 * @param additional 
 */
void Symbol::setAdditional(int additional) {
    this->additional = additional;
}

/**
 * @brief Setter of state of symbol
 * 
 * @param stateSymbol 
 */
void Symbol::setStateSymbol(StateSymbol stateSymbol) {
    this->stateSymbol = stateSymbol;
}

/**
 * @brief Getter of name of symbol
 * 
 * @return string 
 */
string Symbol::getName() {
    return this->name;
}

/**
 * @brief Getter of scope of symbol
 * 
 * @return Scope* 
 */
Scope *Symbol::getScope() {
    return this->scope;
}

/**
 * @brief Getter of type of symbol
 * 
 * @return TypeSymbol 
 */
TypeSymbol Symbol::getTypeSymbol() {
    return this->typeSymbol;
}

/**
 * @brief Getter of additional of symbol
 * 
 * @return int 
 */
int Symbol::getAdditional() const {
    return this->additional;
}

/**
 * @brief Getter of state of symbol
 * 
 * @return StateSymbol 
 */
StateSymbol Symbol::getStateSymbol() {
    return this->stateSymbol;
}

/**
 * @brief Getter of isConst of symbol
 * 
 * @return true 
 * @return false 
 */
bool Symbol::getIsConst() const {
    return this->isConst;
}

/**
 * @brief Getter of address (-index) of symbol
 * 
 * @return int 
 */
int Symbol::getAddress() const {
    return -getIndex();
}

/**
 * @brief Getter of index of symbol
 * 
 * @return int 
 */
int Symbol::getIndex() const {
    return index;
}

/**
 * @brief Setter of index of symbol
 * 
 * @param index 
 */
void Symbol::setIndex(int index) {
    this->index = index;
}

void Symbol::setParameters(const vector<TypeSymbol> &parameters, int number) {
    if(stateSymbol == FUNCTION) {
        this->parameters = parameters;
        this->number = number;
    }
}

int Symbol::getNumberParameters() const {
    if(stateSymbol == FUNCTION) {
        return number;
    }
    return -1;
}

TypeSymbol Symbol::getParameterType(int position) const {
    if(stateSymbol == FUNCTION) {
        return parameters[position];
    }
    return VOID;
}


