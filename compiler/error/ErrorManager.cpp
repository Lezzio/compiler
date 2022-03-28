//
// Created by allan guigal on 28/03/2022.
//

#include "ErrorManager.h"

ErrorManager * ErrorManager::INSTANCE;

ErrorManager::ErrorManager() {
}

ErrorManager * ErrorManager::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ErrorManager();
    }
    return INSTANCE;
}

void ErrorManager::addError(Error * error) {
    this->errors.push_back(error);
}