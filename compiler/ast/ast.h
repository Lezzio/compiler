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
        unsigned long line;
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
        int getValue(){return value;};
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
        int getValue(){return value;};
    protected : 
        int value;
};

class ExprArray : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        ExprArray(string varName, TypeSymbol type, int size) :
            Expr(varName), size(size), type(type){};
        virtual ~ExprArray()= default;
    protected : 
        TypeSymbol type;
        int size;

};


class ExprLArray : public Expr  
{
    public :
        virtual string linearize(CFG * cfg);
        ExprLArray(string varName, TypeSymbol type, Expr* position) :
            Expr(varName), position(position), type(type){};
        virtual ~ExprLArray();
    protected : 
        TypeSymbol type;
        Expr* position;

};

class ExprRArray : public Expr 
{
    public :
        virtual string linearize(CFG * cfg);
        ExprRArray(string varName, TypeSymbol type, Expr *position) :
            Expr(varName), position(position), type(type){};
        virtual ~ExprRArray();
        TypeSymbol getType() { return type; };
        Expr * getPosition() { return position; };
        string getName() { return varName; };
    protected : 
        TypeSymbol type;
         Expr* position;

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

class ExprAffectation : public Statement 
{
    public :
        virtual string linearize(CFG * cfg);
         ExprAffectation(Expr * lExpr, Expr * rExpr) :
            Statement(), lExpr(lExpr), rExpr(rExpr) {};
        virtual ~ExprAffectation();
    protected :
        Expr *lExpr;
        Expr *rExpr;
};

class ArrayAffectation : public Statement 
{
    public :
        virtual string linearize(CFG * cfg);
        void addStatement(ExprAffectation * statement);
        void setArray(ExprArray * exprArray);
         ArrayAffectation() :
            Statement() {};
        virtual ~ArrayAffectation();
    protected :
        vector<ExprAffectation *> array_values;
        ExprArray * arrayD;

};

class ExprDeclaration : public Statement  
{
    public :
        virtual string linearize(CFG * cfg);
         ExprDeclaration(Expr * expr) :
            Statement(), expr(expr) {};
        virtual ~ExprDeclaration();
    protected :
        Expr * expr;
};

class Declaration : public ASTNode
{
    public :
        virtual string linearize(CFG * cfg);
        Declaration(string name, TypeSymbol type, unsigned long line) :
            name(name), type(type){
            ASTNode::line = line;
        };
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

class InstructionExpr : public Statement
{
    public:
        virtual string linearize(CFG * cfg);
        InstructionExpr(Expr * expr): Statement(), expr(expr) {};
        virtual ~InstructionExpr(){delete(expr);};
    protected:
        Expr * expr;
};

class InstructionBreak : public Statement
{
    public:
        virtual string linearize(CFG * cfg);
        virtual ~InstructionBreak() = default;
        InstructionBreak(): Statement() {};
    protected:
};

class InstructionContinue : public Statement
{
    public:
        virtual string linearize(CFG * cfg);
        virtual ~InstructionContinue() = default;
        InstructionContinue(): Statement() {};
    protected:
};

class Parameter : public ASTNode
{
    public :
        virtual string linearize(CFG * cfg);
        Parameter(string name, TypeSymbol type) :
            name(name),type(type){};
        virtual ~Parameter()= default;
        TypeSymbol getType() {return type;};
    protected :
        string name;
        TypeSymbol type;
};

class Parameters : public Statement
{
    public :
        void addParameter(Parameter *parameter);
        virtual string linearize(CFG * cfg);
        Parameters() :
                Statement(){};
            virtual ~Parameters();
        vector<Parameter *> getParameters() {return parameters;}; 
    protected :
        vector<Parameter *> parameters;
};

class Function : public ASTNode {
public :
    string linearize(CFG *cfg);

    Function(string name, TypeSymbol type, Parameters *parameters, Block *block, unsigned long line)
            : ASTNode(), block(block), name(name), type(type), parameters(parameters) {
        ASTNode::line = line;
    };

    virtual ~Function();

    string name;
protected:
    Parameters *parameters;
    Block *block;
    TypeSymbol type;
    unsigned long line;
};

class ExprFunction : public Expr
{
    public :
        virtual string linearize(CFG * cfg);
        void addParameter(Expr * expr);
        ExprFunction(string varName) :
            Expr(varName){};
        virtual ~ExprFunction();
        string getName() const {return varName;};
    protected : 
        vector<Expr *> parameters;
};


class Prog : public ASTNode
{
    public:
        vector<CFG*> linearize();
        void addFunction(Function * function);
        Prog(): ASTNode()
            {};
        virtual ~Prog();
    protected:
        vector<Function *> functions;
        vector<CFG*> cfgs;
        
};

#endif