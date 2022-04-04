// compilation: g++ Symbol.cpp SymbolTable.cpp testSTtemporel.cpp -o test

#include "SymbolTable.h"
#include <iostream>

string newTest(string classname, string methode, string testName){
    string ret = "TEST -- " + classname + "::" + methode + "() -- " + testName + " : ";
    return ret;
}

bool Iassert(string expected, string returned){
    if(expected == returned){
        cout << "   PASSED" << endl;
        return true;
    }else{
        cout << "   FAILED" << endl;
        return false;
    }
}

int main(int argn, const char **argv){
    auto * ST = new SymbolTable();
    //addSymbol(string symbolName, int levelSymbol, TypeSymbol typeSymbol, int additional, int state)
    ST->addSymbol("a", "GLOBAL", INT, -1, ASSIGNED, 0);
    ST->addSymbol("b", "GLOBAL", INT, 3, DECLARED, 1);
    ST->addSymbol("a","GLOBAL", INT, -1, ASSIGNED, 0);
    //cout << "Doit retourner false : ";
    //cout << ST->addSymbol("a", "GLOBAL", INT, -1, ASSIGNED, 1) << endl;
    //ST->print_dictionary();


    //debug
    //string test1 = newTest("SymboleTable", "lookupSymbol", "nameExisting");
    //cout << test1;
    if(ST->lookupSymbol("a", 0) != nullptr){
        Iassert("a", ST->lookupSymbol("a", 0)->getName());
    }else{
        cout << "Error" <<endl;
    }

    //debug
    //string test2 = newTest("SymboleTable", "lookupSymbol", "renamed");
    //cout << test2;
    if(ST->lookupSymbol("a_1", 0) != nullptr){
        Iassert("a_1", ST->lookupSymbol("a_1", 0)->getName());
    }else{
        cout << "Error" <<endl;
    }

    //debug
    //string test3 = newTest("SymboleTable", "lookupSymbol", "non existing");
    //cout << test3;
    if(ST->lookupSymbol("babar", 0) != nullptr){
        Iassert("error", ST->lookupSymbol("babar", 0)->getName());
    }else{
        //cout << "PASSED" <<endl;
    }

    delete ST;
}