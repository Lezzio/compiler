#include <iostream>
using namespace std;

#include "IR.h"

void IRInstr::gen_asm_x86(ostream &o)
{
    switch (op) {
        case ldconst:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string value = this->params[1];
            o << getMovInstr(value, destination);
            break;
        case copy:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            o << getMovInstr(origin, "%eax");
            o << getMovInstr("%eax", destination);
            break;     
        case add:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getAddInstr(rvalue, "%eax");
            o << getMovInstr("%eax", lvalue);
            break;
        case sub:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getSubInstr(rvalue, "%eax");
            o << getMovInstr("%eax", lvalue);  
            break;
        case mul:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getMulInstr(rvalue, "%eax");
            o << getMovInstr("%eax", lvalue);   
            break;
        case div:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getDivInstr(rvalue, "%eax");
            o << getMovInstr("%eax", lvalue); 
            break;
        case mod:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getDivInstr(rvalue, "%eax");
            o << getMovInstr("%edx", lvalue);
            break;
        case orbit:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getOrInstr(rvalue, "%eax");
            o << getMovInstr("%edx", lvalue);
            break;
        case andbit:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getAndInstr(rvalue, "%eax");
            o << getMovInstr("%edx", lvalue);
            break;
        case xorbit:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getXorInstr(rvalue, "%eax");
            o << getMovInstr("%edx", lvalue);
            break;    
        case neg:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getNegInstr("%eax");
            o << getMovInstr("%edx", lvalue);
            break;   
        case not:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getNotInstr("%eax");
            o << getMovInstr("%edx", lvalue);
            break;                     
        case rmem:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            o << getMovInstr(origin, "%eax");
            o << getMovInstr("(%eax)", "%r10");
            o << getMovInstr("%r10", destination);
            break;
        case wmem:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            o << getMovInstr(origin, "%eax");
            o << getMovInstr(destination, "%r10");
            o << getMovInstr("%r10", "(%eax)");
            break;
        case call:
            //TODO:
            break;
        case cmp_eq:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getEqInstr("%al");
            o << getMovInstr("%al", "%edx", INT8_T);
            o << getMovInstr("%edx", lvalue);            
            break;
        case cmp_neq:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getNeqInstr("%al");
            o << getMovInstr("%al", "%edx", INT8_T);
            o << getMovInstr("%edx", lvalue);
            break;
        case cmp_lt:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getLtInstr("%al");
            o << getMovInstr("%al", "%edx", INT8_T);
            o << getMovInstr("%edx", lvalue);
            break;
        case cmp_le:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getLeInstr("%al");
            o << getMovInstr("%al", "%edx", INT8_T);
            o << getMovInstr("%edx", lvalue);
            break;
        case cmp_gt:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getGtInstr("%al");
            o << getMovInstr("%al", "%edx", INT8_T);
            o << getMovInstr("%edx", lvalue);
            break;
        case cmp_ge:
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getGeInstr("%al");
            o << getMovInstr("%al", "%edx", INT8_T);
            o << getMovInstr("%edx", lvalue);
            break;
        default:
            break;
    }
}

IRInstr::IRInstr(BasicBlock *bb_, Operation op, Type t, vector<string> params)
    : bb(bb_), op(op), t(t), params_(params)
{
}

string IRInstr::getMovInstr(string origin, string destination, Type type)
{
    if(type == INT){
        return "    movl " << origin <<", " << destination << "\n";
    } else if (type ==INT8_T) {
        return "    movzbl " << origin <<", " << destination << "\n";
    }
    return ""
}

string IRInstr::getAddInstr(string arg1, string arg2)
{
    return "    addl " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getSubInstr(string arg1, string arg2)
{
    return "    subl " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getMulInstr(string arg1, string arg2)
{
    return "    imul " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getDivInstr(string arg1, string arg2)
{
    return "    idivl " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getOrInstr(string arg1, string arg2)
{
    return "    orl " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getAndInstr(string arg1, string arg2)
{
    return "    andl " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getXorInstr(string arg1, string arg2)
{
    return "    xorl " << arg1 << ", " << arg2 << "\n";
}

string IRInstr::getNotInstr(string arg1)
{
    return "    notl " << arg1 << "\n";
}

string IRInstr::getNegInstr(string arg1)
{
    return "    negl " << arg1 << "\n";
}

string IRInstr::getEqInstr(string arg1)
{
    return "    sete " << arg1 << "\n";
}

string IRInstr::getNeqInstr(string arg1)
{
    return "    setne " << arg1 << "\n";
}

string IRInstr::getLtInstr(string arg1)
{
    return "    setl " << arg1 << "\n";
}

string IRInstr::getLeInstr(string arg1)
{
    return "    setle " << arg1 << "\n";
}

string IRInstr::getGtInstr(string arg1)
{
    return "    setg " << arg1 << "\n";
}

string IRInstr::getGeInstr(string arg1)
{
    return "    setge " << arg1 << "\n";
}




