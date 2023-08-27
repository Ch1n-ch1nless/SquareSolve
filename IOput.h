///@file IOput.h

#ifndef IOPUT_H_INCLUDED
#define IOPUT_H_INCLUDED

#include <stdio.h>
#include <TXLib.h>
#include "struct.h"

/**
<<<<<<< Updated upstream
 * @brief precision const
=======
 * @brief Precision constant  - set num of digits after dot in printf
>>>>>>> Stashed changes
 */

const int OUTPUT_PRECISION = 6;

/**
<<<<<<< Updated upstream
 * @brief show the user instruction
=======
 * @brief Show the user guide about how to use the program
>>>>>>> Stashed changes
 */

void ShowInstructionForUser();

/**
<<<<<<< Updated upstream
 * @brief read the coefficients of the square trinomial
 *
 * Function accepts link to structure 'SquareTrinomialCoef' and fills its coefficients
 *
 * @param [in] UsersTrinomial
=======
 * @brief Read the coefficients of the square trinomial
 *
 * Function accepts pointer to structure 'SquareTrinomialCoef' and fills its coefficients
 *
 * @param [out] UsersTrinomial - pointer to structure 'SquareTrinomialCoef'
>>>>>>> Stashed changes
 *
 */

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial);

/**
<<<<<<< Updated upstream
 * @brief print the number of roots and their value
 *
 * Function accepts the structure 'RootsOfTrinomial' and enum EquationRootsQuantity CountOfRoots.
 * If CountOfRoots = NO_ROOTS or INFINITE_QUANTITY_ROOTS, doesn't print roots.
 * If CountOfRoots = ONE_ROOT, print 1 root.
 * If CountOfRoots = TWO_ROOTS, print 2 roots.
 *
 * @param [in] CountOfRoots
 * @param [in] Root
=======
 * @brief Print the number of roots and their value
 *
 * Function accepts the structure 'RootsOfTrinomial' and enum EquationRootsQuantity CountOfRoots.
 * If CountOfRoots = NO_ROOTS or INFINITE_QUANTITY_ROOTS, does NOT print roots.
 * If CountOfRoots = ONE_ROOT, print 1 root.
 * If CountOfRoots = TWO_ROOTS, print 2 roots.
 *
 * @param [in] CountOfRoots - enum EquationRootsQuantity
 * @param [in] Root - structure 'RootsOfTrinomial'
>>>>>>> Stashed changes
 *
 */

void PrintResult(const EquationRootsQuantity CountOfRoots, const RootsOfTrinomial Root);

/**
 *
 * @brief Read coefficient value
 *
 * @param [in] name_of_CF name of coefficient
 * @param [in] symbol short name of coefficient (for example: A = senior coefficient)
<<<<<<< Updated upstream
 * @param [out] temp value of coefficient
 *
 * Function prints what coefficient value the user should enter.
 * Read the value of coefficient and return this.
 *
=======
 *
 * Function prints what coefficient value the user should enter.
 * Read the value of coefficient and return this.
 * @return value of coefficient
>>>>>>> Stashed changes
 */

double GetInput(char name_of_CF[], const char symbol);

#endif // IOPUT_H_INCLUDED
