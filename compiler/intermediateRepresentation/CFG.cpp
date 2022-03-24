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
    BasicBlock * newbb = new BasicBl     ock(this, name);
    current_bb = newbb;
    bbs.push_back(newbb);
}

void CFG::addInstruction(IRInstr::Operation op, Type t, vector<string> params)
{
    current_bb->addInstruction(op, t, params);
}

void gen_asm_x86(ostream &o)
{
    //TODO: adapt with name of block and multiple blocks? 
        cout << ".text\n";
#ifdef __APPLE__
    cout << ".globl _main\n"
            " _main: \n";
#else
    cout << ".globl	main\n"
            " main: \n";
    gen_asm_prologue_x86();
    for(vector<BasicBlock*>::iterator it = bbs.begin(); it != bbs.end(); it++)
    {
        (*it)->gen_asm_x86(o);
    }
    gen_asm_epilogue_x86();
}

string IR_reg_to_asm(string reg)
{
    int level = 0;
    Symbol * symbolReturned = this->symbolTable->returnSymbol(newVariableName, level);
    if( s== nullptr )
    {
        cerr <<"Error in IR_reg_to_asm" << endl;
        exit(1);
    }
    return "-"+symbolReturned->getIndex()+"(%rbp)";
}

void CFG::gen_asm_prologue_x86(ostream &o)
{
    cout << "   #prologue\n";
            "   pushq %rbp\n"
            "   movq %rsp, %rbp\n";
}

void CFG::gen_asm_epilogue_x86(ostream &o)
{
    cout << "   #epilogue"
            "   popq %rbp\n"
            "   ret\n";
}

// symbol table methods
void CFG::add_to_symbol_table(string name, Type t, StateSymbol stateSymbol)
{
    symbolTable->addSymbol(name, 0, t, 0,stateSymbol,0);
}

string CFG::create_new_tempvar(Type t)
{
    string name = "!tmp" + to_string(nextTmpVarNumber);
    nextTmpVarNumber++;

    symbolTable->addSymbol(name, 0, t, 0,ASSIGNED, 0);
    return name;
}

int CFG::get_var_index(string name)
{
    Symbol * symbol = symbolTable->returnSymbol(name);
    //TODO: check error

    return symbol->getIndex();
}

Type get_var_type(string name)
{
    Symbol * symbol = symbolTable->returnSymbol(name);
    //TODO: check error

    return symbol->getType();
}

string new_BB_name()
{
    string name = this->name + "BB" + to_string(nextBBnumber);
    nextBBnumber++;
    return name;
}