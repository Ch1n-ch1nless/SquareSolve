<<<<<<< HEAD
#include "main.h"
=======
//=========================================================================================================
//!
//!
//=========================================================================================================

#include "SolveSquareEquation.h"
>>>>>>> 3659babd8f3d49b19163bea42c4930e613fde677

int main(int argc, const char* argv[])
{
<<<<<<< HEAD
    bool flag = CheckIfTestNeedToDo(argc, argv);

    if (flag == false)
    {
        ShowInstructionForUser();      //Show the user the instructions for using the program

        SquareTrinomialCoef UsersTrinomial;     //The User's equation which need to solve

        RootsOfTrinomial RootsOfUsersTrinomial; //The roots of SquareTrinomial

        ReadSquareTrinomial(&UsersTrinomial);     //Read the coefficients of polynomial

        EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial, &RootsOfUsersTrinomial);    //Solve the square equation and calculate the number of roots

        PrintResult(CountOfRoots, RootsOfUsersTrinomial);    //Print the result of program
    }
    else
    {
        RunTests();
    }
=======
    ShowInstructionForUser();      //Show the user the instructions for using the program

    SquareTrinomial UsersTrinomial;     //The User's equation which need to solve

    RootsOfTrinomial RootsOfUsersTrinomial;

    ReadSquareTrinomial(&UsersTrinomial);     //Read the coefficients of polynomial

    EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial, &RootsOfUsersTrinomial);    //Solve the square equation and calculate the number of roots

    PrintResult(CountOfRoots, RootsOfUsersTrinomial);    //Print the result of program

    //GroupOfTests();
>>>>>>> 3659babd8f3d49b19163bea42c4930e613fde677

    return 0;
}

bool CheckIfTestNeedToDo(int argc, const char* argv[])
{
    if (argc == 1)
    {
        return false;
    }
    return (!strcmp(argv[1], unittest));
}
