#ifndef SOLVESQUAREEQUATION_H_INCLUDED

#define SOLVESQUAREEQUATION_H_INCLUDED

#include <assert.h>
#include <math.h>
#include "struct.h"

const double EPS = 1e-7;

EquationRootsQuantity SolveSquareEquation(SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root);

EquationRootsQuantity SolveLinearEquation(SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root);

bool CompareDouble(const double number1, const double number2);

void MakeMinRoot1AndMaxRoot2(RootsOfTrinomial *Root);

bool IsZero(const double number);


#endif // SOLVESQUAREEQUATION_H_INCLUDED
