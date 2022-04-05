#include <iostream>
#include <utility>

using namespace std;

#include "IR.h"

/**
 * @brief Method which generate/assemble in x86
 *
 * @param o the output stream
 */
void IRInstr::gen_asm_x86(ostream &o) {
    string reg = "%eax";
    if (t == CHAR || t == INT8_T) {
        reg = "%al";
    } else if(t== INT64_T){
        reg = "%rax";
    }
    //cout << "op = " << op << endl;
    switch (op) {
        case ldconst: {
            o << "\n";
            o << "\t#ldconst\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string value = this->params[1];
            o << getMovInstr(value, destination, t);
            break;
        }
        case ret: {
            o << "\n";
            o << "\t#ret\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string endBBname = bb->cfg->return_bb->label;
            o << getMovInstr(origin, reg);
            o << getMovInstr(reg, destination, t);
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
                destination = this->bb->cfg->IR_reg_to_asm_param(stoi(this->params[2]), t);
            } else {
             //   cout << "BRANCH 2" << endl;
             /*
                if (!bb->cfg->isSymbolAssigned(this->params[0], this->bb->scope)) {
                    //cout << "BRANCH 2 - assignSymbol" << endl; debug
                    this->bb->cfg->assignSymbol(this->params[0], this->bb->scope);
                }*/
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
                TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);
                o << getMovInstr(lvalue, reg, ltype);
            } 
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            o << getAddInstr(rvalue, reg);
            o << getMovInstr(reg, destination, t);
        }
            break;
        case sub: {
            o << "\n";
            o << "\t#sub\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string lvalue = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            string rvalue = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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

            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
            o << getXorInstr(rvalue, reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case neg: {
            o << "\n";
            o << "\t#neg\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string value = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);

            TypeSymbol type = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(value, reg, type);
            o << getNegInstr(reg);
            o << getMovInstr(reg, destination);
            break;
        }
        case not_: {
            o << "\n";
            o << "\t#not\n";
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string value = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);

            TypeSymbol type = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(value, reg, type);
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
            o << getMovInstr(origin, reg, INT64_T);
            o << getMovInstr("(" + reg + ")", "%r10", INT64_T);
            o << getMovInstr("%r10", destination, INT64_T);
            break;
        }
        case wmem: {
            o << "\n";
            o << "\t#wmem\n";
            /*
            if (!bb->cfg->isSymbolAssigned(this->params[0], this->bb->scope)) {
                    this->bb->cfg->assignSymbol(this->params[0], this->bb->scope);
            }*/
            string destination = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope);
            string origin = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope);
            o << getMovInstr(origin, reg, INT64_T);
            o << getMovInstr(destination, "%r10", INT64_T);
            o << getMovInstr("%r10", "(" + reg + ")", INT64_T);
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
            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
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
            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
            o << getCompInstr(rvalue, reg);
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
            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
            o << getCompInstr(rvalue, reg);
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
            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
            o << getCompInstr(rvalue, reg);
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
            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
            o << getCompInstr(rvalue, reg);
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
            TypeSymbol ltype = this->bb->cfg->get_var_type(this->params[1], this->bb->scope);

            o << getMovInstr(lvalue, reg, ltype);
            o << getCompInstr(rvalue, reg);
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
            TypeSymbol type_from = static_cast<TypeSymbol>(stoi(this->params[1]));
            string destination = source;
            if(this->params.size()==3){
                destination = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope);
            }
            o << getCastInstr(source, reg, type_from);
            o << getMovInstr(reg, destination, t);
            break;
        }
        default:
            break;
    }
}

/**
 * @brief Method which shrink asm x86 to ARM
 *
 * @param str_x86 the input string
 * @return string the output string
 */
string shrink_x86_to_ARM(string str_x86) {
    if (str_x86[0] == '$') { //constant à charger
        return str_x86.substr(1);
    } else {    //offset
        uint end = str_x86.find('(');
        return str_x86.substr(1, end - 1);
    }
}

/**
 * @brief Method which generate/assemble in ARM
 *
 * @param o the output stream
 */
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
            /*
            if (!bb->cfg->isSymbolAssigned(this->params[0], this->bb->scope)) {
                this->bb->cfg->assignSymbol(this->params[0], this->bb->scope);
            }*/
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
            o << getSubInstr("r2", "r3", ARM);
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
            string value = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            o << getMovInstr(value, "r3", t, ARM);
            o << getNegInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case not_: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string value = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            o << getMovInstr(value, "r3", t, ARM);
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

            TypeSymbol ltype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[1], this->bb->scope)->getTypeSymbol();
            TypeSymbol rtype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[2], this->bb->scope)->getTypeSymbol();

            o << getMovInstr(lvalue, "r2", ltype, ARM);
            o << getMovInstr(rvalue, "r3", rtype, ARM);
            o << getCompInstr("r2", "r3", ARM);
            o << getEqInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_neq: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));

            TypeSymbol ltype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[1], this->bb->scope)->getTypeSymbol();
            TypeSymbol rtype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[2], this->bb->scope)->getTypeSymbol();

            o << getMovInstr(lvalue, "r2", ltype, ARM);
            o << getMovInstr(rvalue, "r3", rtype, ARM);
            o << getCompInstr("r2", "r3", ARM);
            o << getNeqInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_lt: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));

            TypeSymbol ltype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[1], this->bb->scope)->getTypeSymbol();
            TypeSymbol rtype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[2], this->bb->scope)->getTypeSymbol();

            o << getMovInstr(lvalue, "r2", ltype, ARM);
            o << getMovInstr(rvalue, "r3", rtype, ARM);
            o << getCompInstr("r2", "r3", ARM);
            o << getLtInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_le: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));

            TypeSymbol ltype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[1], this->bb->scope)->getTypeSymbol();
            TypeSymbol rtype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[2], this->bb->scope)->getTypeSymbol();

            o << getMovInstr(lvalue, "r2", ltype, ARM);
            o << getMovInstr(rvalue, "r3", rtype, ARM);
            o << getCompInstr("r2", "r3", ARM);
            o << getLeInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_gt: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));

            TypeSymbol ltype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[1], this->bb->scope)->getTypeSymbol();
            TypeSymbol rtype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[2], this->bb->scope)->getTypeSymbol();

            o << getMovInstr(lvalue, "r2", ltype, ARM);
            o << getMovInstr(rvalue, "r3", rtype, ARM);
            o << getCompInstr("r2", "r3", ARM);
            o << getGtInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case cmp_ge: {
            string destination = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            string lvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope));
            string rvalue = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope));

            TypeSymbol ltype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[1], this->bb->scope)->getTypeSymbol();
            TypeSymbol rtype = this->bb->cfg->getSymbolTable()->lookupSymbol(this->params[2], this->bb->scope)->getTypeSymbol();

            o << getMovInstr(lvalue, "r2", ltype, ARM);
            o << getMovInstr(rvalue, "r3", rtype, ARM);
            o << getCompInstr("r2", "r3", ARM);
            o << getGeInstr("r3", ARM);
            o << getMovInstr("r3", destination, t, ARM);
            break;
        }
        case offset: {
            int value = stoi(this->params[0]);
            value = value / 4;
            value = value * 4 + 8;
            string offset = "#" + to_string(value);
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
        case cast : {
            /*
            o << "\n";
            o << "\t#cast\n";
            string source = shrink_x86_to_ARM(this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope));
            TypeSymbol type_from = static_cast<TypeSymbol>(stoi(this->params[1]));
            o << getCastInstr(source, "r3", type_from, true, ARM);
            o << getMovInstr("r3", source, type_from, ARM);
            break;*/
        }

        default:
            break;
    }
}

/**
 * @brief Construct a new IRInstr::IRInstr object
 *
 * @param bb_
 * @param op
 * @param t
 * @param params
 */
IRInstr::IRInstr(BasicBlock *bb_, Operation op, TypeSymbol t, vector<string> params)
        : bb(bb_), op(op), t(t), params(std::move(params)) {
}

/******************************************* Instructions ******************************************************/
/**
 * @brief Get the mov instruction asm code
 *
 * @param origine : origin register name
 * @param destination : destination register name
 * @param arch : architecture used x86 or ARM
 * @param type : type of the symbol
 * @param cst : bool const or not
 * @return string
 */
string IRInstr::getCastInstr(const string &origine, const string &destination, TypeSymbol type_from, bool sign, Arch arch)
{
    // t := type_to
    string from, to, signed_;
    if (arch == x86) {
        if(type_from == CHAR || type_from == INT8_T){
            from = "b";
        } else if (type_from == INT){
            from = "l";
        } else if (type_from == INT64_T){
            from = "q";
        } else {
            cerr << "Invalid type_from : " << type_from << endl;
        }

        if(t == CHAR || t == INT8_T){
            to = "b";
        } else if (t == INT){
            to = "l";
        } else if (t == INT64_T){
            to = "q";
        } else {
            cerr << "Invalid type_to : " << t << endl;
        }


        if (sign){
            signed_ = "s";
        } else {
            signed_ = "z";
        }

        if ((from == "l" && to == "b") || (from == "q" && from != to)){  //downcast
            from = "";
            to ="";
            signed_ = "";
        }

        return "\tmov" + signed_ + from + to + "\t\t" + origine + ", " + destination + "\n";
    } else {    //ARM
        string type_b, action;

        if (t == CHAR || t == INT8_T) {
            type_b = "b";
        }
        if (destination[0] == 'r' && origine[0] != 'r') {
            action = "\tldr" + type_b + "\t";
        }
        return action + destination + ", [r7, #" + origine + "]\n";
    }
    return "";
}


string IRInstr::getMovInstr(const string &origine, const string &destination, TypeSymbol type, Arch arch, bool cst) {
    if (arch == x86) {
        string from, to, signed_;


        if(type == CHAR || type == INT8_T){
            from = "b";
        } else if (type == INT){
            from = "l";
        } else {
            //from = "q";
        }

        if(t == CHAR || t == INT8_T){
            to = "b";
        } else if (t == INT){
            to = "l";
        } else {
            to = "q";
        }

        if (from == to || (from == "l" && to == "b") || (from == "q" && from != to)){  //same type or downcast
            from = "";
        }

        if(to != "" && from != ""){
            signed_ = "z";
        }
         if(to == "q" && from != ""){
             signed_ = "s";
         }

         if (to == "q" && from == ""){
             signed_ = "";
         }

        return "\tmov" + signed_ + from + to + "\t\t" + origine + ", " + destination + "\n";

        if (type == INT) {
            string action = "\tmovl\t\t";
            if (t == CHAR) {
                action = "\tmovb\t\t";
            }
            if (t == INT64_T) {
                action = "\tmovq\t\t";
            }
            return action + origine + ", " + destination + "\n";
        } else if (type == INT8_T) {
            return "\tmovzbl\t\t" + origine + ", " + destination + "\n";
        } else {
            return "\tmovq\t\t" + origine + ", " + destination + "\n";
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

/**
 * @brief Get the add instruction asm code
 *
 * @param arg1 : register content to add
 * @param arg2 : register in which the content is added
 * @param arch : architecture used x86 or ARM
 * @param dest : destination register (ARM)
 * @return string
 */
string IRInstr::getAddInstr(const string &arg1, const string &arg2, Arch arch, const string &dest) {
    if (arch == x86) {
        string action = "\taddl\t\t";
        if (t == CHAR) {
            action = "\taddb\t\t";
        }
        if (t == INT64_T) {
            action = "\taddq\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tadds\t" + dest + ", ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

/**
 * @brief Get the substraction instruction asm code
 *
 * @param arg1 : register content to substract
 * @param arg2 : register in which the content is substracted
 * @param arch : architecture used x86 or ARM
 * @param dest : destination register (ARM)
 * @return string
 */
string IRInstr::getSubInstr(const string &arg1, const string &arg2, Arch arch, const string &dest) {
    if (arch == x86) {
        string action = "\tsubl\t\t";
        if (t == CHAR) {
            action = "\tsubb\t\t";
        }
        if (t == INT64_T) {
            action = "\tsubq\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tsubs\t" + dest + ", ";
        return action + arg1 + ", " + arg2 + "\n";
    }
}

/**
 * @brief Get the multiplication instruction asm code
 *
 * @param arg1 : register content to multiply
 * @param arg2 : register in which the content is multiplied
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getMulInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "\timull\t\t";
        if (t == CHAR) {
            action = "\timulb\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tmul\tr3, ";
        return action + arg1 + ", " + arg2 + "\n";
    }
}

/**
 * @brief Get the division instruction asm code
 *
 * @param arg1 : register content to divide
 * @param arg2 : register in which the content is divided
 * @param arch : architecture used x86 or ARM
 * @param modulo
 * @return string
 */
string IRInstr::getDivInstr(const string &arg1, const string &arg2, Arch arch, bool modulo) {
    if (arch == x86) {
        string action = "\tidivl\t\t";
        if (t == CHAR) {
            action = "\tidivb\t\t";
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

/**
 * @brief Get the or instruction asm code
 *
 * @param arg1 : register which will contain the bool result
 * @param arg2 : register bool operation result
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getOrInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "\torl\t\t";
        if (t == CHAR) {
            action = "\torb\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\torrs r3, ";
        return action + arg1 + ", " + arg2 + "\n";
    }
}

/**
 * @brief Get the and instruction asm code
 *
 * @param arg1 : register which will contain the bool result
 * @param arg2 : register bool operation result
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getAndInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "\tandl\t\t";
        if (t == CHAR) {
            action = "\tandb\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tands r3, ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

/**
 * @brief
 *
 * @param arg1
 * @param arg2
 * @param arch
 * @return string
 */
string IRInstr::getXorInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "\txorl\t\t";
        if (t == CHAR) {
            action = "\txorb\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\teors r3, ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

/**
 * @brief Get the xor instruction asm code
 *
 * @param arg1 : register which will contain the bool result
 * @param arg2 : register bool operation result
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getCompInstr(const string &arg1, const string &arg2, Arch arch) {
    if (arch == x86) {
        string action = "\tcmpl\t\t";
        if (t == CHAR) {
            action = "\tcmpb\t\t";
        }
        return action + arg1 + ", " + arg2 + "\n";
    } else {
        string action = "\tcmp ";
        return action + arg1 + ", " + arg2 + "\n";
        //return string(__FUNCTION__) + " not implemented for ARM\n";
    }
}

/**
 * @brief Get the not instruction asm code
 *
 * @param arg1 : register which will contain the bool result
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getNotInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        string action = "\tnotl\t\t";
        if (t == CHAR) {
            action = "\tnotb\t\t";
        }
        return action + arg1 + "\n";
    } else {
        string comp = getCompInstr(arg1, "#0", arch);   //on compare avec 0
        string eq = getEqInstr(arg1, arch);    //on regarde si c'est égal à 0 ou pas
        return comp + eq;
    }
}

/**
 * @brief Get the neg instruction asm code
 *
 * @param arg1 : register which will contain the result
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getNegInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        string action = "\tnegl\t\t";
        if (t == CHAR) {
            action = "\tnegb\t\t";
        }
        return action + arg1 + "\n";
    } else {
        string action = "\trsbs r3, ";
        return action + arg1 + ", #0\n";
    }
}

/**
 * @brief Get the eq instruction asm code
 *
 * @param arg1 : register which will contain the flag result
 * @param arch : architecture used x86 or ARM
 */
string IRInstr::getEqInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "\tsete\t\t" + arg1 + "\n";
    } else {
        string action = "\tite eq\n";
        string action_true = "\tmoveq\t" + arg1 + ", #1\n";
        string action_false = "\tmovne\t" + arg1 + ", #0\n";
        return action + action_true + action_false + "\tuxtb\tr3, r3\n";
    }
}

/**
 * @brief Get the neq instruction asm code
 *
 * @param arg1 : register which will contain the flag result
 * @param arch : architecture used x86 or ARM
 */
string IRInstr::getNeqInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "\tsetne\t\t" + arg1 + "\n";
    } else {
        string ite = "\tite ne\n";
        string action_true = "\tmovne\t" + arg1 + ", #1\n";
        string action_false = "\tmoveq\t" + arg1 + ", #0\n";
        return ite + action_true + action_false + "\tuxtb\tr3, r3\n";
    }
}

/**
 * @brief Get the Lt instruction asm code
 *
 * @param arg1 : register which will contain the flag result
 * @param arch : architecture used x86 or ARM
 */
string IRInstr::getLtInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "\tsetl\t\t" + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "cc";
            cond_inv = "cs";
        } else {
            cond = "lt";
            cond_inv = "ge";
        }

        string ite = "\tite " + cond + "\n";
        string action_true = "\tmov" + cond + " " + arg1 + ", #1\n";
        string action_false = "\tmov" + cond_inv + " " + arg1 + ", #0\n";
        return ite + action_true + action_false + "\tuxtb\tr3, r3\n";
    }
}

/**
 * @brief Get the Le instruction asm code
 *
 * @param arg1 : register which will contain the flag result
 * @param arch : architecture used x86 or ARM
 */
string IRInstr::getLeInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "\tsetle\t\t" + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "ls";
            cond_inv = "hi";
        } else {
            cond = "le";
            cond_inv = "gt";
        }

        string ite = "\tite " + cond + "\n";
        string action_true = "\tmov" + cond + " " + arg1 + ", #1\n";
        string action_false = "\tmov" + cond_inv + " " + arg1 + ", #0\n";
        return ite + action_true + action_false + "\tuxtb\tr3, r3\n";
    }
}

/**
 * @brief Get the Gt instruction asm code
 *
 * @param arg1 : register which will contain the flag result
 * @param arch : architecture used x86 or ARM
 */
string IRInstr::getGtInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "\tsetg\t\t" + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "hi";
            cond_inv = "ls";
        } else {
            cond = "gt";
            cond_inv = "le";
        }

        string ite = "\tite " + cond + "\n";
        string action_true = "\tmov" + cond + " " + arg1 + ", #1\n";
        string action_false = "\tmov" + cond_inv + " " + arg1 + ", #0\n";
        return ite + action_true + action_false + "\tuxtb\tr3, r3\n";
    }
}

/**
 * @brief Get the Ge instruction asm code
 *
 * @param arg1 : register which will contain the flag result
 * @param arch : architecture used x86 or ARM
 */
string IRInstr::getGeInstr(const string &arg1, Arch arch) {
    if (arch == x86) {
        return "\tsetge\t\t" + arg1 + "\n";
    } else {
        string cond, cond_inv;

        if (t == CHAR) {
            cond = "cs";
            cond_inv = "cc";
        } else {
            cond = "ge";
            cond_inv = "lt";
        }

        string ite = "\tite " + cond + "\n";
        string action_true = "\tmov" + cond + " " + arg1 + ", #1\n";
        string action_false = "\tmov" + cond_inv + " " + arg1 + ", #0\n";
        return ite + action_true + action_false + "\tuxtb\tr3, r3\n";
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

/**
 * @brief Get the jump instruction asm code
 *
 * @param arg1 : register to where the jump will be done
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getJumpInstr(const string &arg1, Arch arch) {
    return "\tjmp\t\t\t" + arg1 + "\n";
}

/**
 * @brief Get the call instruction asm code
 *
 * @param arg1 : register called
 * @param arch : architecture used x86 or ARM
 * @return string
 */
string IRInstr::getCallInstr(const string &arg1, Arch arch) {
    return "\tcall\t\t" + arg1 + "\n";
}
