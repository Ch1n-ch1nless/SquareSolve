///@file IOput.h

#ifndef IOPUT_H_INCLUDED
#define IOPUT_H_INCLUDED

#include <stdio.h>
#include <TXLib.h>
#include "trinomial.h"

/**
 * @brief Precision constant  - set num of digits after dot in printf
 */
const int OUTPUT_PRECISION = 6;

/**
 * @brief Show the user guide about how to use the program
 */
void ShowInstructionForUser();

/**
 * @brief Read the coefficients of the square trinomial
 *
 * Function accepts pointer to structure 'SquareTrinomialCoef' and fills its coefficients
 *
 * @param [out] UsersTrinomial - pointer to structure 'SquareTrinomialCoef'
 */
void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial);

/**
 * @brief Print the number of roots and their value
 *
 * Function accepts the structure 'RootsOfTrinomial'.
 * If CountOfRoots = NO_ROOTS or INFINITE_QUANTITY_ROOTS, does NOT print roots.
 * If CountOfRoots = ONE_ROOT, print 1 root.
 * If CountOfRoots = TWO_ROOTS, print 2 roots.
 *
 * @param [out] root - structure 'RootsOfTrinomial'
 */
void PrintResult(const RootsOfTrinomial root);

/**
 * @brief Read coefficient value
 *
 * @param [in] name_of_CF name of coefficient
 * @param [in] symbol short name of coefficient (for example: A = senior coefficient)
 * Function prints what coefficient value the user should enter.
 * Read the value of coefficient and return this.
 * @return value of coefficient
 */
double GetNumber(const char name_of_CF[], const char symbol);

/**
 *@brief clear input buffer
 */
void ClearBuf();

/**
 *@brief show list with commands
 */
void ShowHelp();

#endif // IOPUT_H_INCLUDED
