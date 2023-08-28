#include "IOput.h"

static const char* YEL = "\033[0;33m";
static const char* RED = "\033[0;31m";

void PrintResult(const EquationRootsQuantity quantity, const RootsOfTrinomial Root) //function which print result of program
{
    switch (quantity) {
        case NO_ROOTS:
            printf("%sThis equation has no roots\033[0m", RED);
            break;

        case ONE_ROOT:
            printf("This equation has one single root: %sx = %.*lg\033[0m",
                    YEL, OUTPUT_PRECISION, Root.first);
            break;

        case TWO_ROOTS:
            printf("This equation has 2 roots: %s x1 = %.*lg\033[0m è %sx2 = %.*lg\033[0m",
                    YEL, OUTPUT_PRECISION, Root.first, YEL, OUTPUT_PRECISION, Root.second);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("This equation has an infinite number of roots:)");
            break;

        default:
            printf("There’s been some technical problems!\n"
                   "Please remember to reset the numbers you entered, "
                   "via sms to number: 88005553535!\n"
                   "It is easier to decide for yourself than to call the program)\b\b");

            assert(false && "\033[0;31mSomething went wrong in the function OutputResult\033[0m");
            break;
    }
}

void ShowInstructionForUser()
{
    printf("# SolveSquareEquation program version 1.11\n"
           "# Directed by Aleksandrov Oleg\n\n"
           "Hello, you have launched a program to solve the square equation."
           "This program finds roots up to %d characters!\n"
           "The square equation is as follows: %sA\033[0m * x^2 + %sB\033[0m * x + %sC\033[0m = 0, "
           "where %sA\033[0m,  %sB\033[0m,\033[0m è %sC\033[0m - some numbers\n"
           "In order for the program to solve the square equation, "
           "you must enter a numerical value of three.\n"
           "The program cannot solve the equation if you enter not a number, "
           "but \"pi\", \"exp\", \"4/3\",\"sqrt(2)\", etc.\n"
           "You must enter an integer (0 or -123 or 228 etc.)"
           "or a real number in a decimal notation with a dot delimiter "
           "Example: 1.5 (1.5 - incorrect writing)!\n",
           OUTPUT_PRECISION, YEL, YEL, YEL, YEL, YEL, YEL);
}
