<<<<<<< Updated upstream
=======
///@file test.h
>>>>>>> Stashed changes
#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <TXLib.h>
#include "struct.h"

<<<<<<< Updated upstream
const int NUMBER_OF_TESTS = 10;

=======
/// Number of tests
const int NUMBER_OF_TESTS = 10;

/**
 *
 *@brief check the correctness of the SolveSquareEquation()
 *
 *@param [in] CorrectTrinomial - structure in which coefficient values are found
 *@param [in] CorrectNumberOfRoots - correct root number
 *@param [in] CorrectRoots - structure in which correct roots are found
 *
 *Function starts SolveSquareEquation() and gets the number of roots and their values.
 *Then check these roots with correct roots.
 *@return roots from SolveSquareEquation() == CorrectRoots
 */
>>>>>>> Stashed changes
int CheckCorrectnessOfSolve(const SquareTrinomialCoef *CorrectTrinomial,
                            EquationRootsQuantity CorrectNumberOfRoots,
                            const RootsOfTrinomial *CorrectRoots);

<<<<<<< Updated upstream
void RunTests();

void ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
                             RootsOfTrinomial *RefRoots);
=======
/**
 *
 *@brief runs tests
 *
 */
void RunTests(const char *file_name);

/**
 *
 *@brief Read from file coefficients of square trinomial and its roots
 *
 *@param [out] SquareTrinomialCoef *RefTrinomial - structure in which coefficient values are found
 *@param [out] CorrectNumberOfRoots - correct root number
 *@param [out] RefRoots - structure in which correct roots are found
 *
 */
void ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
                             RootsOfTrinomial *RefRoots,
                             FILE *ptr_to_test);
/**
 *
 *@brief Read the number from file
 *
 *@param [in] ptr_to_test - file pointer
 *@return number
 */
double ReadNumber(FILE *ptr_to_test);

/**
 *
 *@brief print square equation
 *
 *@param [in] CorrectTrinomial - pointer to SquareTrinomialCoef struct
 *P.S. about this struct read documentation of struct.h
 */
void PrintEquation(const SquareTrinomialCoef *CorrectTrinomial);
>>>>>>> Stashed changes

#endif // TEST_H_INCLUDED
