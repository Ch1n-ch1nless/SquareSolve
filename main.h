///@file main.h

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include "IOput.h"
#include "SolveSquareEquation.h"
#include "test.h"

/**
 * @brief pointer to string "unittest"
 *
 * This string is inserted in arguments of function main().
 * When the unittest pointer is an argument of the main() function,
 * the test program is called.
 *
 */

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

#endif // MAIN_H_INCLUDED
