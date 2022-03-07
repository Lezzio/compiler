#include "SymbolTable.h"
#include <iostream>

/*bool SymbolTable::addSymbol(string symbolName, int levelSymbol, int type, int address, int additional)
{
    SYMBOL symbolToAdd;
    symbolToAdd.type = Type[type];
    symbolToAdd.additional = additional;
    symbolToAdd.address = address;
    if(levelSymbol != -1){
        symbolToAdd.name = concat(symbolName, "_"+levelSymbol);
    }
    if(!doesSymbolExist(symbolToAdd)){
        this.table.insert(symbolToAdd.name, symbolToAdd);
        return true;
    }else {
        return false;
    }
}


void SymbolTable::print_dictionary(){
    cout << endl << "***   Actual Symbol Table   ***" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "| Name ; Scope ; Type ; Address ; Additionnal | ";
    cout << "--------------------------------------------------------------------------------------------" << endl;

    for (const auto& symbol : table) {
        cout << "| " << symbol.name << " ; " << symbol.scope << " ; " << symbol.type << " ; " << symbol.address << " ; " << symbol.additionnal << " | ";
    }

    cout << "--------------------------------------------------------------------------------------------" << endl;
}
*/

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
SYMBOL SymbolTable::returnSymbol(string name){
    if(table.find(name) != table.end())
        return table.find(name)->second;
    SYMBOL ret;
    ret.name = "fcc::error";
    return ret;
}