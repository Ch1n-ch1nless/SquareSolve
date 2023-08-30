#include "need_test_to_do.h"

int main(int argc, const char* argv[])
{
    const char *file_name = "";

    FlagsOfMain what_program_run = ReadFlags(argc, argv, file_name);

    switch(what_program_run) {
        case nothing:
        {
            ShowInstructionForUser();      //Show the user the instructions for using the program

            SquareTrinomialCoef users_trinomial;     //The User's equation which need to solve
            RootsOfTrinomial roots_of_trinomial; //The roots of SquareTrinomial

            ReadSquareTrinomial(&users_trinomial);     //Read the coefficients of polynomial
            SolveSquareEquation(&users_trinomial, &roots_of_trinomial);    //Solve the square equation

            PrintResult(roots_of_trinomial);    //Print the result of program
        }
            break;

        case help:
            ShowHelp();
            break;

        case test:
            RunTests(file_name);
            break;

        default:
            printf("You print incorrect arguments!\n");
            printf("Please, read the guide:\n");
            ShowHelp();
    }
    return 0;
}

FlagsOfMain ReadFlags(int argc, const char* argv[], const char *file_name)
{
    int temp_flag = 3;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], HELP)) {
            temp_flag = min(temp_flag, 1);
        } else if (!strcmp(argv[i], UNITTEST)){
            temp_flag = min(temp_flag, 2);
        } else if (CheckFile(argv[i])) {
            file_name = argv[i];
        }
    }
    if (temp_flag == 3 && argc == 1) {
        temp_flag = 0;
    }
    return (FlagsOfMain) temp_flag;
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

