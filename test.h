#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <TXLib.h>
#include "struct.h"

const int NUMBER_OF_TESTS = 10;

int CheckCorrectnessOfSolve(const SquareTrinomialCoef *CorrectTrinomial,
                            EquationRootsQuantity CorrectNumberOfRoots,
                            const RootsOfTrinomial *CorrectRoots);

void RunTests();

void ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
                             RootsOfTrinomial *RefRoots);

#endif // TEST_H_INCLUDED
