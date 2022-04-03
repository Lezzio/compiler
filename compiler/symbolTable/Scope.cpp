//
// Created by allan guigal on 03/04/2022.
//

#include "Scope.h"

int Scope::getCurrentLevel() {
    if (levelContext.empty()) {
        return 0;
    }
    return levelContext.back();
}