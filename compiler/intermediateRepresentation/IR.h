#ifndef IR_H
#define IR_H

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
#include <deque>

// Declarations from the parser -- replace with your own
//TODO: fix path
#include "../symbolTable/typeSymbol.h"
#include "../symbolTable/Symbol.h"
#include "../symbolTable/SymbolTable.h"

class BasicBlock;
class CFG;
class DefFonction;

//! The class for one 3-address instruction
class IRInstr
{

public:
    /** The instructions themselves -- feel free to subclass instead */
    typedef enum
    {
        ldconst,
        ret,
        finret,
        copy,
        add,
        sub,
        mul,
        div,
        mod,
        orbit,
        andbit,
        xorbit,
        neg,
        not_,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_neq,
        cmp_lt,
        cmp_le,
        cmp_gt,
        cmp_ge,
        jmp,
        offset, 
        cast
    } Operation;

    typedef enum {
        x86,
        ARM
    } Arch;

    /**  constructor */
    IRInstr(BasicBlock *bb_, Operation op, TypeSymbol t, vector<string> params);

    /** Actual code generation */
    void gen_asm_x86(ostream &o); /**< x86 assembly code generation for this IR instruction */

    void gen_asm_ARM(ostream &o); /**< ARM assembly code generation for this IR instruction */

private:
    BasicBlock *bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    Operation op;
    TypeSymbol t;
    vector<string> params; /**< For 3-op instructions: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
    // if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design.
    int line; //The instruction line

    string getMovInstr(const string &origine,const string &destination, TypeSymbol type = INT, Arch arch = x86, bool cst = false);
    string getAddInstr(const string& arg1, const string& arg2, Arch arch = x86, const string& dest = "r3");
    string getSubInstr(const string& arg1, const string& arg2, Arch arch = x86, const string& dest = "r3");
    string getMulInstr(const string& arg1, const string& arg2, Arch arch = x86);
    string getDivInstr(const string& arg1, const string& arg2, Arch arch = x86, bool modulo = false);
    string getOrInstr(const string& arg1, const string& arg2, Arch arch = x86);
    string getAndInstr(const string& arg1, const string& arg2, Arch arch = x86);
    string getXorInstr(const string& arg1, const string& arg2, Arch arch = x86);
    string getCompInstr(const string& arg1, const string& arg2, Arch arch = x86);
    string getNegInstr(const string& arg1, Arch arch = x86);
    string getNotInstr(const string& arg1, Arch arch = x86);
    string getEqInstr(const string& arg1, Arch arch = x86);
    string getNeqInstr(const string& arg1, Arch arch = x86);
    string getLtInstr(const string& arg1, Arch arch = x86);
    string getLeInstr(const string& arg1, Arch arch = x86);
    string getGtInstr(const string& arg1, Arch arch = x86);
    string getGeInstr(const string& arg1, Arch arch = x86);
    string getJumpInstr(const string& arg1, Arch arch = x86);
    string getCallInstr(const string& arg1, Arch arch = x86);
    string getCastInstr(const string &origine, const string &destination, TypeSymbol type_from, bool sign = true, Arch arch = x86);

};

/**  The class for a basic block */

/* A few important comments.
     IRInstr has no jump instructions.
     cmp_* instructions behaves as an arithmetic two-operand instruction (add or mult),
      returning a boolean value (as an int)

     Assembly jumps are generated as follows:
     BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then
            if  exit_true  is a  nullptr,
            the epilogue is generated
        else if exit_false is a nullptr,
          an unconditional jmp to the exit_true branch is generated
                else (we have two successors, hence a branch)
          an instruction comparing the value of test_var_name to true is generated,
                    followed by a conditional branch to the exit_false branch,
                    followed by an unconditional branch to the exit_true branch
     The attribute test_var_name itself is defined when converting
  the if, while, etc of the AST  to IR.

Possible optimization:
     a cmp_* comparison instructions, if it is the last instruction of its block,
       generates an actual assembly comparison
       followed by a conditional jump to the exit_false branch
*/

class BasicBlock
{
public:
    BasicBlock(CFG *cfg, string entry_label);
    virtual ~BasicBlock();

    void gen_asm_86(ostream &o); /**< x86 assembly code generation for this basic block (very simple) */
    void gen_asm_ARM(ostream &o);   /**< ARM assembly code generation for this basic block (very simple) */

    void add_IRInstr(IRInstr::Operation op, TypeSymbol t, vector<string> params);

    // No encapsulation whatsoever here. Feel free to do better.
    BasicBlock *exit_true;    /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
    BasicBlock *exit_false;   /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
    string label;             /**< label of the BB, also will be the label in the generated code */
    CFG *cfg;                 /** < the CFG where this block belongs */
    vector<IRInstr *> instructions; /** < the instructions themselves. */
    string test_var_name;     /** < when generating IR code for an if(expr) or while(expr) etc, store here the functionName of the variable that holds the value of expr */
    Scope *scope;
protected:
};

/** The class for the control flow graph, also includes the symbol symbolTable */

/*
    A few important comments:
     The entry block is the one with the same label as the AST function functionName.
       (it could be the first of bbs, or it could be defined by an attribute value)
     The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)
 */
class CFG
{
public:
    CFG(SymbolTable * symbolTable, string name);
    virtual ~CFG();

    void add_bb(BasicBlock *bb, bool updateScope = true);
    void addInstruction(IRInstr::Operation op, TypeSymbol t, vector<string> params);

    // x86 code generation: could be encapsulated in a processor class in a retargetable compiler
    void gen_asm_x86(ostream &o);
    string IR_reg_to_asm(const string &reg, Scope *scope); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
    static string IR_reg_to_asm_param(int position);
    static void gen_asm_prologue_x86(ostream &o);
    void gen_asm_epilogue_x86(ostream &o);

    void gen_asm_ARM(ostream &o);
    void gen_asm_prologue_ARM(ostream &o);
    void gen_asm_epilogue_ARM(ostream &o);

    // symbol table methods
    void add_to_symbol_table(const string &name, TypeSymbol t, StateSymbol stateSymbol);
    void add_to_symbol_table(const string &name, TypeSymbol t, StateSymbol stateSymbol, int size);
    string create_new_tempvar(TypeSymbol t);
    int get_var_index(string name);
    TypeSymbol get_var_type(const string& name, Scope *scope);
    void assignSymbol(const string& name, Scope *scope);
    bool isSymbolAssigned(const string& name, Scope *scope);
    void setReturnSymbol(const string& name, Scope *scope);
    void setCurrentFunction(string name) { symbolTable->current_function = name; }
    void setParametersPosition(const string &name, int position, Scope *pScope);
    bool setFunctionParameters(const string &name, const vector<TypeSymbol> &parameters, int number);
    bool doesSymbolExist(const string& name, Scope *scope);
    string getOffset();
    SymbolTable * getSymbolTable();

    // basic block management
    string new_BB_name();
    BasicBlock *current_bb;
    BasicBlock *return_bb;
    string breakBBname;
    string continueBBname;

    bool firstBB(BasicBlock * bb);

    void enteringScope();
    void exitingScope();
    Scope *getCurrentScope();

protected:
    string functionName;
    int highestLevel;
    vector<int> levelHistory;
    SymbolTable * symbolTable;
    int nextTmpVarNumber;
    //int nextFreeSymbolIndex;      /**< to allocate new symbols in the symbol symbolTable */
    int nextBBnumber;             /**< just for naming */

    vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/
};

#endif