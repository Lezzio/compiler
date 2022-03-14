// compilation: g++ Symbol.cpp SymbolTable.cpp testSTtemporel.cpp -o test

#include "SymbolTable.h"
#include <iostream>

int main(int argn, const char **argv){
    SymbolTable * ST = new SymbolTable();
    ST->addSymbol("a", -1, 0, -1);
    ST->addSymbol("b", -1, 4, 3);
    ST->addSymbol("a", 1, 0, -1);
    cout << "Doit retourner false : ";
    cout << ST->addSymbol("a", 1, 0, -1) << endl;
    ST->print_dictionary();


    cout << "TEST SymbolTable.returnSymbol() :" << endl;
    // Name existing
    cout << "  Expected value \"a\" - ";
    if(ST->returnSymbol("a") != nullptr){
        cout << ST->returnSymbol("a")->getName() << endl;
    }else{
        cout << "error" <<endl;
    }
    // Name renamed
    cout << "  Expected value \"a_1\" - ";
    if(ST->returnSymbol("a_1") != nullptr){
        cout << ST->returnSymbol("a_1")->getName() << endl;
    }else{
        cout << "error" <<endl;
    }
    // Name non existing
    cout << "  Expected value \"error\" - ";
    if(ST->returnSymbol("babar") != nullptr){
        cout << ST->returnSymbol("babar")->getName() << endl;
    }else{
        cout << "error" <<endl;
    }
}



