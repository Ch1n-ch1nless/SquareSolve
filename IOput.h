///@file IOput.h

#ifndef IOPUT_H_INCLUDED
#define IOPUT_H_INCLUDED

#include <stdio.h>
#include <TXLib.h>
#include "struct.h"

/**
 * @brief precision const
 */

const int OUTPUT_PRECISION = 6;

/**
 * @brief show the user instruction
 */

void ShowInstructionForUser();

/**
 * @brief read the coefficients of the square trinomial
 *
 * Function accepts link to structure 'SquareTrinomialCoef' and fills its coefficients
 *
 * @param [in] UsersTrinomial
 *
 */

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial);

/**
 * @brief print the number of roots and their value
 *
 * Function accepts the structure 'RootsOfTrinomial' and enum EquationRootsQuantity CountOfRoots.
 * If CountOfRoots = NO_ROOTS or INFINITE_QUANTITY_ROOTS, doesn't print roots.
 * If CountOfRoots = ONE_ROOT, print 1 root.
 * If CountOfRoots = TWO_ROOTS, print 2 roots.
 *
 * @param [in] CountOfRoots
 * @param [in] Root
 *
 */

void PrintResult(const EquationRootsQuantity CountOfRoots, const RootsOfTrinomial Root);

/**
 *
 * @brief Read coefficient value
 *
 * @param [in] name_of_CF name of coefficient
 * @param [in] symbol short name of coefficient (for example: A = senior coefficient)
 * @param [out] temp value of coefficient
 *
 * Function prints what coefficient value the user should enter.
 * Read the value of coefficient and return this.
 *
 */

double GetInput(char name_of_CF[], const char symbol);

#endif // IOPUT_H_INCLUDED
