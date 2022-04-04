#include "Symbol.h"
#include <iostream>

#include <utility>

Symbol::Symbol() {}

Symbol::Symbol(string name, Scope *scope, int index, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {
    this->name = std::move(name);
    this->scope = scope;
    this->index = index;
    this->typeSymbol = typeSymbol;
    this->additional = additional;
    this->stateSymbol = stateSymbol;
    this->isConst = isConst;

    this->number = 0;
}

Symbol::~Symbol() {}

void Symbol::setName(string name) {
    this->name = name;
}

void Symbol::setTypeSymbol(TypeSymbol typeSymbol) {
    this->typeSymbol = typeSymbol;
}

void Symbol::setAdditional(int additional) {
    this->additional = additional;
}

void Symbol::setStateSymbol(StateSymbol stateSymbol) {
    this->stateSymbol = stateSymbol;
}

string Symbol::getName() {
    return this->name;
}

Scope *Symbol::getScope() {
    return this->scope;
}

TypeSymbol Symbol::getTypeSymbol() {
    return this->typeSymbol;
}

int Symbol::getAdditional() const {
    return this->additional;
}

StateSymbol Symbol::getStateSymbol() {
    return this->stateSymbol;
}

bool Symbol::getIsConst() const {
    return this->isConst;
}

int Symbol::getAddress() const {
    return -getIndex();
}

int Symbol::getIndex() const {
    return index;
}

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


