# You can override these from the command-line, as illustrated by the various `runmake_*.sh` scripts
ANTLRJAR=../antlr/jar/antlr-4.9.2-complete.jar
ANTLRINC=../antlr/include
ANTLRLIB=../antlr/lib/libantlr4-runtime.a
#ANTLRINC=/usr/include/antlr4-runtime
#ANTLRLIB=/usr/lib/x86_64-linux-gnu/libantlr4-runtime.a

CC=g++
CCFLAGS=-g -c -std=c++11 -I$(ANTLRINC) -Wno-attributes # -Wno-defaulted-function-deleted -Wno-unknown-warning-option
LDFLAGS=-g
SYMBOLTABLE=build/SymbolTable.o build/Symbol.o
IFCC-LEXER-VISITOR-PARSER=build/ifccBaseVisitor.o build/ifccLexer.o build/ifccVisitor.o build/ifccParser.o
IRINSTR=build/IRInstr.o
CFG=build/CFG.o
BB=build/BasicBlock.o
AST=build/ast.o build/AstVisitor.o 
ERRORMANAGEMENT=build/SyntaxErrorListener.o build/Error.o build/Warning.o build/ErrorManager.o build/ErrorStrategy.o
SCOPE=build/Scope.o
MAIN=build/main.o

default: all
all: ifcc

##########################################
# link together all pieces of our compiler
OBJECTS=$(SYMBOLTABLE) $(IFCC-LEXER-VISITOR-PARSER) $(IRINSTR) $(CFG) $(BB) $(AST) $(ERRORMANAGEMENT) $(SCOPE) $(MAIN) 

ifcc: $(OBJECTS)
	@mkdir -p build
	$(CC) $(LDFLAGS) build/*.o $(ANTLRLIB) -o ifcc

##########################################
# compile our hand-writen C++ code: main(), Visitor, etc.

build/Scope.o: symbolTable/Scope.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/ErrorStrategy.o: error/ErrorStrategy.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/SyntaxErrorListener.o: error/SyntaxErrorListener.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/Warning.o: error/Warning.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/Error.o: error/Error.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/ErrorManager.o: error/ErrorManager.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/%.o: %.cpp generated/ifccParser.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/SymbolTable.o: symbolTable/SymbolTable.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/Symbol.o: symbolTable/Symbol.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/ast.o: ast/ast.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/IRInstr.o: intermediateRepresentation/IRInstr.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/CFG.o: intermediateRepresentation/CFG.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

build/BasicBlock.o: intermediateRepresentation/BasicBlock.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

##########################################
# compile all the antlr-generated C++
build/%.o: generated/%.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

# automagic dependency management: `gcc -MMD` generates all the .d files for us
-include build/*.d

##########################################
# generate the C++ implementation of our Lexer/Parser/Visitor
#
# cf https://stackoverflow.com/a/3077254/117814 for the multiple-file trick
generated/ifcc%.cpp: ifcc.g4
	@mkdir -p generated
	java -cp $(ANTLRJAR) org.antlr.v4.Tool  -visitor -no-listener -Dlanguage=Cpp -o generated ifcc.g4

# prevent automatic cleanup of "intermediate" files like ifccLexer.cpp etc
.PRECIOUS: generated/ifcc%.cpp

##########################################
# view the parse tree in a graphical window

# Usage: `make gui FILE=path/to/your/file.c`
FILE ?= ../tests/testfiles/1_return42.c

gui:
	@mkdir -p generated build
	java -cp $(ANTLRJAR) org.antlr.v4.Tool -Dlanguage=Java -o generated ifcc.g4
	javac -cp $(ANTLRJAR) -d build generated/*.java
	java -cp $(ANTLRJAR):build org.antlr.v4.gui.TestRig ifcc axiom -gui $(FILE)

##########################################
# delete all machine-generated files
clean:
	rm -rf build generated
	rm -f ifcc