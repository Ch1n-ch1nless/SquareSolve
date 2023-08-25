///@file SolveSquareEquation.h
#ifndef SOLVESQUAREEQUATION_H_INCLUDED

#define SOLVESQUAREEQUATION_H_INCLUDED

#include <assert.h>
#include <math.h>
#include "struct.h"

/**
 *
 *@brief comparison constant
 *
 */

const double EPS = 1e-7;

/**
 *
 *@brief solve square equation
 *
 *@param [in] UsersTrinomial structure in which coefficient values are found
 *@param [in] Root structure with root values
 *@param [out] EquationRootsQuantity number of roots
 *
 * Algorithm:
 *  If the senior coefficient is 0, then starts SolveLinearEquation().
 *  Else calculate value of discriminant.
 *  If discriminant < 0 return NO_ROOTS.
 *  If discriminant = 0 calculate calculates the root value by formula and return ONE_ROOT.
 *  Else calculates the values of roots by formula and return TWO_ROOTS.
 *
 */

EquationRootsQuantity SolveSquareEquation(SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root);

/**
 *
 *@brief solve linear equation
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

EquationRootsQuantity SolveLinearEquation(SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root);

/**
 *
 *check the 2-number difference for equality with 0
 *
 *@param [in] number1
 *@param [in] number2
 *@return true if fabs(number1-number2) < comparison const
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

void MakeMinRoot1AndMaxRoot2(RootsOfTrinomial *Root);

/**
 *
 *@brief check the number for equality with 0
 *
 *@param [in] number
 *@return true if fabs(number) < comparison const
 *
 */

bool IsZero(const double number);


#endif // SOLVESQUAREEQUATION_H_INCLUDED
