#include "Symbol.h"

Symbol::Symbol(int index, string name, TypeSymbol typeSymbol, int address, int additionnal, StateSymbol stateSymbol, bool isConst){

    this->index = index;
    this->name = name;
    this->typeSymbol = typeSymbol;
    this->address = address;
    this->additional = additionnal;
    this->stateSymbol = stateSymbol;
    this->isConst = isConst;
}

Symbol::~Symbol(){ }


void Symbol::setName(string name){
    this->name = name;
}

void Symbol::setTypeSymbol(TypeSymbol typeSymbol){
    this->typeSymbol = typeSymbol;
}

void Symbol::setAddress(int address){
    this->address = address;
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

int Symbol::getAddress(){
    return this->address;
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
