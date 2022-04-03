#include <iostream>
#include <utility>

using namespace std;

#include "IR.h"

CFG::CFG(SymbolTable *symbolTable, string name)
        : name(std::move(name)), symbolTable(symbolTable), nextBBnumber(0), current_bb(nullptr), return_bb(nullptr),
          nextTmpVarNumber(0), highestLevel(0), breakBBname(""), continueBBname("") {
    levelHistory.push_back(0);
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

void CFG::gen_asm_x86(ostream &o) {
    //TODO: adapt with name of block and multiple blocks? 
    cout << ".text\n";
    string currentFunction = name;
    symbolTable->current_function = name;

#ifdef __APPLE__
    cout << ".globl _" + currentFunction + "\n"
                                           " _" + currentFunction + ": \n";
#else
    cout << ".globl	"+currentFunction+"\n"
            " "+currentFunction+": \n";
#endif
    for (auto it = bbs.begin(); it != bbs.end(); it++) {
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
    //gen_asm_prologue_ARM(o);
    for (auto &bb : bbs) {
        bb->gen_asm_ARM(o);
    }

    IRInstr *ir = new IRInstr(bbs.back(), IRInstr::offset, INT64_T, {"124", "end"});
    ir->gen_asm_ARM(o);
    delete (ir);
    gen_asm_epilogue_ARM(o);
}

string CFG::IR_reg_to_asm(const string &reg, const string &scope) {
    cout << "IR reg to asm" << endl;
    cout << "reg = " << reg << endl;
    Symbol *symbolReturned = this->symbolTable->returnSymbol(reg, scope);
    if (symbolReturned != nullptr) {
        string returnVal = "-" + to_string(symbolReturned->getIndex()) + "(%rbp)";
        return returnVal;
    }
    symbolReturned = this->symbolTable->returnParameter(reg, scope);
    if (symbolReturned != nullptr) {
        int position = symbolReturned->getIndex();
        return IR_reg_to_asm_param(position);
    }
    //ERROR
    cerr << "Error in IR_reg_to_asm" << endl;
    exit(1);
}

string CFG::IR_reg_to_asm_param(int position) {
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

void CFG::gen_asm_epilogue_x86(ostream &o) {
    cout << "   #epilogue\n";
    if (get_var_type(name, "GLOBAL") == VOID) {
        cout << "   nop\n";
    }
    //     "   popq %rbp\n"
    cout << "   leave\n"
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
void CFG::add_to_symbol_table(string name, TypeSymbol t, StateSymbol stateSymbol) {
    cout << "About to add symbol name = " << name << endl;
    symbolTable->print_dictionary();
    if (stateSymbol == PARAMETER) {
        this->symbolTable->defParameter(name, getCurrentScope(), t);
    } else if (stateSymbol == FUNCTION) {
        this->symbolTable->defFunction(name, t);
    } else if (stateSymbol == DECLARED) {
        this->symbolTable->declareSymbol(name, getCurrentScope(), t, 0, DECLARED, false);
    } else {
        symbolTable->addSymbol(name, getCurrentScope(), t, 0, stateSymbol, false);
    }
    cout << "Added symbol finished" << endl;
}

void CFG::setParametersPosition(string name, int position) {
    Symbol *symbol = symbolTable->returnParameter(name, 0);
    symbol->setIndex(position);
}

string CFG::create_new_tempvar(TypeSymbol t) {
    string name = "!tmp" + to_string(nextTmpVarNumber);
    nextTmpVarNumber++;

    symbolTable->addSymbol(name, getCurrentScope(), t, 0, ASSIGNED, false);
    return name;
}

int CFG::get_var_index(string name) {
    Symbol *symbol = symbolTable->returnSymbol(name, getCurrentScope());
    //TODO: check error

    return symbol->getIndex();
}

TypeSymbol CFG::get_var_type(const string& name, const string& scope) {
    Symbol *symbol = symbolTable->returnSymbol(name, scope);
    if (symbol == nullptr) {
        symbol = symbolTable->returnParameter(name, scope);
    }
    //TODO: check error
    return symbol->getTypeSymbol();
}

/**
 * @return a newly generated name for a basic block following the format :
 * .(function name)#(basic block number)
 */
string CFG::new_BB_name() {
    string name = "." + this->name + "#" + to_string(nextBBnumber);
    nextBBnumber++;
    return name;
}

void CFG::assignSymbol(string name) {
    Symbol *symbolReturned = this->symbolTable->returnSymbol(name, getCurrentScope());
    this->symbolTable->assignSymbol(symbolReturned);

}

bool CFG::firstBB(BasicBlock *bb) {
    return (bb == bbs.front());
}

bool CFG::isSymbolAssigned(const string& name, const string& scope) {
    Symbol *symbolReturned = this->symbolTable->returnSymbol(name, scope);
    return (symbolReturned->getStateSymbol() == ASSIGNED);
}

void CFG::setReturnSymbol(const string& name, const string& scope) {
    if (!symbolTable->doesSymbolExist(name, scope)) {
        symbolTable->addSymbol(name, scope, INT, 0, ASSIGNED, false);
    }
}

bool CFG::doesSymbolExist(string name, string scope) {
    return symbolTable->doesSymbolExist(name, scope);
}

string CFG::getOffset() {
    return to_string(symbolTable->highestIndex);
}

SymbolTable *CFG::getSymbolTable() {
    return symbolTable;
}

void CFG::enteringScope() {
    cout << "Entering scope" << endl;
    int level = highestLevel++;
    cout << "Level = " << level;
    levelHistory.push_back(level);
}

void CFG::exitingScope() {
    levelHistory.pop_back();
}

string CFG::getCurrentScope() {
    int level = levelHistory.back();
    cout << "Scope is = " << level << " " + name + "_" + to_string(level) << endl;
    return name + "_" + to_string(level);
}