#ifndef SOLVESQUAREEQUATION_H_INCLUDED

#define SOLVESQUAREEQUATION_H_INCLUDED

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <TXLib.h>

const int OUTPUT_PRECISION = 6;



enum EquationRootsQuantity {

    INFINITE_ROOTS_QUANTITY = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS

};

struct SquareTrinomial {

    double senior_cf = NAN;     //senior coefficient of polynomial
    double second_cf = NAN;     //second coefficient of polynomial
    double free_term = NAN;     //free term of polynomial
    double root1 = NAN;         //root #1 of polynomial
    double root2 = NAN;         //root #2 of polynomial

};



void OperatingInstructionForUser();

void InputSquareTrinomialCF(SquareTrinomial *UsersTrinomial);

EquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial);

EquationRootsQuantity SolveLinearEquation(SquareTrinomial *UsersTrinomial);

void OutputResult(EquationRootsQuantity CountOfRoots, SquareTrinomial UsersTrinomial);

bool CompareDouble(double number1, double number2);

double GetInput(char name_of_CF[], char symbol);

void AssertSquareTrinomial(SquareTrinomial InterestingTrinom);

void AssertPtrSquareTrinomial(SquareTrinomial *InterestingTrinom);

void AssertDouble(double number);

void MakeMinRoot1AndMaxRoot2(SquareTrinomial *UsersTrinomial);

int CheckCorrectnessOfSolve(SquareTrinomial *CorrectTrinomial, EquationRootsQuantity CorrectNumberOfRoots);

void GroupOfTests();


#endif // SOLVESQUAREEQUATION_H_INCLUDED
