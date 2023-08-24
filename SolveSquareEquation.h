<<<<<<< HEAD
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
=======
#ifndef SOLVESQUAREEQUATION_H_INCLUDED

#define SOLVESQUAREEQUATION_H_INCLUDED

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <TXLib.h>

const int OUTPUT_PRECISION = 6;
const double EPS = 1e-7;



enum EquationRootsQuantity {

    INFINITE_ROOTS_QUANTITY = -1,
    NO_ROOTS, // TODO: give a number to all of your elements
    ONE_ROOT,
    TWO_ROOTS

};

struct SquareTrinomial {

    double senior_cf = NAN;     //senior coefficient of polynomial
    double second_cf = NAN;     //second coefficient of polynomial
    double free_term = NAN;     //free term of polynomial

};

struct RootsOfTrinomial {

    double first = NAN;     //first root of equation
    double second = NAN;    //second root of equation

};

void ShowInstructionForUser();

void ReadSquareTrinomial(SquareTrinomial *UsersTrinomial);

EquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial, RootsOfTrinomial *Root);

EquationRootsQuantity SolveLinearEquation(SquareTrinomial *UsersTrinomial, RootsOfTrinomial *Root);

void PrintResult(EquationRootsQuantity CountOfRoots, RootsOfTrinomial Root);

bool CompareDouble(double number1, double number2);

double GetInput(char name_of_CF[], char symbol);

void MakeMinRoot1AndMaxRoot2(RootsOfTrinomial *Root);

int CheckCorrectnessOfSolve(SquareTrinomial *CorrectTrinomial, EquationRootsQuantity CorrectNumberOfRoots, RootsOfTrinomial *CorrectRoots);

void GroupOfTests();

bool IsZero(double number);


#endif // SOLVESQUAREEQUATION_H_INCLUDED
>>>>>>> 3659babd8f3d49b19163bea42c4930e613fde677
