#include "main.h"

int main(int argc, const char* argv[])
{
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
