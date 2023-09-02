#include "need_test_to_do.h"

int main(int argc, const char* argv[])
{
    int ptr_to_file_name = 0;

    ModsOfMain what_option_run = ReadArgs(argc, argv, &ptr_to_file_name);

    switch(what_option_run) {
        case MOD_SQUARE:
        {
            ShowInstructionForUser();                                      //Show the user the instructions for using the program

            SquareTrinomialCoef users_trinomial;         //The User's equation which need to solve
            RootsOfTrinomial roots_of_trinomial;    //The roots of SquareTrinomial

            ReadSquareTrinomial(&users_trinomial);                         //Read the coefficients of polynomial
            SolveSquareEquation(&users_trinomial, &roots_of_trinomial);    //Solve the square equation

            PrintResult(roots_of_trinomial);                               //Print the result of program
            break;
        }

        case MOD_HELP:
        {
            ShowHelp();
            break;
        }

        case MOD_UNITTEST:
        {
            RunTests(argv[ptr_to_file_name]);
            break;
        }

        case MOD_END:
        {
            printf("You print incorrect arguments!\n");
            printf("Please, read the guide:\n");
            ShowHelp();
            break;
        }

        default:
        {
            printf("You print incorrect arguments!\n");
            printf("Please, read the guide:\n");
            ShowHelp();
            break;
        }
    }
    return 0;
}

ModsOfMain ReadArgs(int argc, const char* argv[], int *ptr_to_file_name)
{
    int mod = MOD_END;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], OPTION_HELP)) {
            mod = min(mod, (int) MOD_HELP);
        } else if (!strcmp(argv[i], OPTION_UNITTEST)){
            mod = min(mod, (int) MOD_UNITTEST);
            if (mod == (int) MOD_UNITTEST) {
                i++;
                if (CheckFile(argv[i])) {
                    *ptr_to_file_name = i;
                } else {
                    mod = MOD_END;
                    break;
                }
            } else {
                mod = MOD_END;
                break;
            }
        }
    }
    if (mod == MOD_END && argc == 1) {
        mod = 0;
    }
    return (ModsOfMain) mod;
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
        const char *testfile_extension = "txt";
        return (!strcmp(last_point_ptr, testfile_extension));
    }
}

