//
// Created by allan guigal on 28/03/2022.
//

#include "ErrorManager.h"

ErrorManager * ErrorManager::INSTANCE;

/**
 * @brief Construct a new Error Manager:: Error Manager object
 * 
 */
ErrorManager::ErrorManager() {
}

/**
 * @brief get the instance of the error manager
 * 
 * @return ErrorManager* : a pointer on the error manager
 */
ErrorManager * ErrorManager::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ErrorManager();
    }
    return INSTANCE;
}

/**
 * @brief add an error to the list of errors
 * 
 * @param error : the error to add
 */
void ErrorManager::addError(Error *error) {
    std::cout << "Error : " << error->message << " at line " << error->line << endl;
    this->errors.push_back(error);
}

void ErrorManager::addWarning(Warning *warning) {
    std::cout << "Warning : " << warning->message << " at line " << warning->line << endl;
    this->warnings.push_back(warning);
}