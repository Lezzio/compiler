#include <iostream>
#include <utility>

using namespace std;

#include "IR.h"

/**
 * @brief Construct a new CFG::CFG object
 * 
 * @param symbolTable : la table où sont stockés tous les symboles du programme à compiler
 * @param name : nom du cfg
 */
CFG::CFG(SymbolTable *symbolTable, string name)
        : functionName(std::move(name)), symbolTable(symbolTable), nextBBnumber(0), current_bb(nullptr), return_bb(nullptr),
          nextTmpVarNumber(0), highestLevel(0), breakBBname(""), continueBBname("") {
    levelHistory.push_back(0);
}

/**
 * @brief Destroy the CFG::CFG object
 * 
 */
CFG::~CFG() {
    for (BasicBlock *bb: bbs) {
        delete (bb);
    }
    delete (return_bb);
    //delete (symbolTable);
}

/**
 * @brief ajoute un basic bloc a la liste des basic blocs
 * 
 * @param bb : le basic bloc a ajouter
 */
void CFG::add_bb(BasicBlock *bb) {
    current_bb = bb;
    bbs.push_back(bb);
}

/**
 * @brief ajoute une instruction au basic bloc
 * 
 * @param op : l'operation a ajouter
 * @param t : le type du symbole
 * @param params : les parametres lies a l'instruction
 */
void CFG::addInstruction(IRInstr::Operation op, TypeSymbol t, vector<string> params) {
    current_bb->add_IRInstr(op, t, params);
}

/**
 * @brief genere les parties differentes pour x86 entre mac et windows
 * 
 * @param o : le stream de sortie
 */
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

/**
 * @brief genere les parties differentes pour arm entre mac et windows
 * 
 * @param o : le stream de sortie
 */
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

/**
 * @brief TODO
 * 
 * @param reg 
 * @param scope 
 * @return string 
 */
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

/**
 * @brief selectionne le bon regsitre en fonction de la position
 * 
 * @param position : la position
 * @return string : le registre a mettre dans l'assembleur
 */
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

/**
 * @brief genere le prologue pour l'architecture x86
 * 
 * @param o : le stream de sortie
 */
void CFG::gen_asm_prologue_x86(ostream &o) {
    o << "\t#prologue\n"
         "\tpushq\t\t%rbp\n"
         "\tmovq\t\t%rsp, %rbp\n";
}

/**
 * @brief : genere l'epilogue pour l'architecture x86
 * 
 * @param o : le stream de sortie
 */
void CFG::gen_asm_epilogue_x86(ostream &o) {
    cout << "\t#epilogue\n";
    if (get_var_type(functionName, &GLOBAL_SCOPE) == VOID) {
        cout << "\tnop\n";
    }
    //     "   popq %rbp\n"
    cout << "\tleave\n"
            "\tret\n";
}

/**
 * @brief genere le prologue pour l'architecture arm
 * 
 * @param o : le stream de sortie
 */
void CFG::gen_asm_prologue_ARM(ostream &o) {
    o << "\tpush\t{r7, lr}" << endl;
    o << "\tsub\tsp, sp, #space_needed" << endl;
    o << "\tadd\tr7, sp, #0" << endl;
    //TODO : gerer le sp et r7
}

/**
 * @brief : genere l'epilogue pour l'architecture arm
 * 
 * @param o : le stream de sortie
 */
void CFG::gen_asm_epilogue_ARM(ostream &o) {
    o << "\tadds\tr7, r7, #space_needed" << endl;
    o << "\tmov\tsp, r7" << endl;
    o << "\tpop\t{r7, pc}" << endl;
    //o << "\tldr\tr7, [sp], #4" << endl;
    //o << "\tbx\tlr" << endl;
}

// symbol symbolTable methods
/**
 * @brief Ajoute un symbole à la symbolTable
 * 
 * @param name : nom du symbole
 * @param t : type du symbole
 * @param stateSymbol : etat du symbole
 */
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

/**
 * @brief Ajoute un symbole de taille variable à la symbolTable
 * 
 * @param name : nom du symbole
 * @param t : type du symbole
 * @param stateSymbol : etat du symbole
 * @param size : la taille du symbole
 */
void CFG::add_to_symbol_table(const string &name, TypeSymbol t, StateSymbol stateSymbol, int size){
    symbolTable->addSymbol(name, getCurrentScope(), t, size, stateSymbol, false);
}

/**
 * @brief TODO
 * 
 * @param name 
 * @param position 
 * @param pScope 
 */
void CFG::setParametersPosition(const string &name, int position, Scope *pScope) {
    Symbol *symbol = symbolTable->lookupParameter(name, pScope);
    symbol->setIndex(position);
}

/**
 * @brief Crée une variable temporaire (!tmp+[incrementationNBvarTemporaires])
 * 
 * @param t : le type du symbole
 * @return string : le nom de la variable temporaire
 */
string CFG::create_new_tempvar(TypeSymbol t) {
    string name = "!tmp" + to_string(nextTmpVarNumber);
    nextTmpVarNumber++;

    symbolTable->addSymbol(name, getCurrentScope(), t, 0, ASSIGNED, false);
    return name;
}

/**
 * @brief recupere l'index (l'adresse) de la variable
 * 
 * @param name : le nom de la variable
 * @return int : l'adresse de la variable recuperee
 */
int CFG::get_var_index(string name) {
    Symbol *symbol = symbolTable->lookupSymbol(name, getCurrentScope());
    //TODO: check error

    return symbol->getIndex();
}

/**
 * @brief recupere dans la table des symboles le type de la variable
 * 
 * @param name : le nom de la variable
 * @param scope : le scope de la variable
 * @return TypeSymbol : le type de la variable trouvee
 */
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

/**
 * @brief TODO
 * 
 * @param name 
 * @param scope 
 */
void CFG::assignSymbol(const string& name, Scope *scope) {
    Symbol *symbolReturned = this->symbolTable->lookupSymbol(name, scope);
    this->symbolTable->assignSymbol(symbolReturned);
}

/**
 * @brief determine si le basic bloc est le premier de la liste ou non
 * 
 * @param bb : la basic bloc dont on cherche la position
 * @return true 
 * @return false 
 */
bool CFG::firstBB(BasicBlock *bb) {
    return (bb == bbs.front());
}

/**
 * @brief determine si une valeur est assignee au symbole
 * 
 * @param name : le nom du symbole
 * @param scope : le scope du symbole
 * @return true 
 * @return false 
 */
bool CFG::isSymbolAssigned(const string& name, Scope *scope) {
    Symbol *symbolReturned = this->symbolTable->lookupSymbol(name, scope);
    return (symbolReturned->getStateSymbol() == ASSIGNED);
}

/**
 * @brief ajoute un symbole à la table des symbole, s'il n'existe pas deja
 * 
 * @param name : le nom du symbole a jouter
 * @param scope : le scope du symbole
 */
void CFG::setReturnSymbol(const string& name, Scope *scope) {
    if (!symbolTable->doesSymbolExist(name, scope)) {
        symbolTable->addSymbol(name, scope, INT, 0, ASSIGNED, false);
    }
}

/**
 * @brief verifie l'existence du symbole dans la table des symboles
 * 
 * @param name : le nom du symbole
 * @param scope : le scope du symbole
 * @return true 
 * @return false 
 */
bool CFG::doesSymbolExist(const string& name, Scope *scope) {
    return symbolTable->doesSymbolExist(name, scope);
}

/**
 * @brief recupere l'offset associé à un symbole de la symbolTable
 * 
 * @return string : l'offset du symbole
 */
string CFG::getOffset() {
    return to_string(symbolTable->highestIndex);
}

/**
 * @brief recupere la symboleTable
 * 
 * @return SymbolTable* 
 */
SymbolTable *CFG::getSymbolTable() {
    return symbolTable;
}

/**
 * @brief TODO
 * 
 */
void CFG::enteringScope() {
    //cout << "Entering scope" << endl; debug
    int level = highestLevel++;
    //cout << "Level = " << level; debug
    levelHistory.push_back(level);
    current_bb->scope = getCurrentScope(); //Update the current basic block to be aligned with the new scope
}

/**
 * @brief TODO
 * 
 */
void CFG::exitingScope() {
    levelHistory.pop_back();
}

/**
 * @brief recupere le socpe actuel
 * 
 * @return Scope* 
 */
Scope *CFG::getCurrentScope() {
    int level = levelHistory.back();
    //cout << "| Current scope LEVEL is = " << level << " function name " + functionName << endl; debug
    auto *scope = new Scope(functionName);
    scope->levelContext = levelHistory; //Copy assign
    return scope;
}