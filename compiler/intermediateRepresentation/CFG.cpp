#include <iostream>
#include <utility>

using namespace std;

#include "IR.h"

CFG::CFG(SymbolTable *symbolTable, string name)
        : functionName(std::move(name)), symbolTable(symbolTable), nextBBnumber(0), current_bb(nullptr), return_bb(nullptr),
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
    //TODO: adapt with functionName of block and multiple blocks?
    cout << ".text\n";
    string currentFunction = functionName;
    symbolTable->current_function = functionName;

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
    //TODO: adapt with functionName of block and multiple blocks?
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

string CFG::IR_reg_to_asm(const string &reg, Scope *scope) {
    //cout << "IR reg to asm" << endl; debug
    //cout << "reg = " << reg << " | scope = " << scope << endl; debug
    Symbol *symbolReturned = this->symbolTable->lookupSymbol(reg, scope);
    if (symbolReturned != nullptr) {
        string returnVal = "-" + to_string(symbolReturned->getIndex()) + "(%rbp)";
        return returnVal;
    }
    symbolReturned = this->symbolTable->lookupParameter(reg, scope);
    if (symbolReturned != nullptr) {
        int position = symbolReturned->getIndex();
        return IR_reg_to_asm_param(position);
    }
    //ERROR
    cout << "reg = " << reg << endl;
    symbolTable->print_dictionary();
    cerr << "Error in IR_reg_to_asm" << endl;
    exit(1);
}

string CFG::IR_reg_to_asm_param(int position) {
    string retVal;
    switch (position) {
        case 1:
            retVal = "%edi";
            break;
        case 2:
            retVal = "%esi";
            break;
        case 3:
            retVal = "%edx";
            break;
        case 4:
            retVal = "%ecx";
            break;
        case 5:
            retVal = "%r8d";
            break;
        case 6:
            retVal = "%r9d";
            break;
        default:
            retVal = "unknown";
            break;
    }
    return retVal;
}

void CFG::gen_asm_prologue_x86(ostream &o) {
    o << "\t#prologue\n"
         "\tpushq\t\t%rbp\n"
         "\tmovq\t\t%rsp, %rbp\n";
}

void CFG::gen_asm_epilogue_x86(ostream &o) {
    cout << "\t#epilogue\n";
    if (get_var_type(functionName, &GLOBAL_SCOPE) == VOID) {
        cout << "\tnop\n";
    }
    //     "   popq %rbp\n"
    cout << "\tleave\n"
            "\tret\n";
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

// symbol symbolTable methods
void CFG::add_to_symbol_table(const string &name, TypeSymbol t, StateSymbol stateSymbol) {
    //cout << "--------------" << endl; debug
    //cout << "About to add symbol named = " << name << endl; debug
    if (stateSymbol == PARAMETER) {
        this->symbolTable->defParameter(name, getCurrentScope(), t);
    } else if (stateSymbol == FUNCTION) {
        this->symbolTable->defFunction(name, t);
    } else if (stateSymbol == DECLARED) {
        this->symbolTable->declareSymbol(name, getCurrentScope(), t, 0, DECLARED, false);
    } else {
        symbolTable->addSymbol(name, getCurrentScope(), t, 0, stateSymbol, false);
    }
}

void CFG::add_to_symbol_table(const string &name, TypeSymbol t, StateSymbol stateSymbol, int size){
    symbolTable->addSymbol(name, getCurrentScope(), t, size, stateSymbol, false);
}

//TODO Feed scope to the set parameter position => now check if working
void CFG::setParametersPosition(const string &name, int position, Scope *pScope) {
    Symbol *symbol = symbolTable->lookupParameter(name, pScope);
    symbol->setIndex(position);
}

string CFG::create_new_tempvar(TypeSymbol t) {
    string name = "!tmp" + to_string(nextTmpVarNumber);
    nextTmpVarNumber++;

    symbolTable->addSymbol(name, getCurrentScope(), t, 0, ASSIGNED, false);
    return name;
}

int CFG::get_var_index(string name) {
    Symbol *symbol = symbolTable->lookupSymbol(name, getCurrentScope());
    //TODO: check error

    return symbol->getIndex();
}

TypeSymbol CFG::get_var_type(const string& name, Scope *scope) {
    //cout << "GET VAR TYPE name = " << name << " scope context = " << scope->getLevelContextAsString() << endl; debug
    Symbol *symbol = symbolTable->lookupSymbol(name, scope);
    if (symbol == nullptr) {
        symbol = symbolTable->lookupParameter(name, scope);
    }
    //TODO: check error
    return symbol->getTypeSymbol();
}


/**
 * @return a newly generated functionName for a basic block following the format :
 * .(function functionName)#(basic block number)
 */
string CFG::new_BB_name() {
    string name = "." + this->functionName + "_" + to_string(nextBBnumber);
    nextBBnumber++;
    return name;
}

void CFG::assignSymbol(const string& name, Scope *scope) {
    Symbol *symbolReturned = this->symbolTable->lookupSymbol(name, scope);
    this->symbolTable->assignSymbol(symbolReturned);
}

bool CFG::firstBB(BasicBlock *bb) {
    return (bb == bbs.front());
}

bool CFG::isSymbolAssigned(const string& name, Scope *scope) {
    Symbol *symbolReturned = this->symbolTable->lookupSymbol(name, scope);
    return (symbolReturned->getStateSymbol() == ASSIGNED);
}

void CFG::setReturnSymbol(const string& name, Scope *scope) {
    if (!symbolTable->doesSymbolExist(name, scope)) {
        symbolTable->addSymbol(name, scope, INT, 0, ASSIGNED, false);
    }
}

bool CFG::doesSymbolExist(const string& name, Scope *scope) {
    return symbolTable->doesSymbolExist(name, scope);
}

string CFG::getOffset() {
    return to_string(symbolTable->highestIndex);
}

SymbolTable *CFG::getSymbolTable() {
    return symbolTable;
}

void CFG::enteringScope() {
    //cout << "Entering scope" << endl; debug
    int level = highestLevel++;
    //cout << "Level = " << level; debug
    levelHistory.push_back(level);
    current_bb->scope = getCurrentScope(); //Update the current basic block to be aligned with the new scope
}

void CFG::exitingScope() {
    levelHistory.pop_back();
}

Scope *CFG::getCurrentScope() {
    int level = levelHistory.back();
    //cout << "| Current scope LEVEL is = " << level << " function name " + functionName << endl; debug
    auto *scope = new Scope(functionName);
    scope->levelContext = levelHistory; //Copy assign
    return scope;
}