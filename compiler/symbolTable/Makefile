all: analyse

analyse: Symbol.o SymbolTable.o testSTtemporel.o
	g++ -o analyse Symbol.o SymbolTable.o testSTtemporel.o

Symbol.o: Symbol.cpp Symbol.h
	g++ -o Symbol.o -c Symbol.cpp

SymbolTable.o: SymbolTable.cpp SymbolTable.h Symbol.h
	g++ -o SymbolTable.o -c SymbolTable.cpp

testSTtemporel.o: testSTtemporel.cpp SymbolTable.h
	g++ -o testSTtemporel.o -c testSTtemporel.cpp

clean:
	rm -rf *.o

mrproper: clean
	rm -rf analyse