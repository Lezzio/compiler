#include <iostream>
using namespace std;

#include "IR.h"

CFG::CFG(SymbolTable *symbolTable, string name)
        : name(name), symbolTable(symbolTable), nextBBnumber(0), current_bb(nullptr), return_bb(nullptr),
          nextTmpVarNumber(0) {

}

CFG::~CFG() {
    for (BasicBlock *bb: bbs) {
        delete (bb);
    }
    delete (return_bb);
    //delete (symbolTable);
}

void CFG::add_bb(BasicBlock *bb) {
    current_bb = bb;
    bbs.push_back(bb);
}

void CFG::addInstruction(IRInstr::Operation op, TypeSymbol t, vector<string> params) {
    current_bb->add_IRInstr(op, t, params);
}

void CFG::gen_asm_x86(ostream &o)
{
    //TODO: adapt with name of block and multiple blocks? 
        cout << ".text\n";
        string currentFunction = name;
        symbolTable->current_function = name;

#ifdef __APPLE__
    cout << ".globl _"+currentFunction+"\n"
            " _"+currentFunction+": \n";
#else
    cout << ".globl	"+currentFunction+"\n"
            " "+currentFunction+": \n";
#endif
    for(auto it = bbs.begin(); it != bbs.end(); it++)
    {
        (*it)->gen_asm_86(o);
    }
    return_bb->gen_asm_86(o);
    gen_asm_epilogue_x86(o);
    //o << "\n";
    //symbolTable->print_dictionary();
}

void CFG::gen_asm_ARM(ostream &o) {
    //TODO: adapt with name of block and multiple blocks?
    cout << ".text\n";
#ifdef __APPLE__
    cout << ".globl _main\n"
            " _main: \n";
#else
    cout << ".globl	main\n"
            " main: \n";
#endif
    gen_asm_prologue_ARM(o);
    for (auto & bb : bbs) {
        bb->gen_asm_ARM(o);
    }
    gen_asm_epilogue_ARM(o);

    //o << "\n";
    //symbolTable->print_dictionary();

}

string CFG::IR_reg_to_asm(string reg) {
    int level = 0;
    Symbol *symbolReturned = this->symbolTable->returnSymbol(reg, level);
    if (symbolReturned != nullptr) {
        string returVal = "-" + to_string(symbolReturned->getIndex()) + "(%rbp)";
        return returVal;
    }
    symbolReturned = this->symbolTable->returnParameter(reg, level);
    if (symbolReturned != nullptr) {
        int position = symbolReturned->getIndex();
        return IR_reg_to_asm_param(position);
    }
    //ERROR
    cerr << "Error in IR_reg_to_asm" << endl;
    exit(1);
}

string CFG::IR_reg_to_asm_param(int position)
{
    string returVal;
    switch (position) {
            case 1:
                returVal = "%edi";
                break;
            case 2:
                returVal = "%esi";
                break;
            case 3:
                returVal = "%edx";
                break;
            case 4:
                returVal = "%ecx";
                break;
            case 5:
                returVal = "%r8d";
                break;
            case 6:
                returVal = "%r9d";
                break;
            default:
                returVal = "unknown";
                break;
        }
        return returVal;
}


void CFG::gen_asm_prologue_x86(ostream &o) {
    o << "   #prologue\n"
         "   pushq %rbp\n"
         "   movq %rsp, %rbp\n";
}

void CFG::gen_asm_epilogue_x86(ostream &o)
{
    cout << "   #epilogue\n";
            if(get_var_type(name)== VOID){
                cout << "   nop\n";
            }
       //     "   popq %rbp\n"
    cout <<     "   leave\n"
                "   ret\n";
}


void CFG::gen_asm_prologue_ARM(ostream &o) {
    o << "\tpush\t{r7, lr}" << endl;
    o << "\tsub\tsp, sp, #space_needed" << endl;
    o << "\tadd\tr7, sp, #0" << endl;
    //TODO : gerer le sp et r7
}
/*
 * push	{r7}
	sub	sp, sp, #20
	add	r7, sp, #0
 */

void CFG::gen_asm_epilogue_ARM(ostream &o) {
    o << "\tadds\tr7, r7, #space_needed" << endl;
    o << "\tmov\tsp, r7" << endl;
    o << "\tpop\t{r7, pc}" << endl;
    //o << "\tldr\tr7, [sp], #4" << endl;
    //o << "\tbx\tlr" << endl;
}


// symbol table methods
void CFG::add_to_symbol_table(string name, TypeSymbol t, StateSymbol stateSymbol)
{
    if(stateSymbol == PARAMETER){
        this->symbolTable->defParameter(name,  t);
    }
    else if(stateSymbol == FUNCTION){
        this->symbolTable->defFunction(name,  t);
    }
    else if(stateSymbol==DECLARED){
        this->symbolTable->declareSymbol(name, 0, t, 0, DECLARED, 0);
    } else {
        symbolTable->addSymbol(name, 0, t, 0, stateSymbol, 0);
    }
}

void CFG::setParametersPosition(string name, int position) {
    Symbol *symbol = symbolTable->returnParameter(name, 0);
    symbol->setIndex(position);
}

string CFG::create_new_tempvar(TypeSymbol t) {
    string name = "!tmp" + to_string(nextTmpVarNumber);
    nextTmpVarNumber++;

    symbolTable->addSymbol(name, 0, t, 0, ASSIGNED, 0);
    return name;
}

int CFG::get_var_index(string name) {
    Symbol *symbol = symbolTable->returnSymbol(name, 0);
    //TODO: check error

    return symbol->getIndex();
}

TypeSymbol CFG::get_var_type(string name) {
    Symbol *symbol = symbolTable->returnSymbol(name, 0);
    if(symbol == nullptr){
        symbol = symbolTable->returnParameter(name, 0);
    }
    //TODO: check error
    return symbol->getTypeSymbol();
}

string CFG::new_BB_name() {
    string name = "." + this->name + "BB" + to_string(nextBBnumber);
    nextBBnumber++;
    return name;
}

void CFG::assignSymbol(string name) {
    Symbol *symbolReturned = this->symbolTable->returnSymbol(name, 0);
    this->symbolTable->assignSymbol(symbolReturned);

}

bool CFG::firstBB(BasicBlock *bb) {
    return (bb == bbs.front());
}

bool CFG::isAssigneSymbol(string name) {
    Symbol *symbolReturned = this->symbolTable->returnSymbol(name, 0);
    return (symbolReturned->getStateSymbol() == ASSIGNED);
}

void CFG::setReturnSymbol(string name) {
    if (!symbolTable->doesSymbolExist(name, 0)) {
        symbolTable->addSymbol(name, 0, INT, 0, ASSIGNED, 0);
    }
}

bool CFG::isSymbolExist(string name){
   
    return symbolTable->doesSymbolExist(name,0);
}

string CFG::getOffset(){
    return to_string(symbolTable->higherIndex);
}

SymbolTable * CFG::getSymbolTable() {
    return symbolTable;
}