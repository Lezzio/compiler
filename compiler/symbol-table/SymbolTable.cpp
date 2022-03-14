#include "SymbolTable.h"
#include <iostream>
#include <string>

using namespace std;

int SymbolTable::staticIndex;
int SymbolTable::staticAddress;

bool SymbolTable::addSymbol(string symbolName, int levelSymbol, int type, int additional)
{
    string nameSymbol = symbolName;
    if(levelSymbol != -1){
        nameSymbol = symbolName + "_" + to_string(levelSymbol);
    }
    
    Symbol * symbolToAdd = new Symbol(staticIndex, nameSymbol, type, staticAddress, additional);
    staticIndex = staticIndex + 4;
    staticAddress = staticAddress + 1;

    if(!doesSymbolExist(nameSymbol)){
        this->table.emplace(nameSymbol, symbolToAdd);
        return true;
    }
    return false;
}


void SymbolTable::print_dictionary(){
    cout << endl << "***   Actual Symbol Table   ***" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|   Index   ;    Name   ;   Scope   ;   Type   ;   Address   ;   Additionnal   | " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto myPair : table) {
        cout << "|  " << myPair.second->getIndex() << "  ;  " << myPair.second->getName() << "  ;  " << myPair.second->getScope() << "  ;  " << myPair.second->getType() << "  ;  " << to_string(myPair.second->getAddress()) << "  ;  " << to_string(myPair.second->getAdditional()) << "  | " << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
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