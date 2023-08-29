#include "main.h"

int main(int argc, const char* argv[])
{
    bool flag = CheckIfTestNeedToDo(argc, argv);

    if (flag == false) {
        ShowInstructionForUser();      //Show the user the instructions for using the program

        SquareTrinomialCoef UsersTrinomial;     //The User's equation which need to solve
        RootsOfTrinomial RootsOfUsersTrinomial; //The roots of SquareTrinomial

        ReadSquareTrinomial(&UsersTrinomial);     //Read the coefficients of polynomial
        EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial, &RootsOfUsersTrinomial);    //Solve the square equation and calculate the number of roots

        PrintResult(CountOfRoots, RootsOfUsersTrinomial);    //Print the result of program
    } else {
        if (argc >= 3) {
            const char *file_name = argv[2];
            if (CheckFile(file_name)) {
                RunTests(argv[2]);
            }
        }
        printf("You print incorrect arguments!");
    }

    return 0;
}

bool CheckIfTestNeedToDo(int argc, const char* argv[])
{
    if (argc == 1) {
        return false;
    }
    return (!strcmp(argv[1], unittest));
}

bool CheckFile(const char *str)
{
    assert((str != nullptr) && "String pointer is nullptr");
    const char *last_point_ptr = nullptr;
    char point = '.';
    const char *ptr = strchr(str, point);

    while (ptr != nullptr) {
        ptr++;
        last_point_ptr = ptr;
        ptr = strchr(ptr,  point);
    }

    if (last_point_ptr == nullptr) {
        return false;
    } else {
        const char *Txt = "txt";
        return (!strcmp(last_point_ptr, Txt));
    }
}

