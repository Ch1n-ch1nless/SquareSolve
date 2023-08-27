///@file main.h

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include "IOput.h"
<<<<<<< Updated upstream
#include "SolveSquareEquation.h"
#include "test.h"

/**
 * @brief pointer to string "unittest"
 *
 * This string is inserted in arguments of function main().
=======
#include "solve_square_equation.h"
#include "test.h"

/**
 * @brief Pointer to string "unittest"
 *
 * This string is passed in arguments of function main().
>>>>>>> Stashed changes
 * When the unittest pointer is an argument of the main() function,
 * the test program is called.
 *
 */
<<<<<<< Updated upstream

const char unittest[] = "unittest";

/**
 * @brief run test.
 *
 * Function, verifying the need to call the test program.
 *
 * @param [in] argc
 * @param [in] argv
 * @return true if the unittest pointer is an argument of the main()
 * @return false in other cases
 */

bool CheckIfTestNeedToDo(int argc, const char* argv[]);

=======
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

>>>>>>> Stashed changes
#endif // MAIN_H_INCLUDED
