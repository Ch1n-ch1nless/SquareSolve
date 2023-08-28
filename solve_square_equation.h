///@file SolveSquareEquation.h
#ifndef SOLVESQUAREEQUATION_H_INCLUDED

#define SOLVESQUAREEQUATION_H_INCLUDED

#include <assert.h>
#include <math.h>

#include "struct.h"

/**
 *
 *@brief Accuracy of the comparison
 *
 */
const double EPS = 1e-7;

/**
 *
 *@brief Solve square equation
 *
 *@param [in] UsersTrinomial - structure in which coefficient values are found
 *@param [out] Root - structure with root values
 *@return EquationRootsQuantity number of roots
 *
 * Algorithm:
 *  If the senior coefficient is 0, then starts SolveLinearEquation().
 *  Else calculate value of Discriminant.
 *  If Discriminant < 0 return NO_ROOTS.
 *  If Discriminant = 0 calculate calculates the root value by formula and return ONE_ROOT.
 *  Else calculates the values of roots by formula and return TWO_ROOTS.
 *
 */
EquationRootsQuantity SolveSquareEquation(const SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root);

/**
 *
 *@brief Solve linear equation
 *
 *@param [in] UsersTrinomial structure in which coefficient values are found
 *@param [in] Root structure with root values
 *@param [out] EquationRootsQuantity number of roots
 *
 *The function solves a linear equation.
 *If the coefficient before x is not 0, then return ONE_ROOT. value of root = -free term / coefficient.
 *If the coefficient before x is 0 and free term is 0, then return INFINITE_ROOTS_QUANTITY.
 *In other cases return NO_ROOTS.
 *
 */
EquationRootsQuantity SolveLinearEquation(const SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root);

/**
 *
 *check the 2-number difference for equality with 0
 *
 *@param [in] number1
 *@param [in] number2
 *@return fabs(number1-number2) < comparison const
 *
 */
bool CompareDouble(const double number1, const double number2);

/**
 *
 *@brief regulates roots in ascending order
 *
 *@param [in] Root structure with root value
 *
 *Function accepts the structure 'RootsOfTrinomial'.
 *If root1 > root2, then root1 and root2 change the value (swap)
 *
 */
void SortRoots(RootsOfTrinomial *Root);

/**
 *
 *@brief check the number for equality with 0
 *
 *@param [in] number
 *@return fabs(number) < comparison const
 *
 */
bool IsZero(const double number);


#endif // SOLVESQUAREEQUATION_H_INCLUDED
