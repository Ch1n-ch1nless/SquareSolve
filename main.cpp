//=========================================================================================================
//!
//!
//=========================================================================================================

#include "SolveSquareEquation.h"

int main()
{
    ShowInstructionForUser();      //Show the user the instructions for using the program

    SquareTrinomial UsersTrinomial;     //The User's equation which need to solve

    RootsOfTrinomial RootsOfUsersTrinomial;

    ReadSquareTrinomial(&UsersTrinomial);     //Read the coefficients of polynomial

    EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial, &RootsOfUsersTrinomial);    //Solve the square equation and calculate the number of roots

    PrintResult(CountOfRoots, RootsOfUsersTrinomial);    //Print the result of program

    //GroupOfTests();

    return 0;

}
