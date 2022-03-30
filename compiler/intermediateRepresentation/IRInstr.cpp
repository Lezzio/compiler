#include <iostream>
using namespace std;

#include "IR.h"

void IRInstr::gen_asm_x86(ostream &o)
{
    string reg = "%eax";
    if(t == CHAR || t == INT8_T){
        reg = "%al";
    }

    switch (op) {
        case ldconst:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string value = this->params[1];
            o << getMovInstr(value, destination);
            break;}
        case ret:
            {
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string endBBname = bb->cfg->return_bb->label;
            o << getMovInstr(origin, reg);
            o << getMovInstr(reg, destination);
            o << getJumpInstr(endBBname);
            break;}
        case finret:
            {
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[0]);   
            o << getMovInstr(origin, reg);
            break;
            }
        case copy:
            {
            string destination;
            if(this->params[0].compare("param_reg") == 0){
                destination = this->bb->cfg->IR_reg_to_asm_param(stoi(this->params[2]));
            } else {
                if(!bb->cfg->isAssigneSymbol(this->params[0])){
                 this->bb->cfg->assignSymbol(this->params[0]);
                }
                destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            }
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            o << getMovInstr(origin, reg);
            o << getMovInstr(reg, destination);
            break;  }   
        case add:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getAddInstr(rvalue, reg);
            o << getMovInstr(reg, destination);}
            break;
        case sub:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue,reg);
            o << getSubInstr(rvalue, reg);
            o << getMovInstr(reg, destination);  }
            break;
        case mul:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getMulInstr(rvalue, reg);
            o << getMovInstr(reg, destination);   
            break;}
        case div:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getDivInstr(rvalue, reg);
            o << getMovInstr(reg, destination); 
            break;}
        case mod:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getDivInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;}
        case orbit:
           { string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getOrInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;}
        case andbit:
           { string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getAndInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;}
        case xorbit:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getXorInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break; }   
        case neg:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getNegInstr(reg);
            o << getMovInstr(reg, destination);
            break;   }
        case note:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getNotInstr(reg);
            o << getMovInstr("%edx", destination);
            break;      }               
        case rmem:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            o << getMovInstr(origin, reg);
            o << getMovInstr("("+reg+")", "%r10");
            o << getMovInstr("%r10", destination);
            break;}
        case wmem:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            o << getMovInstr(origin, reg);
            o << getMovInstr(destination, "%r10");
            o << getMovInstr("%r10", "("+reg+")");
            break;}
        case call:
            {
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string funcName = this->params[1];
            o << getCallInstr(funcName);
            if(t != VOID){
                 o << getMovInstr(reg, destination);
            }
            break;}
        case cmp_eq:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, reg);
            o << getCompInstr(rvalue, reg);
            o << getEqInstr("%al");
            if(reg != "%al"){
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);            
            break;}
        case cmp_neq:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getNeqInstr("%al");
            if(reg != "%al"){
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;}
        case cmp_lt:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getLtInstr("%al");
            if(reg != "%al"){
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;}
        case cmp_le:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getLeInstr("%al");
            if(reg != "%al"){
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;}
        case cmp_gt:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getGtInstr("%al");
            if(reg != "%al"){
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;}
        case cmp_ge:
            {string destination = this->bb->cfg->IR_reg_to_asm(this->params[0]);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1]);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2]);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getGeInstr("%al");
            if(reg != "%al"){
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;}
        case offset:
            {
            int value = stoi(this->params[0]);
            value = value / 16;
            value = value *16 +16; 
            string offset = "$"+to_string(value);   
            o << getSubInstr(offset, "%rsp");
            break;
            }    
        default:
            break;
    }
}

IRInstr::IRInstr(BasicBlock *bb_, Operation op, TypeSymbol t, vector<string> params)
    : bb(bb_), op(op), t(t), params(params)
{
}

string IRInstr::getMovInstr(string origin, string destination, TypeSymbol type)
{
    if(type == INT){
        string action = "   movl ";
        if(t == CHAR){
            action = "  movb ";
        }
        return action + origin +", " + destination + "\n";
    } else if (type ==INT8_T) {
        return "   movzbl " + origin +", " + destination + "\n";
    }
    return "";
}

string IRInstr::getAddInstr(string arg1, string arg2)
{
    string action = "   addl ";
    if(t == CHAR){
            action = "  addb ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getSubInstr(string arg1, string arg2)
{
    string action = "   subl ";
    if(t == CHAR){
            action = "  subb ";
    }
    if(t == INT64_T){
            action = "  subq ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getMulInstr(string arg1, string arg2)
{
    string action = "   imull ";
    if(t == CHAR){
            action = "  imulb ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getDivInstr(string arg1, string arg2)
{
    string action = "   idivl ";
    if(t == CHAR){
            action = "  idivb ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getOrInstr(string arg1, string arg2)
{
    string action = "   orl ";
    if(t == CHAR){
            action = "  orb ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getAndInstr(string arg1, string arg2)
{
    string action = "   andl ";
    if(t == CHAR){
            action = "  andb ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getXorInstr(string arg1, string arg2)
{
    string action = "   xorl ";
    if(t == CHAR){
            action = "  xorb ";
    }
    return "    xorl " + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getCompInstr(string arg1, string arg2)
{
    string action = "   cmpl ";
    if(t == CHAR){
            action = "  cmpb ";
    }
    return action + arg1 + ", " + arg2 + "\n";
}

string IRInstr::getNotInstr(string arg1)
{
    string action = "   notl ";
    if(t == CHAR){
            action = "  notb ";
    }
    return action + arg1 + "\n";
}

string IRInstr::getNegInstr(string arg1)
{
    string action = "   negl ";
    if(t == CHAR){
            action = "  negb ";
    }
    return action + arg1 + "\n";
}

string IRInstr::getEqInstr(string arg1)
{
    
    return "   sete " + arg1 + "\n";
}

string IRInstr::getNeqInstr(string arg1)
{
    return "   setne " + arg1 + "\n";
}

string IRInstr::getLtInstr(string arg1)
{
    return "   setl " + arg1 + "\n";
}

string IRInstr::getLeInstr(string arg1)
{
    return "   setle " + arg1 + "\n";
}

string IRInstr::getGtInstr(string arg1)
{
    return "    setg " + arg1 + "\n";
}

string IRInstr::getGeInstr(string arg1)
{
    return "    setge " + arg1 + "\n";
}

string IRInstr::getJumpInstr(string arg1){
    return "   jmp   " + arg1 + "\n";
}

string IRInstr::getCallInstr(string arg1){
    return "   call " + arg1 + "\n"; 
}



