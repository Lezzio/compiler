//
// Created by allan guigal on 28/03/2022.
//

#include "ErrorStrategy.h"
#include <iostream>

using namespace std;
using namespace antlr4;

void ErrorStrategy::reportError(Parser recognizer, RecognitionException e) {
    cout << "CALLED ANTLR4 REPORT ERROR" << endl;
}