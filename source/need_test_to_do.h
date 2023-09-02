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
const char OPTION_UNITTEST[] = "--unit_test";

/**
 * @brief Pointer to string "--help"
 *
 * This string is passed in arguments of function main().
 * When the help pointer is an argument of the main() function,
 * the program show what commands user can enter.
 *
 */
const char OPTION_HELP[] = "--help";

/// FLAGS - which option need to run
enum ModsOfMain {
    MOD_SQUARE = 0,   //!< run default option - solve square equation
    MOD_HELP = 1,     //!< show options
    MOD_UNITTEST = 2, //!< run UNITtests

    MOD_END           //!< error! User print incorrect arguments
};

/**
 *@brief read flags from terminal
 *
 *@param [in] argc
 *@param [in] argv
 *@param [out] file_name
 *@return Flag - enum FlagsOfMain
 *
 *Function reads all flags from terminal and returns a variable
 * that will then specify which program to call
 */
ModsOfMain ReadArgs(int argc, const char* argv[], int *ptr_to_file_name);

/**
 *
 *@brief Check if the file name is correct
 *
 *@param [in] str - file name pointer
 *@return if the file extension is .txt
 */
bool CheckFile (const char *str);

#endif // NEED_TEST_TO_DO_H_INCLUDED
