#include "SymbolTable.h"
#include <iostream>
#include <string>

using namespace std;

int SymbolTable::staticIndex;

SymbolTable::SymbolTable(){ staticIndex = 4;}

int SymbolTable::addSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst)
{
    string nameSymbol = symbolName;
    if(levelSymbol != -1){
        nameSymbol = symbolName + "_" + to_string(levelSymbol);
    }
    
    Symbol * symbolToAdd = new Symbol(staticIndex, nameSymbol, typeSymbol, additional, stateSymbol, isConst);

    if(!doesSymbolExist(nameSymbol,levelSymbol)){
        this->table.insert(pair<string,Symbol *>(nameSymbol, symbolToAdd));
        int returnadress = -staticIndex;
        staticIndex = staticIndex + 4;
        return returnadress;
    }
    delete symbolToAdd;
    return -1;
}

int SymbolTable::declareSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, StateSymbol stateSymbol, bool isConst)
{
    string nameSymbol = symbolName;
    if(levelSymbol != -1){
        nameSymbol = symbolName + "_" + to_string(levelSymbol);
    }
    
    Symbol * symbolToAdd = new Symbol(-1, nameSymbol, typeSymbol, additional, stateSymbol, isConst);

    if(!doesSymbolExist(nameSymbol,levelSymbol)){
        this->table.insert(pair<string,Symbol *>(nameSymbol, symbolToAdd));
        return 0;
    }
    delete symbolToAdd;
    return -1;
}


void SymbolTable::print_dictionary(){
    cout << endl << "***   Actual Symbol Table   ***" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|   Index   ;    Name   ;   Scope   ;   Type   ;   Additionnal   ;    State    ;    IsConst   | " << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    for (const auto myPair : table) {
        cout << "|  " << myPair.second->getIndex() << "  ;  " << myPair.second->getName() << "  ;  " << myPair.second->getScope() << "  ;  " << to_string(myPair.second->getTypeSymbol()) << "  ;  "<< to_string(myPair.second->getAdditional()) << "  ;  " << to_string(myPair.second->getStateSymbol()) << "  ;  " << to_string(myPair.second->getIsConst()) << "  | " << endl;
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
bool SymbolTable::doesSymbolExist(string ident, int level){
    if(table.find(ident+"_"+to_string(level)) != table.end()){
        return true;
    }else{
        return false;
    }
}

int SymbolTable::getAddressSymbol(string ident, int level){
    ident = ident+"_"+to_string(level);
    if(table.find(ident) != table.end()){
        return table.find(ident)->second->getAddress();
    }else{
        return 0;
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
Symbol * SymbolTable::returnSymbol(string name,int level){
    string ident = name+"_"+to_string(level);

    if(table.find(ident) != table.end())
        return table.find(ident)->second;
    return nullptr;
}

SymbolTable::~SymbolTable(){
    for (const auto myPair : table) {
        delete myPair.second;
    }
}