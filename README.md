# compiler

This project implements a compiler for a C-like language.
The compiler supports essential language features like block structures, int and char primitive types, arrays, functions, loops, scopes and arithmetic operations

The compiler is using the antlr4 framework targeted for C++.

## Executable

First, from the root directory, go to the compiler subdirectory :

<pre><code>cd compiler</code></pre>

You can run the executable in different ways :

### `./ifcc program.c program.s`

Run the compiler to compile the program.c file and print the output in the program.s

### `./ifcc program.c program.s -ARM`

Also run the compiler but targeting ARM architectures.

## Makefile

### `make`

Compiles source files, generates binary files and creates the project executable.

### `make clean`

Deletes the compiled files

You can find additional information in :
* documentation_developpeur.md
* documentation_utilisateur.md
