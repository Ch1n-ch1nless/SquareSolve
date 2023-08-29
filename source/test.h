///@file test.h

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <TXLib.h>
#include "trinomial.h"

/**
 *
 *@brief check the correctness of the SolveSquareEquation()
 *
 *@param [in] CorrectTrinomial - structure in which coefficient values are found
 *@param [in] CorrectRoots - structure in which correct roots are found
 *
 *Function starts SolveSquareEquation() and gets the number of roots and their values.
 *Then check these roots with correct roots.
 *@return roots from SolveSquareEquation() == correct roots
 */
int CheckCorrectnessOfSolve(const SquareTrinomialCoef *correct_trinomial,
                            const RootsOfTrinomial *correct_root);
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
 *@param [in] FILE - file pointer
 *
 */
bool ReadCorrectSqrTrinomial(SquareTrinomialCoef *ref_trinomial,
                             RootsOfTrinomial *ref_roots,
                             FILE *ptr_to_test);
/**
 *
 *@brief Read the number from file
 *
 *@param [in] ptr_to_test - file pointer
 *@return number
 */
double ReadNumber(FILE *ptr_to_test, int *check_correct_numbers_test);

/**
 *
 *@brief print square equation
 *
 *@param [in] CorrectTrinomial - pointer to SquareTrinomialCoef struct
 *P.S. about this struct read documentation of struct.h
 */
void PrintEquation(const SquareTrinomialCoef *correct_trinomial);

#endif // TEST_H_INCLUDED
