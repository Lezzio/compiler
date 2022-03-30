#include "Symbol.h"
#include <iostream>

Symbol::Symbol(int index, int level, string name, TypeSymbol typeSymbol, int additionnal, StateSymbol stateSymbol, bool isConst){
    this->level = level;
    this->index = index;
    this->name = name;
    this->typeSymbol = typeSymbol;
    this->additional = additionnal;
    this->stateSymbol = stateSymbol;
    this->isConst = isConst;
}

Symbol::~Symbol(){ }

void Symbol::setIndex(int index) { 
    this->index = index;
}

void Symbol::setName(string name){
    this->name = name;
}

void Symbol::setTypeSymbol(TypeSymbol typeSymbol){
    this->typeSymbol = typeSymbol;
}

void Symbol::setAdditional(int additional){
    this->additional = additional;
}

void Symbol::setStateSymbol(StateSymbol stateSymbol){
    this->stateSymbol = stateSymbol;
}

string Symbol::getName(){
    return this->name;
}

string Symbol::getScope(){
    return this->scope;
}

TypeSymbol Symbol::getTypeSymbol(){
    return this->typeSymbol;
}

int Symbol::getAdditional(){
    return this->additional;
}

int Symbol::getIndex(){
    return this->index;
}

StateSymbol Symbol::getStateSymbol(){
    return this->stateSymbol;
}

bool Symbol::getIsConst(){
    return this->isConst;
}

int Symbol::getAddress(){
    return -this->index;
}

string Symbol::getCode() {
    return name + "_" + to_string(level);
}
