#include "Symbol.h"
#include <iostream>

#include <utility>

Symbol::Symbol() {}

Symbol::Symbol(string name, int level, int index, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst) {
    this->name = std::move(name);
    this->level = level;
    this->index = index;
    this->typeSymbol = typeSymbol;
    this->additional = additional;
    this->stateSymbol = stateSymbol;
    this->isConst = isConst;
}

Symbol::~Symbol() {}

void Symbol::setLevel(int level) {
    this->level = level;
}

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

string Symbol::getScope() {
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

string Symbol::getCode() {
    return name + "_" + to_string(level);
}

int Symbol::getLevel() const {
    return level;
}

int Symbol::getIndex() const {
    return index;
}

void Symbol::setIndex(int index) {
    this->index = index;
}
