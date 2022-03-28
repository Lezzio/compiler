#ifndef AST_H
#define AST_H

#include "../intermediateRepresentation/IR.h"

#include <string> 
#include <vector>
using namespace std;

enum Operator {
    MULT, DIV, MOD,
    PLUS, MINUS,
    OR, AND, XOR,
    GR, GRE, LE, LEE,
    EQUAL, NEQUAL,
    NEG, NOT
};

class ASTNode
{
    public :
        ASTNode() 
           {};
        virtual ~ASTNode() = default;

};

class Expr : public ASTNode
{
    public : 
        virtual string linearize(CFG * cfg) = 0;
        Expr(string varName) :
            ASTNode(), varName(varName){};
        virtual ~Expr()= default;
    protected :
        string varName;

};

class ExprVar : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprVar(string varName) :
            Expr(varName){};
        virtual ~ExprVar()= default;

};

class ExprConst : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprConst(string varName="", int value = 0) :
            Expr(varName), value(value){};
        virtual ~ExprConst()= default;
    protected : 
        int value;
};

class ExprChar : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprChar(string varName, int value) :
            Expr(varName), value(value){};
        virtual ~ExprChar()= default;
    protected : 
        int value;
};

class ExprMult : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprMult(string varName, Expr * lExpr, Expr * rExpr, Operator op) :
            Expr(varName), lExpr(lExpr), rExpr(rExpr), op(op){};
        virtual ~ExprMult();
    protected :
        Operator op; 
        Expr *lExpr;
        Expr *rExpr;
};

class ExprAdd : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprAdd(string varName, Expr * lExpr, Expr * rExpr, Operator op) :
            Expr(varName), lExpr(lExpr), rExpr(rExpr), op(op){};
        virtual ~ExprAdd();
    protected :
        Operator op; 
        Expr *lExpr;
        Expr *rExpr;
};

class ExprBits : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprBits(string varName, Expr * lExpr, Expr * rExpr, Operator op) :
            Expr(varName), lExpr(lExpr), rExpr(rExpr), op(op){};
        virtual ~ExprBits();
    protected :
        Operator op; 
        Expr *lExpr;
        Expr *rExpr;
};

class ExprRelational : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprRelational(string varName, Expr * lExpr, Expr * rExpr, Operator op) :
            Expr(varName), lExpr(lExpr), rExpr(rExpr), op(op){};
        virtual ~ExprRelational();
    protected :
        Operator op; 
        Expr *lExpr;
        Expr *rExpr;
};

class ExprEqual : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprEqual(string varName, Expr * lExpr, Expr * rExpr, Operator op) :
            Expr(varName), lExpr(lExpr), rExpr(rExpr), op(op){};
        virtual ~ExprEqual();
    protected :
        Operator op; 
        Expr *lExpr;
        Expr *rExpr;
};

class ExprUnary : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprUnary(string varName, Expr * rExpr, Operator op) :
            Expr(varName), rExpr(rExpr), op(op){};
        virtual ~ExprUnary();
    protected :
        Operator op; 
        Expr *rExpr;
};

class Statement : public ASTNode 
{
    public :
        virtual string linearize(CFG * cfg) = 0;
        Statement(): ASTNode()
            {};
        virtual ~Statement()= default;
};

class Block : public ASTNode 
{
    public:
        virtual void linearize(CFG * cfg);
        void addStatement(Statement * statement);
        Block(): ASTNode()
            {};
        virtual ~Block();
    protected:
        vector<Statement *> statements;
};

class Prog : public ASTNode
{
    public:
        CFG* linearize();
        Prog(Block * block): ASTNode(), block(block)
            {};
        virtual ~Prog();
    protected:
        Block * block;
        
};


class Affectation : public Statement
{
    public :
        virtual string linearize(CFG * cfg);
        Affectation(ExprVar * lExpr, Expr * rExpr) :
            Statement(), lExpr(lExpr), rExpr(rExpr) {};
        virtual ~Affectation();
    protected :
        ExprVar *lExpr;
        Expr *rExpr;
};

class Declaration : public ASTNode
{
    public :
        virtual string linearize(CFG * cfg);
        Declaration(string name, TypeSymbol type) :
            name(name),type(type){};
        virtual ~Declaration()= default;
    protected :
        string name;
        TypeSymbol type;
};

class DecAffectation : public Statement
{
    public :
        virtual string linearize(CFG * cfg);
        DecAffectation(Declaration *declaration, Expr * rExpr) :
            Statement(), declaration(declaration), rExpr(rExpr){};
        virtual ~DecAffectation();
    protected :
        Declaration *declaration;
        Expr *rExpr;
        TypeSymbol type;

};


class Declarations : public Statement
{
    public :
        void addDeclaration(Declaration *declaration);
        virtual string linearize(CFG * cfg);
        Declarations() :
                Statement(){};
            virtual ~Declarations();
    protected :
        vector<Declaration *> declarations;
};

class Return : public Statement
{
    public :
        Return(Expr * returnExpr) : Statement(), expr(returnExpr){};
        virtual ~Return();
        virtual string linearize(CFG * cfg);
    protected :
        Expr * expr;

};

class InstructionIF : public Statement
{
    public:
        virtual string linearize(CFG * cfg);
        InstructionIF(Expr* test, Block * then, Block * elseb) : Statement(), test(test), falseCodeBlock(elseb), trueCodeBlock(then){};
        virtual ~InstructionIF();
    protected :
        Expr * test;
        Block * trueCodeBlock;
        Block * falseCodeBlock;
};

class InstructionWhile : public Statement
{
    public:
        virtual string linearize(CFG * cfg);
        InstructionWhile(Expr* test, Block * block) : Statement(), test(test), block(block) {};
        virtual ~InstructionWhile();
    protected:
        Expr * test;
        Block * block;
};

class InstructionFor : public Statement
{
    public:
        virtual string linearize(CFG * cfg);
        InstructionFor(Statement* init, Expr* test, Statement* update, Block * block) : Statement(), test(test), block(block), init(init), update(update) {};
        virtual ~InstructionFor();
    protected:
        Statement * init;
        Expr * test;
        Statement * update;
        Block * block;
};

#endif