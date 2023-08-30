#include "need_test_to_do.h"

int main(int argc, const char* argv[])
{
    int ptr_to_file_name = 0;

    FlagsOfMain what_option_run = ReadFlags(argc, argv, &ptr_to_file_name);

    switch(what_option_run) {
        case FLAG_NOTHING:
        {
            ShowInstructionForUser();                                      //Show the user the instructions for using the program

            SquareTrinomialCoef users_trinomial;                           //The User's equation which need to solve
            RootsOfTrinomial roots_of_trinomial;                           //The roots of SquareTrinomial

            ReadSquareTrinomial(&users_trinomial);                         //Read the coefficients of polynomial
            SolveSquareEquation(&users_trinomial, &roots_of_trinomial);    //Solve the square equation

            PrintResult(roots_of_trinomial);                               //Print the result of program
            break;
        }

        case FLAG_HELP:
        {
            ShowHelp();
            break;
        }

        case FLAG_UNITTEST:
        {
            RunTests(argv[ptr_to_file_name]);
            break;
        }

        case FLAG_END:
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



FlagsOfMain ReadFlags(int argc, const char* argv[], int *ptr_to_file_name)
{
    int temp_flag = FLAG_END;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], OPTION_HELP)) {
            temp_flag = min(temp_flag, (int) FLAG_HELP);
        } else if (!strcmp(argv[i], OPTION_UNITTEST)){
            temp_flag = min(temp_flag, (int) FLAG_UNITTEST);
            if (temp_flag == (int) FLAG_UNITTEST) {
                i++;
                if (CheckFile(argv[i])) {
                    *ptr_to_file_name = i;
                } else {
                    temp_flag = FLAG_END;
                    break;
                }
            } else {
                temp_flag = FLAG_END;
                break;
            }
        }
    }
    if (temp_flag == FLAG_END && argc == 1) {
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
        const char *testfile_extension = "txt";
        return (!strcmp(last_point_ptr, testfile_extension));
    }
}

