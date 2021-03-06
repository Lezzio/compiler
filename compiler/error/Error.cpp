//
// Created by allan guigal on 28/03/2022.
//

#include "Error.h"

#include <utility>

/**
 * @brief Construct a new Error:: Error object
 *
 */
Error::Error(string message, unsigned long line) : message(std::move(message)), line(line) {}