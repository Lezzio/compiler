#include "ast/ast.h"
#include "AstVisitor.h"
#include <iostream>

using namespace std;
using namespace antlr4;

/**
 * @brief Visit an axiom
 * 
 * @param ctx : context of the axiom
 * @return antlrcpp::Any 
 */
antlrcpp::Any AstVisitor::visitAxiom(ifccParser::AxiomContext *ctx) {
    //throw antlr4::RecognitionException("okokok", recognizer, recognizer->getInputStream(), recognizer->getContext(), recognizer->getCurrentToken());
    return visit(ctx->prog());
}

/**
 * @brief Visit each fonctions of a program and create the object program
 * 
 * @param context : context of the program
 * @return : a pointer on the program
 */
antlrcpp::Any AstVisitor::visitProg(ifccParser::ProgContext *context) {
    Prog *prog = new Prog();
    for (const auto f : context->function()) {
        Function *function = (Function *) visit(f);
        prog->addFunction(function);
    }
    return prog;
}

/**
 * @brief : Visit a fonction: read the name of the function and the type it returns
 * 
 * @param context : the context of the function
 * @return : a pointer on the function
 */
antlrcpp::Any AstVisitor::visitFunction(ifccParser::FunctionContext *context) {
    string name = context->IDENT()->getText();
  // string functionName = "main";
  //  string functionName = (string) visit(context->nameFunction()).as<string>();
    string res;
    TypeSymbol t = INT;
    if(context->type() != nullptr) {
        res = (string) visit(context->type()).as<string>();   
        if (res == "char") {
            t = CHAR;
        }
    } else {
        t = VOID;
    }

    Parameters * parameters = nullptr;
    if(context->parameters()!=nullptr) {
        parameters = (Parameters *) visit(context->parameters());
    }

    auto line = context->IDENT()->getSymbol()->getLine();
    Block * block = (Block *) visit(context->block());
    auto * function = new Function(name, t, parameters, block, line);
    return (Function * ) function;
}

/**
 * @brief Visit each statement of a block
 * 
 * @param context : context of the block
 * @return : a pointer on the block
 */
antlrcpp::Any AstVisitor::visitBlock(ifccParser::BlockContext *context) {
    auto *block = new Block();
    for (const auto s : context->statement()) {
        Statement *statement = (Statement *) visit(s);
        block->addStatement(statement);
    }
    return (Block *) block;
}

/**
 * @brief visit a statement created by a declaration
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement1(ifccParser::Statement1Context *context) {
    return (Statement *) visit(context->declaration());
}

/**
 * @brief visit a statement created by an affectation
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement2(ifccParser::Statement2Context *context) {
    return (Statement *) visit(context->affectation());
}

/**
 * @brief visit a statement created by a return
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement3(ifccParser::Statement3Context *context) {
    return (Statement *) visit(context->retcode());
}

/**
 * @brief visit a statement created by a if block
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement4(ifccParser::Statement4Context *context)
{
    return (Statement *)visit(context->ifBlock());
}

/**
 * @brief visit a statement created by a white block
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement5(ifccParser::Statement5Context *context)
{
    return (Statement *)visit(context->whileBlock());
}

/**
 * @brief visit a statement created by a for block
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement6(ifccParser::Statement6Context *context)
{
    return (Statement *)visit(context->forBlock());
}

/**
 * @brief visit a statement created by an expression
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement7(ifccParser::Statement7Context *context)
{
    Expr * expr = (Expr *)visit(context->expression());
    auto * inst = new InstructionExpr(expr);
    return (Statement *) inst;
}

/**
 * @brief visit a statement created by an instruction break
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement8(ifccParser::Statement8Context *context)
{
    InstructionBreak * instructionBreak = new InstructionBreak();
    return (Statement *) instructionBreak;
}

/**
 * @brief visit a statement created by an instruction continue
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement9(ifccParser::Statement9Context *context)
{
    InstructionContinue * instruction = new InstructionContinue();
    return (Statement *) instruction;
}

/**
 * @brief visit a statement created by an array
 * 
 * @param context : context of the statement
 * @return : a pointer on the statement
 */
antlrcpp::Any AstVisitor::visitStatement10(ifccParser::Statement10Context *context)
{
    return (Statement *)visit(context->array());
}

/**
 * @brief visit parameters of the context
 * 
 * @param context : the context
 * @return : a pointer on the list of parameters
 */
antlrcpp::Any AstVisitor::visitParameters(ifccParser::ParametersContext *context)
{
    auto * parameters = new Parameters();

    int index = 0;
    for(const auto p : context->parameter()){
        parameters->addParameter((Parameter *) visit(p));
    }

    return (Parameters *) parameters;
}

/**
 * @brief get a parameter by its address
 * 
 * @param context : the context
 * @return : a pointer on the parameter
 */
antlrcpp::Any AstVisitor::visitParameter(ifccParser::ParameterContext *context)
{
    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    if (res == "char") {
        t = CHAR;
    }
    auto line = context->IDENT()->getSymbol()->getLine();
    auto * parameter = new Parameter(context->IDENT()->getText(), t, line);

    return (Parameter *) parameter;
}

/**
 * @brief visit the declarations and create a list of declarations
 * 
 * @param context : the context
 * @return a pointer on the statement of the list of declarations
 */
antlrcpp::Any AstVisitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    auto * declarations = new Declarations();
    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    if (res == "char") {
        t = CHAR;
    }

    for (const auto var : context->IDENT()) {
        auto line = var->getSymbol()->getLine();
        declarations->addDeclaration(new Declaration(var->getText(), t, line));
    }
    return (Statement *) declarations;
}

/**
 * @brief visit a return in an expression a create the statement of the return
 * 
 * @param context : the context of the return
 * @return a statement pointer of the return
 */
antlrcpp::Any AstVisitor::visitRet1(ifccParser::Ret1Context *context) {
    Expr *expr = (Expr *) visit(context->expression());
    Return *ret = new Return(expr);
    return (Statement *) ret;
}

/**
 * @brief visit an affectation 1 (type IDENT '=' expression) and create its statement
 * 
 * @param context : the context of the affectation
 * @return a statement pointer of the affectation
 */
antlrcpp::Any AstVisitor::visitAffectation1(ifccParser::Affectation1Context *context) {
    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    if (res == "char") {
        t = CHAR;
    }
    auto line = context->IDENT()->getSymbol()->getLine();
    auto *declaration = new Declaration(context->IDENT()->getText(), t, line);
    Expr *expr = (Expr *) visit(context->expression());
    auto *decAffectation = new DecAffectation(declaration, expr);
    return (Statement *) decAffectation;
}

/**
 * @brief visit an affectation 2 (IDENT '=' expression) and create its statement
 * 
 * @param context : the context of the affectation
 * @return a statement pointer of the affectation
 */
antlrcpp::Any AstVisitor::visitAffectation2(ifccParser::Affectation2Context *context) {
    auto exprVarLine = context->IDENT()->getSymbol()->getLine();
    auto *exprVar = new ExprVar(context->IDENT()->getText(), exprVarLine);
    Expr *expr = (Expr *) visit(context->expression());
    auto *affectation = new Affectation(exprVar, expr);
    return (Statement *) affectation;
}

/**
 * @brief visit an affectation 3 (expression '=' expression) and create its statement
 * 
 * @param context : the context of the affectation
 * @return a statement pointer of the affectation
 */
antlrcpp::Any AstVisitor::visitAffectation3(ifccParser::Affectation3Context *context){
    Expr *lexpr = (Expr *) visit(context->expression(0));
    Expr *rexpr = (Expr *) visit(context->expression(1));

    ExprRArray * exprTmp = dynamic_cast<ExprRArray *>(lexpr);
    ExprLArray * exprLArray;
    if(lexpr){
        exprLArray = new ExprLArray(exprTmp->getName(), exprTmp->getType(), exprTmp->getPosition());
    } else {
        cerr << "Sorry, this compiler does not allow this functionality yet" << endl;
        exit(1);
    }

    ExprAffectation * affectation = new ExprAffectation(exprLArray, rexpr);
    return (Statement *) affectation;
}

/**
 * @brief visit the declaration of an array and create its statement
 * 
 * @param context : the context of the array
 * @return a statement pointer of the array's declaration
 */
antlrcpp::Any AstVisitor::visitDeclarationArray(ifccParser::DeclarationArrayContext *context){
    int size = stoi(context->CONST()->getText()); 

    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    int offset = 8;
    if (res == "char") {
        cerr << "Sorry, this compiler does not allow this functionality yet" << endl;
        exit(1);
        t = CHAR;
        offset = 1;
    }

    string name = context->IDENT()->getText();
    ExprArray * arrayD = new ExprArray(name,t, size*offset);
    return (Statement *) new ExprDeclaration(arrayD);
}

/**
 * @brief visit the affectation of an array and create its statement
 * 
 * @param context : the context of the array
 * @return a statement pointer of the array's affectation
 */
antlrcpp::Any AstVisitor::visitAffectationArray(ifccParser::AffectationArrayContext *context){
    int size = 0;
    if(context->CONST()){
        size = stoi(context->CONST()->getText()); 

        if(context->expression().size() != size){
            cerr << "The size of the table is not good" << endl;
        }  
    }

    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    int offset = 8;
    if (res == "char") {
        cerr << "Sorry, this compiler does not allow this functionality yet" << endl;
        exit(1);
        t = CHAR;
        offset = 1;
    }

    string name = context->IDENT()->getText();

    ArrayAffectation * arrayAff = new ArrayAffectation();
    size = 0;
    for(const auto expr : context->expression()){
        Expr * rValue = (Expr * ) visit(expr);
        Expr * pos = (Expr *) new ExprConst("", size*offset);
        Expr * lValue = (Expr *) new ExprLArray(name, t, pos); 
        arrayAff->addStatement(new ExprAffectation(lValue, rValue));
        size ++;
    }

    ExprArray * arrayD = new ExprArray(name,t, size*offset);
    arrayAff->setArray(arrayD);

    return (Statement *) arrayAff;
}

/**
 * @brief visit en unary expression 
 * 
 * @param context : the context of the unary expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitUnaryexpr(ifccParser::UnaryexprContext *context) {
    Expr *expr = (Expr *) visit(context->expression());
    Operator op;
    if (context->op->getText() == "-") {
        op = NEG;
    } else {
        op = NOT;
    }
    auto *unary = new ExprUnary("", expr, op);
    return (Expr *) unary;
}

/**
 * @brief visit a char expression
 * 
 * @param context : the context of the char
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitCharexpr(ifccParser::CharexprContext *context) {
    string variable = context->CHARACTER()->getText();
    char character = variable.substr(1, 2)[0];
    int value = (int) character;

    auto *expr = new ExprChar("", value);
    return (Expr *) expr;
}

/**
 * @brief visit a relationnal expression (>= for exemple)
 * 
 * @param context : the context of the relationnal expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitRelationalexpr(ifccParser::RelationalexprContext *context) {
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == ">") {
        op = GR;
    } else if (context->op->getText() == ">=") {
        op = GRE;
    } else if (context->op->getText() == "<") {
        op = LE;
    } else {     //if(context->op->getText() == "<=")
        op = LEE;
    }

    bool lConst = checkConst(lExpr);
    bool rConst = checkConst(rExpr);

    int lValue, rValue;
    if(lConst) {
        lValue = getConstValue(lExpr);
    }
    if(rConst) {
        rValue = getConstValue(rExpr);
    }

    if(lConst && rConst) {
        delete lExpr;
        delete rExpr;
        if(op == GR){
            return (Expr *) new ExprConst("", lValue > rValue);
        } else if(op == GRE) {
            return (Expr *) new ExprConst("", lValue >= rValue);
        } else if(op == LE){
            return (Expr *) new ExprConst("", lValue < rValue);
        } else {
            return (Expr *) new ExprConst("", lValue <= rValue);
        }
    }

    auto *rel = new ExprRelational("", lExpr, rExpr, op);
    return (Expr *) rel;
}

/**
 * @brief visit an expression between brackets
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitBracketexpr(ifccParser::BracketexprContext *context) {
    return (Expr *) visit(context->expression());
}

/**
 * @brief visit an expression with only a variable
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitVarexpr(ifccParser::VarexprContext *context) {
    auto exprVarLine = context->IDENT()->getSymbol()->getLine();
    auto *exprVar = new ExprVar(context->IDENT()->getText(), exprVarLine);
    return (Expr *) exprVar;
}

/**
 * @brief visit an expression with a multiplicative operator (* / %)
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitMultplicationexpr(ifccParser::MultplicationexprContext *context) {
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "*") {
        op = MULT;
    } else if (context->op->getText() == "/") {
        op = DIV;
    } else {
        op = MOD;
    }

    bool lConst = checkConst(lExpr);
    bool rConst = checkConst(rExpr);

    int lValue, rValue;
    if(lConst) {
        lValue = getConstValue(lExpr);
    }
    if(rConst) {
        rValue = getConstValue(rExpr);
    }

    if(lConst && rConst) {
        delete lExpr;
        delete rExpr;
        if(op == MULT){
            return (Expr *) new ExprConst("", lValue * rValue);
        } else if(op == DIV){
            return (Expr *) new ExprConst("", lValue / rValue);
        } else {
            return (Expr *) new ExprConst("", lValue % rValue);
        }
    }

    if(lConst && (lValue == 1) && op ==MULT) {
        delete lExpr;
        return (Expr *) rExpr;
    }

    if(rConst && (rValue ==1)){
        delete rExpr;
        return (Expr *) lExpr;
    }

    auto *mul = new ExprMult("", lExpr, rExpr, op);
    return (Expr *) mul;
}

/**
 * @brief visit an expression with a additive operator (+ -)
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitAdditiveexpr(ifccParser::AdditiveexprContext *context) {
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "+") {
        op = PLUS;
    } else {
        op = MINUS;
    }

    bool lConst = checkConst(lExpr);
    bool rConst = checkConst(rExpr);

    int lValue, rValue;
    if(lConst) {
        lValue = getConstValue(lExpr);
    }
    if(rConst) {
        rValue = getConstValue(rExpr);
    }

    if(lConst && rConst) {
        delete lExpr;
        delete rExpr;
        if(op == PLUS){
            return (Expr *) new ExprConst("", lValue + rValue);
        } else {
            return (Expr *) new ExprConst("", lValue - rValue);
        } 
    }

    if(lConst && (lValue == 0)) {
        delete lExpr;
        return (Expr *) rExpr;
    }

    if(rConst && (rValue ==0)){
        delete rExpr;
        return (Expr *) lExpr;
    }


    ExprAdd *add = new ExprAdd("", lExpr, rExpr, op);
    return (Expr *) add;
}

/**
 * @brief visit a bit to bit expression (& | ^)
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitBitsexpr(ifccParser::BitsexprContext *context) {
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "|") {
        op = OR;
    } else if (context->op->getText() == "&") {
        op = AND;
    } else {
        op = XOR;
    }

    bool lConst = checkConst(lExpr);
    bool rConst = checkConst(rExpr);

    int lValue, rValue;
    if(lConst) {
        lValue = getConstValue(lExpr);
    }
    if(rConst) {
        rValue = getConstValue(rExpr);
    }

    if(lConst && rConst) {
        delete lExpr;
        delete rExpr;
        if(op == OR){
            return (Expr *) new ExprConst("", lValue | rValue);
        } else if(op == AND){
            return (Expr *) new ExprConst("", lValue & rValue);
        } else {
            return (Expr *) new ExprConst("", lValue ^ rValue);
        }
    }

    ExprBits *bits = new ExprBits("", lExpr, rExpr, op);
    return (Expr *) bits;
}

/**
 * @brief visit an expression with constant variables
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitConstexpr(ifccParser::ConstexprContext *context) {
    int value = stoi(context->CONST()->getText());
    ExprConst *expr = new ExprConst("", value);
    return (Expr *) expr;
}

/**
 * @brief visit an equality expression
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitEqualityexpr(ifccParser::EqualityexprContext *context) {
    Expr *lExpr = (Expr *) visit(context->expression(0));
    Expr *rExpr = (Expr *) visit(context->expression(1));
    Operator op;
    if (context->op->getText() == "==") {
        op = EQUAL;
    } else {
        op = NEQUAL;
    }

    bool lConst = checkConst(lExpr);
    bool rConst = checkConst(rExpr);

    int lValue, rValue;
    if(lConst) {
        lValue = getConstValue(lExpr);
    }
    if(rConst) {
        rValue = getConstValue(rExpr);
    }

    if(lConst && rConst) {
        delete lExpr;
        delete rExpr;
        if(op == EQUAL){
            return (Expr *) new ExprConst("", lValue == rValue);
        } else{
            return (Expr *) new ExprConst("", lValue != rValue);
        } 
    }

    ExprEqual *equal = new ExprEqual("", lExpr, rExpr, op);
    return (Expr *) equal;
}

/**
 * @brief visit an expression with an array
 * 
 * @param context : the context of the expression
 * @return a pointer on the expression
 */
antlrcpp::Any AstVisitor::visitArrayexpr(ifccParser::ArrayexprContext *context){
    string varname = context->IDENT()->getText();

    Expr * offset = (Expr *) visit(context->expression());
    Expr * position;
    if(checkConst(offset)){             //TODO: Handle char
        position = (Expr *) new ExprConst("", 8*getConstValue(offset));
    } else {
        position = (Expr *) new ExprMult("", offset, new ExprConst("", 8), MULT);
    }

    ExprRArray * rArray = new ExprRArray(varname, INT64_T, position);
    return (Expr *) rArray;
}

/**
 * @brief visit a type
 * 
 * @param context : the context of the type
 * @return : the type visited
 */
antlrcpp::Any AstVisitor::visitType(ifccParser::TypeContext *context) {
    string type = context->getText();
    return type;
}

/**
 * @brief visit a if block and create the instruction associated
 * 
 * @param context : the context of the if block
 * @return a statement pointer of the instruction
 */
antlrcpp::Any AstVisitor::visitIfBlock(ifccParser::IfBlockContext *context)
{
    Expr* test = (Expr*)visit(context->expression());

    Block* ifBlock;
    if(context->statement()){
        ifBlock = new Block();
        Statement *statement = (Statement *) visit(context->statement());
        ifBlock->addStatement(statement);
    } else {
        ifBlock = (Block*)visit(context->block());
    }

    Block* elseBlock = nullptr;
    if(context->elseBlock()){
        elseBlock = (Block*)visit(context->elseBlock());
    } 

    InstructionIF * instrIF = new InstructionIF(test, ifBlock, elseBlock);
    return (Statement *) instrIF;
}

/**
 * @brief visit else block
 * 
 * @param context : the context of the else block 
 * @return a pointer on the block
 */
antlrcpp::Any AstVisitor::visitElseBlock(ifccParser::ElseBlockContext *context) 
{
    Block* elseBlock = nullptr;
    if(context->statement()){
        Statement *statement = (Statement *) visit(context->statement());
        elseBlock = new Block();
        elseBlock->addStatement(statement);
    } else if(context->block()){
        elseBlock = (Block*)visit(context->block());
    } else {
        Statement *statement = (Statement *) visit(context->ifBlock());
        elseBlock = new Block();
        elseBlock->addStatement(statement);
    }

    return (Block *) elseBlock;
}

/**
 * @brief visit a white block and create the instrcution associated
 * 
 * @param context : the context of the white block
 * @return a statement of the instruction created
 */
antlrcpp::Any AstVisitor::visitWhileBlock(ifccParser::WhileBlockContext *context){
    Expr* test = (Expr*)visit(context->expression());

    Block* whileBlock;
    if(context->statement()){
        whileBlock = new Block();
        Statement *statement = (Statement *) visit(context->statement());
        whileBlock->addStatement(statement);
    } else {
        whileBlock = (Block*)visit(context->block());
    }

    InstructionWhile * instrWhile = new InstructionWhile(test, whileBlock);
    return (Statement *) instrWhile;
}

/**
 * @brief visit a for block and create the instruction associated
 * 
 * @param context : the context of the for block
 * @return a statement pointer of the instruction
 */
antlrcpp::Any AstVisitor::visitForBlock(ifccParser::ForBlockContext *context) {
    Statement * init = nullptr;
    Statement * update = nullptr;
    if(context->init!=nullptr){
        init = (Statement *) visit(context->init);
    }
    if(context->update!=nullptr){
        update = (Statement *) visit(context->update);
    }

    Expr * test = (Expr *) visit(context->test);

    Block* forBlock;
    if(context->statement(1)){
        forBlock = new Block();
        Statement *statement = (Statement *) visit(context->statement(1));
        forBlock->addStatement(statement);
    } else {
        forBlock = (Block*)visit(context->block());
    }

    InstructionFor * instrFor = new InstructionFor(init, test, update, forBlock);
    return (Statement *) instrFor;
}

/**
 * @brief visit an expression with a function
 * 
 * @param context : the context of the function
 * @return an expression pointer of the function
 */
antlrcpp::Any AstVisitor::visitFunctionexpr(ifccParser::FunctionexprContext *context){
    string name = context->IDENT()->getText();
    ExprFunction * function = new ExprFunction(name);

    for(const auto expr : context->expression()){
        function->addParameter((Expr * ) visit(expr));
    }

    return (Expr *) function;
}

/**
 * @brief check if an expression is a constant
 * 
 * @param expr : the expression to check
 * @return true 
 * @return false 
 */
bool AstVisitor::checkConst(Expr * expr){
    ExprConst * exprConst = dynamic_cast<ExprConst *>(expr);
    
    if(exprConst){
        return true;
    }

    ExprChar * exprChar = dynamic_cast<ExprChar *>(expr);

    if(exprChar){
        return true;
    }

    return false; 
}

/**
 * @brief get the value of the expression if constant or return 0
 * 
 * @param expr : the expression
 * @return : the value of the expression or a 0
 */
int AstVisitor::getConstValue(Expr * expr){
    ExprConst * exprConst = dynamic_cast<ExprConst *>(expr);
    
    if(exprConst){
        return exprConst->getValue();
    }

    ExprChar * exprChar = dynamic_cast<ExprChar *>(expr);

    if(exprChar){
        return exprChar->getValue();
    }

    return 0; 
}
