#include <iostream>
#include <utility>

using namespace std;

#include "IR.h"

void IRInstr::gen_asm_x86(ostream &o) {
    string reg = "%eax";
    if (t == CHAR || t == INT8_T) {
        reg = "%al";
    } else if(t== INT64_T){
        reg = "%rax";
    }
<<<<<<< HEAD
    //cout << "op = " << op << endl;
    switch (op) {
        case ldconst: {
            o << "\n";
            o << "\t#ldconst\n";
=======
    //cout << "op = " << op << endl; debug
    switch (op) {
        case ldconst: {
            //cout << "BB scope = " << this->bb->scope << endl; debug
>>>>>>> 31890d3689b716173009da9eab3a21c7624eb27b
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string value = this->params[1];
            o << getMovInstr(value, destination);
            break;
        }
        case ret: {
            o << "\n";
            o << "\t#ret\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string endBBname = bb->cfg->return_bb->label;
            o << getMovInstr(origin, reg);
            o << getMovInstr(reg, destination);
            o << getJumpInstr(endBBname);
            break;
        }
        case finret: {
            o << "\n";
            o << "\t#finret\n";
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            o << getMovInstr(origin, reg);
            break;
        }
        case copy: {
            o << "\n";
            o << "\t#copy\n";
            //cout << "copy operation" << endl;
            string destination;
            if (this->params[0] == "param_reg") {
             //  cout << "BRANCH 1" << endl;
                destination = this->bb->cfg->IR_reg_to_asm_param(stoi(this->params[2]));
            } else {
             //   cout << "BRANCH 2" << endl;
                if (!bb->cfg->isSymbolAssigned(this->params[0], this->bb->scope)) {
                    //cout << "BRANCH 2 - assignSymbol" << endl; debug
                    this->bb->cfg->assignSymbol(this->params[0], this->bb->scope);
                }
                //cout << "BRANCH 2 - destination" << endl; debug
                destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            }
            //cout << "END ELIF" << endl; debug
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            o << getMovInstr(origin, reg);
            o << getMovInstr(reg, destination);
            //cout << "END COPY" << endl; debug
            break;
        }
        case add: {
            o << "\n";
            o << "\t#add\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue;
            if(this->params[1].compare("%rbp")==0){
                lvalue = this->params[1];
                o << getMovInstr(lvalue, "%rax", INT64_T);
            } else {
                lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
                o << getMovInstr(lvalue, reg);
            } 
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getAddInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
        }
            break;
        case sub: {
            o << "\n";
            o << "\t#sub\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getSubInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
        }
            break;
        case mul: {
            o << "\n";
            o << "\t#mul\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getMulInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case div: {
            o << "\n";
            o << "\t#div\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getDivInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case mod: {
            o << "\n";
            o << "\t#mod\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getDivInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case orbit: {
            o << "\n";
            o << "\t#orbit\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getOrInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case andbit: {
            o << "\n";
            o << "\t#andbit\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getAndInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case xorbit: {
            o << "\n";
            o << "\t#xorbit\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getXorInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case neg: {
            o << "\n";
            o << "\t#neg\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getNegInstr(reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case not_: {
            o << "\n";
            o << "\t#not\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getNotInstr(reg);
            o << getMovInstr("%edx", destination);
            break;
        }
        case rmem: {
            o << "\n";
            o << "\t#rmem\n";
            if (!bb->cfg->isSymbolAssigned(this->params[1], this->bb->scope)) {
                    cerr << "Memory space not allocated" << endl;
                    exit(1);
            }
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            cout << "#readMem" << endl;
            o << getMovInstr(origin, reg);
            o << getMovInstr("(" + reg + ")", "%r10");
            o << getMovInstr("%r10", destination);
            break;
        }
        case wmem: {
            o << "\n";
            o << "\t#wmem\n";
            if (!bb->cfg->isSymbolAssigned(this->params[0], this->bb->scope)) {
                    this->bb->cfg->assignSymbol(this->params[0]);
            }
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            o << getMovInstr(origin, reg);
            o << getMovInstr(destination, "%r10");
            o << getMovInstr("%r10", "(" + reg + ")");
            break;
        }
        case call: {
            o << "\n";
            o << "\t#call\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string funcName = this->params[1];
            o << getCallInstr(funcName);
            if (t != VOID) {
                o << getMovInstr(reg, destination);
            }
            break;
        }
        case cmp_eq: {
            o << "\n";
            o << "\t#cmp_eq\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, reg);
            o << getCompInstr(rvalue, reg);
            o << getEqInstr("%al");
            if (reg != "%al") {
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;
        }
        case cmp_neq: {
            o << "\n";
            o << "\t#cmp_neq\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getNeqInstr("%al");
            if (reg != "%al") {
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;
        }
        case cmp_lt: {
            o << "\n";
            o << "\t#cmp_lt\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getLtInstr("%al");
            if (reg != "%al") {
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;
        }
        case cmp_le: {
            o << "\n";
            o << "\t#cmp_le\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getLeInstr("%al");
            if (reg != "%al") {
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;
        }
        case cmp_gt: {
            o << "\n";
            o << "\t#cmp_gt\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getGtInstr("%al");
            if (reg != "%al") {
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;
        }
        case cmp_ge: {
            o << "\n";
            o << "\t#cmp_ge\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getMovInstr(lvalue, "%eax");
            o << getCompInstr(rvalue, "%eax");
            o << getGeInstr("%al");
            if (reg != "%al") {
                o << getMovInstr("%al", reg, INT8_T);
            }
            o << getMovInstr(reg, destination);
            break;}
        case jmp:
            {
            o << "\n";
            o << "\t#jmp\n";
            o << getJumpInstr(this->params[0]);    
            break;    
            }    
        case offset:
            {
            o << "\n";
            o << "\t#offset\n";
            int value = stoi(this->params[0]);
            value = value / 16;
            value = value * 16 + 16;
            string offset = "$" + to_string(value);
            o << getSubInstr(offset, "%rsp");
            break;
        }
        case cast : {
            o << "\n";
            o << "\t#cast\n";
            string source = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            o << getCastInstr(source, reg);
            o << getMovInstr(reg, source);
        }
        default:
            break;
    }
}

string shrink_x86_to_ARM(string str_x86) {
    if (str_x86[0] == '$') { //constant à charger
        return str_x86.substr(1);
    } else {    //offset
        uint end = str_x86.find('(');
        return str_x86.substr(1, end - 1);
    }
}

void IRInstr::gen_asm_ARM(ostream &o) {

    switch (op) {
        case ldconst: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string value = shrink_x86_to_ARM(this->params[1]);
            if (stoi(value) > 255) { //on ne peut pas faire tenir la constante sur plus de 8 bits
                cerr << "The value " << value << " is too big for ARM " << endl;
                break;
            }
            o << getMovInstr(value, "r3", t, ARM, true);
            o << getMovInstr("r3", destination, t, ARM, true);
            break;
        }
        case ret: {
            string origin = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string endBBname = bb->cfg->return_bb->label;
            o << getMovInstr(origin, "r3", t, ARM);
            o << getMovInstr("r3", "r0", t, ARM);
            //jump to epilogue
            break;
        }
        case finret:    //TODO
        {
            string origin = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            //o << getMovInstr(origin, reg);
            break;
        }
        case copy: {
            if (!bb->cfg->isSymbolAssigned(this->params[0], this->bb->scope)) {
                this->bb->cfg->assignSymbol(this->params[0], this->bb->scope);
            }
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string origin = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            o << getMovInstr(origin, "r3", t, ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case add: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getAddInstr("r3", "r2", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case sub: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getSubInstr("r3", "r2", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case mul: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getMulInstr("r3", "r2", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case div: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getDivInstr(lvalue, rvalue, ARM, false);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case mod: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getDivInstr(lvalue, rvalue, ARM, true);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case orbit: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getOrInstr("r3", "r2", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case andbit: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getAndInstr("r3", "r2", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case xorbit: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getXorInstr("r3", "r2", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case neg: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getNegInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case not_: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(rvalue, "r3", t, ARM);
            o << getNotInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case rmem: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string origin = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            //TODO : rmem
            break;
        }
        case wmem: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string origin = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            //TODO : wmem
            break;
        }
        case call: {//TODO:
            break;
        }
        case cmp_eq: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getCompInstr(rvalue, "r3", ARM);
            o << getEqInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_neq: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getCompInstr(rvalue, "r3", ARM);
            o << getNeqInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_lt: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getCompInstr(rvalue, "r3", ARM);
            o << getLtInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_le: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getCompInstr(rvalue, "r3", ARM);
            o << getLeInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_gt: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getCompInstr(rvalue, "r3", ARM);
            o << getGtInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_ge: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));
            o << getMovInstr(lvalue, "r2", t, ARM);
            o << getCompInstr(rvalue, "r3", ARM);
            o << getGeInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case offset: {
            int value = stoi(this->params[0]);
            value = value / 4;
            value = value * 4 + 8;
            string offset = "_" + to_string(value);
            if (this->params[1] == "start") {
                o << getSubInstr("sp", offset, ARM, "sp");
                o << getAddInstr("sp", "#0", ARM, "r7");
            } else if (this->params[1] == "end") {
                o << getAddInstr("r7", offset, ARM, "r7");
                o << getMovInstr("r7", "sp", t, ARM);
            } else {
                cerr << "Error in func : " << __FUNCTION__ << " status should be 'start' or 'end' instead of : "
                     << this->params[1] << endl;
            }


            break;
        }
        default:
            break;
    }
}

IRInstr::IRInstr(BasicBlock *bb_, Operation op, TypeSymbol t, vector<string> params)
        : bb(bb_), op(op), t(t), params(std::move(params)) {
}

string IRInstr::getCastInstr(const string &origine, const string &destination, Arch arch)
{
    if (arch == x86) {
        if(t == INT64_T){
            return "    movzbl " + origine + ", " + destination + "\n";
        }
    }
    return "";
}


/** Instructions */
string IRInstr::getMovInstr(const string &origine, const string &destination, TypeSymbol type, Arch arch, bool cst) {
    if (arch == x86) {
        if (type == INT) {
            string action = "   movl ";
            if (t == CHAR) {
                action = "  movb ";
            }
            if (t == INT64_T) {
                action = "  movq ";
            }
            return action + origine + ", " + destination + "\n";
        } else if (type == INT8_T) {
            return "    movzbl " + origine + ", " + destination + "\n";
        } else {
            return "    movq " + origine + ", " + destination + "\n";
        }
    } else {
        string action, type_b;

        if (type == CHAR || type == INT8_T) {
            type_b = "b";
        }
        if (destination[0] == 'r' && origine[0] != 'r') {   //from stack to reg

            if (cst) { //load cst to reg
                action = "\tmovs\t";
                return action + destination + ", #" + origine + "\n";
            } else {  //from stack to reg
                action = "\tldr" + type_b + "\t";
            }

        } else if (destination[0] == 's' && origine[0] == 'r') { //from reg to sp
            //mov	sp, r7
            return "\tmov\tsp, " + origine + "\n";
        } else if (destination[0] == 'r' && origine[0] == 'r') { // from reg to reg
            action = "\tmov\t";
            return action + destination + ", " + origine + "\n";
        } else if (destination[0] == 's' && origine[0] == 'r') { //from reg to sp
            //mov	sp, r7
            return "\tmov\tsp, " + origine + "\n";
        } else if (destination[0] != 'r' && origine[0] == 'r') { //from reg to stack
            action = "\tstr" + type_b + "\t";
            return action + origine + ", [r7, #" + destination + "]\n";
        }
        return action + destination + ", [r7, #" + origine + "]\n";
    }
}

string IRInstr::getAddInstr(const string &arg1, const string &arg2, Arch arch, const string &dest) {
    if (arch == x86) {
        string action = "   addl ";
        if (t == CHAR) {
            action = "  addb ";
        }
        if (t == INT64_T) {
            action = "  addq ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tadds\t" + dest + ", ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}


string IRInstr::getSubInstr(const string &arg1, const string &arg2, Arch arch, const string &dest) {
    if (arch == x86) {
        string action = "   subl ";
        if (t == CHAR) {
            action = "  subb ";
        }
        if (t == INT64_T) {
            action = "  subq ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tsubs\t" + dest + ", ";
        return action + arg1 + ", " + arg2 + "\n";
    }
}

string IRInstr::getMulInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "   imull ";
        if (t == CHAR) {
            action = "  imulb ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tmul\tr3, ";
        return action + arg1 + ", " + arg2 + "\n";
    }
}

string IRInstr::getDivInstr(const string &arg1, const string &arg2, Arch arch, bool modulo) {
    if (arch == x86) {
        string action = "   idivl ";
        if (t == CHAR) {
            action = "  idivb ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action, lvalue, rvalue, result;
        if (modulo) {  //modulo
            lvalue = getMovInstr(arg1, "r3", t, ARM);

            string load_r0 = getMovInstr("r3", "r0", t, ARM);
            if (t == CHAR) {
                rvalue = getMovInstr(arg2, "r2", t, ARM) + getMovInstr("r2", "r1", t, ARM);
                action = "\tbl\t__aeabi_udivmod(PLT)\n";
            } else {
                rvalue = getMovInstr(arg2, "r1", t, ARM);
                action = "\tbl\t__aeabi_idivmod(PLT)\n";
            }

            result = getMovInstr("r1", "r3", t, ARM);
            return lvalue + rvalue + load_r0 + action + result + "\tuxtb\tr3, r3\n";
        } else {    //division
            if (t == CHAR) {
                lvalue = getMovInstr(arg1, "r3", t, ARM);
                rvalue = getMovInstr(arg2, "r2", t, ARM) + getMovInstr("r2", "r1", t, ARM);
                string load_r0 = getMovInstr("r3", "r0", t, ARM);
                action = "\tbl\t__aeabi_uidiv(PLT)\n";
                result = getMovInstr("r0", "r3", t, ARM);
                return lvalue + rvalue + load_r0 + action + result + "\tuxtb\tr3, r3\n";
            } else {
                rvalue = getMovInstr(arg2, "r1", t, ARM);
                lvalue = getMovInstr(arg1, "r0", t, ARM);
                action = "\tbl\t__aeabi_idiv(PLT)\n";
                result = getMovInstr("r0", "r3", t, ARM);
                return rvalue + lvalue + action + result;
            }
        }
    }
}

/**
 *  ldr	r3, [r7, #4]
	ldr	r1, [r7, #8]
	mov	r0, r3
	bl	__aeabi_idivmod(PLT)
	mov	r3, r1
 */
string IRInstr::getOrInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "   orl ";
        if (t == CHAR) {
            action = "  orb ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "   orrs r3, ";
        return action + arg1 + ", " + arg2 + "\n";
    }
}

string IRInstr::getAndInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "   andl ";
        if (t == CHAR) {
            action = "  andb ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "   ands r3, ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

string IRInstr::getXorInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "   xorl ";
        if (t == CHAR) {
            action = "  xorb ";
        }
        return "    xorl " + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "   eors r3, ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

string IRInstr::getCompInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "   cmpl ";
        if (t == CHAR) {
            action = "  cmpb ";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "   cmp ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

string IRInstr::getNotInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        string action = "   notl ";
        if (t == CHAR) {
            action = "  notb ";
        }
        return action + arg1 + "\n";
    } else {
        string comp = getCompInstr(arg1, "#0", arch);   //on compare avec 0
        string eq = getEqInstr(arg1, arch);    //on regarde si c'est égal à 0 ou pas
        return comp + eq;
    }
}

string IRInstr::getNegInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        string action = "   negl ";
        if (t == CHAR) {
            action = "  negb ";
        }
        return action + arg1 + "\n";
    } else {
        string action = "   rsbs r3, ";
        return action + arg1 + ", #0\n";
    }
}

string IRInstr::getEqInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "    sete " + arg1 + "\n";
    } else {
        string action = "   ite eq\n";
        string action_true = "  moveq\t" + arg1 + ", #1\n";
        string action_false = " movne\t" + arg1 + ", #0\n";
        return action + action_true + action_false + "uxtb\tr3, r3";
    }
}

string IRInstr::getNeqInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "    setne " + arg1 + "\n";
    } else {
        string ite = "   ite ne\n";
        string action_true = " movne\t" + arg1 + ", #1\n";
        string action_false = "  moveq\t" + arg1 + ", #0\n";
        return ite + action_true + action_false + "uxtb\tr3, r3";
    }
}

string IRInstr::getLtInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "    setl " + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "cc";
            cond_inv = "cs";
        } else {
            cond = "lt";
            cond_inv = "ge";
        }

        string ite = "   ite " + cond + "\n";
        string action_true = "  mov" + cond + " " + arg1 + ", #1\n";
        string action_false = "  mov" + cond_inv + " " + arg1 + ", #1\n";
        return ite + action_true + action_false + "uxtb\tr3, r3";
    }
}

string IRInstr::getLeInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "    setle " + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "ls";
            cond_inv = "hi";
        } else {
            cond = "le";
            cond_inv = "gt";
        }

        string ite = "   ite " + cond + "\n";
        string action_true = "  mov" + cond + " " + arg1 + ", #1\n";
        string action_false = "  mov" + cond_inv + " " + arg1 + ", #1\n";
        return ite + action_true + action_false + "uxtb\tr3, r3";
    }
}

string IRInstr::getGtInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "    setg " + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "hi";
            cond_inv = "ls";
        } else {
            cond = "gt";
            cond_inv = "le";
        }

        string ite = "   ite " + cond + "\n";
        string action_true = "  mov" + cond + " " + arg1 + ", #1\n";
        string action_false = "  mov" + cond_inv + " " + arg1 + ", #1\n";
        return ite + action_true + action_false + "uxtb\tr3, r3";
    }
}

string IRInstr::getGeInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "    setge " + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "cs";
            cond_inv = "cc";
        } else {
            cond = "ge";
            cond_inv = "lt";
        }

        string ite = "   ite " + cond + "\n";
        string action_true = "  mov" + cond + " " + arg1 + ", #1\n";
        string action_false = "  mov" + cond_inv + " " + arg1 + ", #1\n";
        return ite + action_true + action_false + "uxtb\tr3, r3";
    }
}

/**
 *  strb	r3, [r7, #3]
	ldrb	r2, [r7, #2]
 */

/**
 *
 * Fonctionnement de ARM:
 *
 * Prologue :
 * push {r7}
 * On enleve à sp l'espace requis pour la fonction
 * On met sp + #0 dans r7
 *
 * Pour les déclarations :
 * On met la val ds le registre r3 (ça peut etre une const ou la valeur d'une variable en mémoire)
 * On stocke r3 en mémoire
 * Et on continue pour la déclaration des autres variables
 *
 * Pour une opération binaire :
 * On charge la partie gauche dans r2
 * On charge la partie droite dans r3
 * On met le resultat dans r3
 * On stocke r3 dans la mémoire
 *
 * Pour une opération unaire :
 * On charge la variable de la mémoire dans r3
 * On met le resultat dans r3
 * On stocke r3 dans la mémoire
 *
 *
 * Epilogue :
 * On charge dans r3 la valeur à retouner
 * On move r3 dans r0 car c'est la valeur de retour
 * On met à jour r7 en lui ajoutant l'espace de la fonction
 * On mov r7 dans sp
 */


string IRInstr::getJumpInstr(const string &arg1, Arch arch) {
    return "   jmp   " + arg1 + "\n";
}

string IRInstr::getCallInstr(const string &arg1, Arch arch) {
    return "   call " + arg1 + "\n";
}
