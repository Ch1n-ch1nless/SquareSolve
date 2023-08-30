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
const char UNITTEST[] = "--unit_test";

/**
 * @brief Pointer to string "--help"
 *
 * This string is passed in arguments of function main().
 * When the help pointer is an argument of the main() function,
 * the program show what commands user can enter.
 *
 */
const char HELP[] = "--help";

enum FlagsOfMain {
    nothing = 0,
    help = 1,
    test = 2
};

FlagsOfMain ReadFlags(int argc, const char* argv[], const char *file_name);

/**
 *
 *@brief Check if the file name is correct
 *
 *@param [in] str - file name pointer
 *@return if the file extension is .txt
 */
bool CheckFile (const char *str);

#endif // NEED_TEST_TO_DO_H_INCLUDED
