//
// Created by allan guigal on 28/03/2022.
//

#ifndef COMPILER_ERRORSTRATEGY_H
#define COMPILER_ERRORSTRATEGY_H

#include "antlr4-runtime.h"

using namespace antlr4;

class ErrorStrategy : public DefaultErrorStrategy {

    void reportError(Parser recognizer,
                     RecognitionException e);

};


#endif //COMPILER_ERRORSTRATEGY_H
