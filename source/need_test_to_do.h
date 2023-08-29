///@file need_test_to_do.h

#ifndef NEED_TEST_TO_DO_H_INCLUDED
#define NEED_TEST_TO_DO_H_INCLUDED

#include <string>
#include "IOput.h"
#include "solve_square_equation.h"
#include "test.h"

/**
 * @brief Pointer to string "--unit_test"
 *
 * This string is passed in arguments of function main().
 * When the unittest pointer is an argument of the main() function,
 * the test program is called.
 *
 */
const char unittest[] = "--unit_test";

/**
 * @brief Pointer to string "--help"
 *
 * This string is passed in arguments of function main().
 * When the help pointer is an argument of the main() function,
 * the program show what commands user can enter.
 *
 */
const char help[] = "--help";

/**
 * @brief Run test.
 *
 * Function, check if need to do unit tests.
 *
 * @param [in] argc
 * @param [in] argv
 * @return if need to do unit tests.
 */
int CheckIfTestNeedToDo(int argc, const char* argv[]);

/**
 *
 *@brief Check if the file name is correct
 *
 *@param [in] str - file name pointer
 *@return if the file extension is .txt
 */
bool CheckFile (const char *str);

#endif // NEED_TEST_TO_DO_H_INCLUDED
