//
// Created by allan guigal on 03/04/2022.
//

#include "Scope.h"
#include <iterator>
/**
 * @brief get the current level of the scope
 * 
 * @return the level of the scope
 */
int Scope::getCurrentLevel() {
    return levelContext.back();
}

/**
 * @brief get the level of the context a parse it
 * 
 * @return the level of the context (string)
 */
string Scope::getLevelContextAsString() {
    std::stringstream context;
    std::copy(levelContext.begin(), levelContext.end(), std::ostream_iterator<int>(context, " "));
    return context.str();
}