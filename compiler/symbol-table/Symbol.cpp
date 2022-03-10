#include "Symbol.h"

const string Type[] = { "INTEGER", "ARGUMENT", "FONCTION", "VARIABLE", "TABLEAU" };

Symbol::Symbol(string name, int type, int address, int additionnal){
    this->name = name;
    this->type = Type[type];
    this->address = address;
    this->additional = additionnal;
}


void Symbol::setName(string name){
    this->name = name;
}

void Symbol::setType(int type){
    this->type = Type[type];
}

void Symbol::setAddress(int address){
    this->address = address;
}

void Symbol::setAdditional(int additional){
    this->additional = additional;
}

string Symbol::getName(){
    return this->name;
}

string Symbol::getScope(){
    return this->scope;
}

string Symbol::getType(){
    return this->type;
}

int Symbol::getAddress(){
    return this->address;
}

int Symbol::getAdditional(){
    return this->additional;
}

