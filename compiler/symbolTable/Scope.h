
#ifndef COMPILER_SCOPE_H
#define COMPILER_SCOPE_H

#include <string>
#include <utility>
#include <vector>

using namespace std;

class Scope {

public:
    explicit Scope(string name) : name(std::move(name)) {}

    /**
     * The functionName of the scope, usually GLOBAL or the function's functionName
     */
    string name;
    /**
     * The level context of the scope within the functionName's scope
     */
    vector<int> levelContext;

    /**
     * @return the current level based on [levelContext] meaning the vector's back (last element)
     */
    int getCurrentLevel();
};

#endif //COMPILER_SCOPE_H