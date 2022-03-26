#include <iostream>
using namespace std;

#include "IR.h"

BasicBlock::BasicBlock(CFG *cfg, string entry_label)
    : cfg(cfg), label(entry_label), exit_true(nullptr), exit_false(nullptr)
{}

BasicBlock::~BasicBlock() 
{
    for (IRInstr * instr : this->instrs) {
        delete (instr);
    }
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, TypeSymbol t, vector<string> params)
{
    instrs.push_back(new IRInstr(this, op, t, params));
}

/** TODO: 
 * Assembly jumps are generated as follows:
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
  the if, while, etc of the AST  to IR. */
void BasicBlock::gen_asm_86(ostream &o)
{
    for(vector<IRInstr*>::iterator it = instrs.begin(); it != instrs.end(); it++)
    {
        (*it)->gen_asm_x86(o);
    }

    if(exit_true == nullptr)
    {
       // this->cfg->gen_asm_prologue_x86(o);
    } else if(exit_false == nullptr)
    {
        o << "jmp   " << exit_true->label << "\n";
    } else {
        //TODO pas bien compris
    }
}