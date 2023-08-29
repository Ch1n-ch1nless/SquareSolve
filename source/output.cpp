#include "IOput.h"

static const char* ESCYELLOW = "\033[0;33m";
static const char* ESCRED = "\033[0;31m";
static const char* ESCDEFAULT = "\033[0m";
static const char* ESCGREEN = "\033[0;32m";

#define REDASSERT(str) "\033[0;31m" %str "\033[0m"

void PrintResult(const RootsOfTrinomial root) //function which print result of program
{
    switch (root.number) {
        case NO_ROOTS:
            printf("%sThis equation has no roots%s", ESCRED, ESCDEFAULT);
            break;

        case ONE_ROOT:
            printf("This equation has one single root: %sx = %.*lg%s",
                    ESCYELLOW, OUTPUT_PRECISION, root.first, ESCDEFAULT);
            break;

        case TWO_ROOTS:
            printf("This equation has 2 roots: %s x1 = %.*lg%s è %sx2 = %.*lg%s",
                    ESCYELLOW, OUTPUT_PRECISION, root.first, ESCDEFAULT, ESCYELLOW,
                    OUTPUT_PRECISION, root.second, ESCDEFAULT);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("This equation has an infinite number of roots:)");
            break;

        default:
            printf("There’s been some technical problems!\n"
                   "Please remember to reset the numbers you entered, "
                   "via sms to number: 88005553535!\n"
                   "It is easier to decide for yourself than to call the program)\b\b");

            assert(false && REDASSERT("Something went wrong in the function OutputResult"));
            break;
    }
}

void ShowInstructionForUser()
{
    printf("# SolveSquareEquation program version 1.14\n"
           "# Directed by Aleksandrov Oleg\n\n"
           "Hello, you have launched a program to solve the square equation.\n"
           "This program finds roots up to %s%d%s characters!\n"
           "%sA%s * x^2 + %sB%s * x + %sC%s = 0, "
           "where %sA%s, %sB%s, è %sC%s - some%s numbers%s\n"
           "The program cannot solve the equation if you enter%s not%s a%s number%s, "
           "but \"pi\", \"exp\", \"4/3\",\"sqrt(2)\", etc.\n"
           "You must enter an integer (0 or -123 or 228 etc.)"
           "or a real number in a decimal notation with a dot delimiter "
           "%sExample:%s 1.5 (1,5 - incorrect writing)!\n",
           ESCGREEN, OUTPUT_PRECISION, ESCDEFAULT, ESCYELLOW, ESCDEFAULT, ESCYELLOW, ESCDEFAULT,
           ESCYELLOW, ESCDEFAULT, ESCYELLOW, ESCDEFAULT, ESCYELLOW, ESCDEFAULT, ESCYELLOW, ESCDEFAULT,
           ESCGREEN, ESCDEFAULT, ESCRED, ESCDEFAULT, ESCGREEN, ESCDEFAULT, ESCYELLOW, ESCDEFAULT);
}
