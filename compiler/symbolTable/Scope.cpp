//
// Created by allan guigal on 03/04/2022.
//

#include "Scope.h"
#include <iterator>

int Scope::getCurrentLevel() {
    return levelContext.back();
}

string Scope::getLevelContextAsString() {
    std::stringstream context;
    std::copy(levelContext.begin(), levelContext.end(), std::ostream_iterator<int>(context, " "));
    return context.str();
}