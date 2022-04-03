#include "ast/ast.h"
#include "AstVisitor.h"
#include <iostream>

using namespace std;
using namespace antlr4;

antlrcpp::Any AstVisitor::visitAxiom(ifccParser::AxiomContext *ctx) {
    //throw antlr4::RecognitionException("okokok", recognizer, recognizer->getInputStream(), recognizer->getContext(), recognizer->getCurrentToken());
    return visit(ctx->prog());
}

antlrcpp::Any AstVisitor::visitProg(ifccParser::ProgContext *context) {
    Prog *prog = new Prog();
    for (const auto f : context->function()) {
        Function *function = (Function *) visit(f);
        prog->addFunction(function);
    }
    return prog;
}

antlrcpp::Any AstVisitor::visitFunction(ifccParser::FunctionContext *context) {
    string name = context->IDENT()->getText();
  // string name = "main";
  //  string name = (string) visit(context->nameFunction()).as<string>();
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

    Block * block = (Block *) visit(context->block());
    auto * function = new Function(name, t, parameters, block);
    return (Function * ) function;
}

antlrcpp::Any AstVisitor::visitBlock(ifccParser::BlockContext *context) {
    auto *block = new Block();
    for (const auto s : context->statement()) {
        Statement *statement = (Statement *) visit(s);
        block->addStatement(statement);
    }
    return (Block *) block;
}

antlrcpp::Any AstVisitor::visitStatement1(ifccParser::Statement1Context *context) {
    return (Statement *) visit(context->declaration());
}

antlrcpp::Any AstVisitor::visitStatement2(ifccParser::Statement2Context *context) {
    return (Statement *) visit(context->affectation());
}

antlrcpp::Any AstVisitor::visitStatement3(ifccParser::Statement3Context *context) {
    return (Statement *) visit(context->retcode());
}

antlrcpp::Any AstVisitor::visitStatement4(ifccParser::Statement4Context *context)
{
    return (Statement *)visit(context->ifBlock());
}

antlrcpp::Any AstVisitor::visitStatement5(ifccParser::Statement5Context *context)
{
    return (Statement *)visit(context->whileBlock());
}

antlrcpp::Any AstVisitor::visitStatement6(ifccParser::Statement6Context *context)
{
    return (Statement *)visit(context->forBlock());
}

antlrcpp::Any AstVisitor::visitStatement7(ifccParser::Statement7Context *context)
{
    Expr * expr = (Expr *)visit(context->expression());
    auto * inst = new InstructionExpr(expr);
    return (Statement *) inst;
}

antlrcpp::Any AstVisitor::visitStatement8(ifccParser::Statement8Context *context)
{
    InstructionBreak * instructionBreak = new InstructionBreak();
    return (Statement *) instructionBreak;
}

antlrcpp::Any AstVisitor::visitStatement9(ifccParser::Statement9Context *context)
{
    InstructionContinue * instruction = new InstructionContinue();
    return (Statement *) instruction;
}

antlrcpp::Any AstVisitor::visitParameters(ifccParser::ParametersContext *context)
{
    auto * parameters = new Parameters();

    int index = 0;
    for(const auto p : context->parameter()){
        parameters->addParameter((Parameter *) visit(p));
    }

    return (Parameters *) parameters;
}

antlrcpp::Any AstVisitor::visitParameter(ifccParser::ParameterContext *context)
{
    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    if (res == "char") {
        t = CHAR;
    }
    auto * parameter = new Parameter(context->IDENT()->getText(), t);

    return (Parameter *) parameter;
}

antlrcpp::Any AstVisitor::visitDeclaration(ifccParser::DeclarationContext *context)
{
    auto * declarations = new Declarations();
    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    if (res == "char") {
        t = CHAR;
    }

    for (const auto var : context->IDENT()) {
        declarations->addDeclaration(new Declaration(var->getText(), t));
    }
    return (Statement *) declarations;
}

antlrcpp::Any AstVisitor::visitRet1(ifccParser::Ret1Context *context) {
    Expr *expr = (Expr *) visit(context->expression());
    Return *ret = new Return(expr);
    return (Statement *) ret;
}


antlrcpp::Any AstVisitor::visitAffectation1(ifccParser::Affectation1Context *context) {
    string res = (string) visit(context->type()).as<string>();

    TypeSymbol t = INT;
    if (res == "char") {
        t = CHAR;
    }

    auto *declaration = new Declaration(context->IDENT()->getText(), t);
    Expr *expr = (Expr *) visit(context->expression());
    auto *decAffectation = new DecAffectation(declaration, expr);
    return (Statement *) decAffectation;
}

antlrcpp::Any AstVisitor::visitArray_declaration(ifccParser::Array_declarationContext *context) {
    
}

antlrcpp::Any AstVisitor::visitArray_affectation(ifccParser::Array_affectationContext *context) {
    
}

/*antlrcpp::Any AstVisitor::visitAffectation2(ifccParser::Affectation2Context *context) {
    auto *exprVar = new ExprVar(context->IDENT()->getText());
    Expr *expr = (Expr *) visit(context->expression());
    auto *affectation = new Affectation(exprVar, expr);
    return (Statement *) affectation;
}*/

antlrcpp::Any AstVisitor::visitAffectation2(ifccParser::Affectation2Context *context) {
    Expr *lexpr = (Expr *) visit(context->expression(0));
    Expr *rexpr = (Expr *) visit(context->expression(1));

    Affectation *affectation = new Affectation(lexpr, rexpr);
    return (Statement *) affectation;
}

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

antlrcpp::Any AstVisitor::visitCharexpr(ifccParser::CharexprContext *context) {
    string variable = context->CHARACTER()->getText();
    char character = variable.substr(1, 2)[0];
    int value = (int) character;

    auto *expr = new ExprChar("", value);
    return (Expr *) expr;
}

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

antlrcpp::Any AstVisitor::visitBracketexpr(ifccParser::BracketexprContext *context) {
    return (Expr *) visit(context->expression());
}

antlrcpp::Any AstVisitor::visitVarexpr(ifccParser::VarexprContext *context) {
    ExprVar *exprVar = new ExprVar(context->IDENT()->getText());
    return (Expr *) exprVar;
}

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

antlrcpp::Any AstVisitor::visitConstexpr(ifccParser::ConstexprContext *context) {
    int value = stoi(context->CONST()->getText());
    ExprConst *expr = new ExprConst("", value);
    return (Expr *) expr;
}

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

antlrcpp::Any AstVisitor::visitArrayexpr(ifccParser::ArrayexprContext *context) {
    Expr* indexExpr = (Expr*) visit(context->expression());

    ExprArray * exprArray = new ExprArray(context->IDENT()->getText(), indexExpr);
}

antlrcpp::Any AstVisitor::visitType(ifccParser::TypeContext *context) {
    string type = context->getText();
    return type;
}

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


antlrcpp::Any AstVisitor::visitFunctionexpr(ifccParser::FunctionexprContext *context){
    string name = context->IDENT()->getText();
    ExprFunction * function = new ExprFunction(name);

    for(const auto expr : context->expression()){
        function->addParameter((Expr * ) visit(expr));
    }

    return (Expr *) function;
}


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
