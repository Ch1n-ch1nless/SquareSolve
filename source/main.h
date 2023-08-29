///@file main.h

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include "IOput.h"
#include "solve_square_equation.h"
#include "test.h"

/**
 * @brief Pointer to string "unittest"
 *
 * This string is passed in arguments of function main().
 * When the unittest pointer is an argument of the main() function,
 * the test program is called.
 *
 */
const char unittest[] = "--unit_test";

/**
 * @brief Run test.
 *
 * Function, check if need to do unit tests.
 *
 * @param [in] argc
 * @param [in] argv
 * @return if need to do unit tests.
 */
bool CheckIfTestNeedToDo(int argc, const char* argv[]);

/**
 *
 *@brief Check if the file name is correct
 *
 *@param [in] str - file name pointer
 *@return if the file extension if .txt
 */
bool CheckFile (const char *str);

#endif // MAIN_H_INCLUDED
