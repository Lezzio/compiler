#include <iostream>
using namespace std;

#include "IR.h"

/**
 * @brief Construct a new Basic Block:: Basic Block object
 * 
 * @param cfg : la control flow graphe
 * @param entry_label : le label du bloc
 */
BasicBlock::BasicBlock(CFG *cfg, string entry_label)
    : cfg(cfg), label(entry_label), exit_true(nullptr), exit_false(nullptr), scope(cfg->getCurrentScope())
{
    //cout << "BB scope is = " << cfg->getCurrentScope() << endl; debug
}

/**
 * @brief Destroy the Basic Block:: Basic Block object
 * 
 */
BasicBlock::~BasicBlock()
{
    for (IRInstr * instr : this->instructions) {
        delete (instr);
    }
}

/**
 * @brief Ajoute une instruction à la liste des instructions possibles
 * 
 * @param op : l'operation executable 
 * @param t : le type du symbole
 * @param params : les parametres liés à l'instruction
 */
void BasicBlock::add_IRInstr(IRInstr::Operation op, TypeSymbol t, vector<string> params)
{
    instructions.push_back(new IRInstr(this, op, t, params));
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

/**
 * @brief génére l'executable pour les architectures x86
 * 
 * @param o : le flux de sortie
 */
void BasicBlock::gen_asm_86(ostream &o)
{
    /*cout << "----------------" << endl;
    cout << "BasikBlock :" << endl;
        cout << label << endl;
        if(exit_true){
                cout << "exit true :" << endl;
                cout << exit_true->label << endl;
        }
        
        if(exit_false){
            cout << "exit false :" << endl;
            cout << exit_false->label << endl;
        }
    cout << "----------------" << endl;    */

    //cout << "Generating bb with label " << this->label << " and scope = " << this->scope << endl; debug

    o << label << ":" << "\n";
    if(cfg->firstBB(this)){
        this->cfg->gen_asm_prologue_x86(o);
        IRInstr * ir = new IRInstr(this,IRInstr::offset, INT64_T, {cfg->getOffset()});
        ir->gen_asm_x86(o);
        delete ir;
    }
    for(auto & instr : instructions)
    {
        instr->gen_asm_x86(o);
    }

    if(exit_true == nullptr)
    {
       //this->cfg->gen_asm_epilogue_x86(o);
    } else if(exit_false == nullptr)
    {
        o << "\tjmp\t\t\t" << exit_true->label << "\n";
    } else {
        string address = cfg->IR_reg_to_asm(test_var_name, this->scope);
        TypeSymbol t = cfg->getVarType(test_var_name, this->scope);

        string action = "\tcmpl";
        if (t == CHAR) {
            action = "\tcmpb";
        }
       o << action << "\t\t$0, " << address << "\n";
       o << "\tje\t\t\t" << exit_false->label << "\n"; 
    }
}

/**
 * @brief génère l'exécutable pour les architectures arm
 * 
 * @param o : le flux de sortie
 */
void BasicBlock::gen_asm_ARM(ostream &o)
{
    o << label << ":" << "\n";
    /*
    if(cfg->firstBB(this)){
        this->cfg->gen_asm_prologue_ARM(o);
        IRInstr * ir = new IRInstr(this,IRInstr::offset, INT64_T, {"124", "start"});
        ir->gen_asm_ARM(o);
        delete (ir);
    }*/
    for(auto & instr : instructions)
    {
        instr->gen_asm_ARM(o);
    }
}