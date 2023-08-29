#include "need_test_to_do.h"

int main(int argc, const char* argv[])
{
    int need_test = CheckIfTestNeedToDo(argc, argv);

    if (need_test == 0) {
        ShowInstructionForUser();      //Show the user the instructions for using the program

        SquareTrinomialCoef users_trinomial;     //The User's equation which need to solve
        RootsOfTrinomial roots_of_trinomial; //The roots of SquareTrinomial

        ReadSquareTrinomial(&users_trinomial);     //Read the coefficients of polynomial
        SolveSquareEquation(&users_trinomial, &roots_of_trinomial);    //Solve the square equation

        PrintResult(roots_of_trinomial);    //Print the result of program
    } else if (need_test == 1){
        if (argc >= 3) {
            const char *file_name = argv[2];
            if (CheckFile(file_name)) {
                RunTests(argv[2]);
            }
        } else {
        printf("You print incorrect arguments!");
        }
    } else {
        if (!strcmp(argv[1], help)) {
            ShowHelp();
        } else {
            printf("You print incorrect arguments!");
        }
    }

    return 0;
}

int CheckIfTestNeedToDo(int argc, const char* argv[])
{
    if (argc == 1) {
        return 0;
    }
    return (!strcmp(argv[1], unittest)) ? 1 : -1;
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

