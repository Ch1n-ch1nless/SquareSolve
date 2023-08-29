#include "IOput.h"

static const char* YEL = "\033[0;33m";

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial)
{
    assert((UsersTrinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "senior coefficient";
    UsersTrinomial->senior_cf = GetInput(senior_cf, 'A');
    char second_cf[] = "second coefficient";
    UsersTrinomial->second_cf = GetInput(second_cf, 'B');
    char free_term[] = "free term";
    UsersTrinomial->free_term = GetInput(free_term, 'C');
}

double GetInput(char name_of_cf[], const char symbol)
{
    double temp = NAN; //time variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Enter the value of the %s: %s%c\033[0m = ", name_of_cf, YEL, symbol); //read the coefficient
    scanf_correctness_check_result = scanf("%lg", &temp);
    while (scanf_correctness_check_result == 0) {
        clearBUF();

        printf("\nOops, you entered the coefficent wrong, try again!\n"
               "Enter the value of the %s: %s%c\033[0m = ", name_of_cf, YEL,  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");

    return temp;
}

void clearBUF() {
    int c = 0;
    while((c = getchar()) != '\n')
        ;
}
