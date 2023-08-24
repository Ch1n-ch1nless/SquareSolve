#ifndef IOPUT_H_INCLUDED
#define IOPUT_H_INCLUDED

#include <stdio.h>
#include <TXLib.h>
#include "struct.h"

const int OUTPUT_PRECISION = 6;

void ShowInstructionForUser();

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial);

void PrintResult(const EquationRootsQuantity CountOfRoots, const RootsOfTrinomial Root);

double GetInput(char name_of_CF[], const char symbol);

#endif // IOPUT_H_INCLUDED
