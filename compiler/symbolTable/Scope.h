
#ifndef COMPILER_SCOPE_H
#define COMPILER_SCOPE_H

#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

class Scope {

public:
    explicit Scope(string name) : name(std::move(name)) {
        levelContext.push_back(0); //The initial scope
    }

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

    string getLevelContextAsString();
};

#endif //COMPILER_SCOPE_H