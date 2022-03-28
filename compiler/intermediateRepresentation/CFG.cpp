#include <iostream>
using namespace std;

#include "IR.h"

CFG::CFG(SymbolTable * symbolTable, string name)
    : name(name), symbolTable(symbolTable), nextBBnumber(0), current_bb(nullptr), nextTmpVarNumber(0)
{

}

CFG::~CFG() {
    for (BasicBlock * bb : bbs) {
        delete (bb);
    }
}

void CFG::add_bb(BasicBlock *bb)
{
    string name = new_BB_name();
    BasicBlock * newbb = new BasicBlock(this, name);
    current_bb = newbb;
    bbs.push_back(newbb);
}

void CFG::addInstruction(IRInstr::Operation op, TypeSymbol t, vector<string> params)
{
    current_bb->add_IRInstr(op, t, params);
}

void CFG::gen_asm_x86(ostream &o)
{
    //TODO: adapt with name of block and multiple blocks? 
        cout << ".text\n";
#ifdef __APPLE__
    cout << ".globl _main\n"
            " _main: \n";
#else
    cout << ".globl	main\n"
            " main: \n";
#endif
    gen_asm_prologue_x86(o);
    for(vector<BasicBlock*>::iterator it = bbs.begin(); it != bbs.end(); it++)
    {
        (*it)->gen_asm_86(o);
    }
    gen_asm_epilogue_x86(o);

    //o << "\n";
    //symbolTable->print_dictionary();

}

string CFG::IR_reg_to_asm(string reg) {
    int level = 0;
    Symbol *symbolReturned = this->symbolTable->returnSymbol(reg, level);
    if (symbolReturned == nullptr) {
        //ERROR
        cerr << "Error in IR_reg_to_asm" << endl;
        exit(1);
    }
    string returVal = "-" + to_string(symbolReturned->getIndex()) + "(%rbp)";
    return returVal;
}

void CFG::gen_asm_prologue_x86(ostream &o)
{
    cout << "   #prologue\n"
            "   pushq %rbp\n"
            "   movq %rsp, %rbp\n";
}

void CFG::gen_asm_epilogue_x86(ostream &o)
{
    cout << "   #epilogue\n"
            "   popq %rbp\n"
            "   ret\n";
}

// symbol table methods
void CFG::add_to_symbol_table(string name, TypeSymbol t, StateSymbol stateSymbol)
{
    if(stateSymbol==DECLARED){
        this->symbolTable->declareSymbol(name, 0, t, 0, DECLARED, 0);
    } else {
         symbolTable->addSymbol(name, 0, t, 0,stateSymbol,0);
    }

}

string CFG::create_new_tempvar(TypeSymbol t)
{
    string name = "!tmp" + to_string(nextTmpVarNumber);
    nextTmpVarNumber++;

    symbolTable->addSymbol(name, 0, t, 0,ASSIGNED, 0);
    return name;
}

int CFG::get_var_index(string name)
{
    Symbol * symbol = symbolTable->returnSymbol(name, 0);
    //TODO: check error

    return symbol->getIndex();
}

TypeSymbol CFG::get_var_type(string name)
{
    Symbol * symbol = symbolTable->returnSymbol(name, 0);
    //TODO: check error

    return symbol->getTypeSymbol();
}

string CFG::new_BB_name()
{
    string name = this->name + "BB" + to_string(nextBBnumber);
    nextBBnumber++;
    return name;
}

void CFG::assignSymbol(string name)
{
    Symbol * symbolReturned = this->symbolTable->returnSymbol(name, 0);
    this->symbolTable->assignSymbol(symbolReturned);

}