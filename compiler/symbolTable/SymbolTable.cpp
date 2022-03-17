#include "SymbolTable.h"
#include <iostream>
#include <string>

using namespace std;

int SymbolTable::staticIndex;
int SymbolTable::staticAddress;

SymbolTable::SymbolTable(){ staticIndex = 4; staticAddress = 0;}

bool SymbolTable::addSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst)
{
    string nameSymbol = symbolName;
    if(levelSymbol != -1){
        nameSymbol = symbolName + "_" + to_string(levelSymbol);
    }
    
    Symbol * symbolToAdd = new Symbol(staticIndex, nameSymbol, typeSymbol, staticAddress, additional, stateSymbol, isConst);
    staticIndex = staticIndex + 4;
    staticAddress = staticAddress + 1;

    if(!doesSymbolExist(nameSymbol)){
        this->table.insert(pair<string,Symbol *>(nameSymbol, symbolToAdd));
        return true;
    }
    delete symbolToAdd;
    return false;
}


void SymbolTable::print_dictionary(){
    cout << endl << "***   Actual Symbol Table   ***" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|   Index   ;    Name   ;   Scope   ;   Type   ;   Address   ;   Additionnal   ;    State    ;    IsConst   | " << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    for (const auto myPair : table) {
        cout << "|  " << myPair.second->getIndex() << "  ;  " << myPair.second->getName() << "  ;  " << myPair.second->getScope() << "  ;  " << to_string(myPair.second->getTypeSymbol()) << "  ;  " << to_string(myPair.second->getAddress()) << "  ;  " << to_string(myPair.second->getAdditional()) << "  ;  " << to_string(myPair.second->getStateSymbol()) << "  ;  " << to_string(myPair.second->getIsConst()) << "  | " << endl;
    }

    cout << "------------------------------------------------------------------------------------------------------------" << endl;
}


/**
 * @brief 
 * 
 * @param ident 
 * @return true if symbol exists in the table
 * @return false else
 */
bool SymbolTable::doesSymbolExist(string ident){
    if(table.find(ident) != table.end()){
        return true;
    }else{
        return false;
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
Symbol * SymbolTable::returnSymbol(string name){
    if(table.find(name) != table.end())
        return table.find(name)->second;
    return nullptr;
}

SymbolTable::~SymbolTable(){
    for (const auto myPair : table) {
        delete myPair.second;
    }
}