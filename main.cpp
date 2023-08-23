#include "SolveSquareEquation.h"

int main()
{

    OperatingInstructionForUser();      //Show the user the instructions for using the program

    SquareTrinomial UsersTrinomial;     //The User's equation which need to solve

    InputSquareTrinomialCF(&UsersTrinomial);     //Read the coefficients of polynomial

    EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial);    //Solve the square equation and calculate the number of roots

    OutputResult(CountOfRoots, UsersTrinomial);    //Print the result of program

    //GroupOfTests();

    return 0;

}
