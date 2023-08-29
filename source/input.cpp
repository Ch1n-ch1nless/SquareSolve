#include "IOput.h"

static const char* ESCYELLOW = "\033[0;33m";
static const char* ESCDEFAULT = "\033[0m";

void ReadSquareTrinomial(SquareTrinomialCoef *users_trinomial)
{
    assert((users_trinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "senior coefficient";
    users_trinomial->senior_cf = GetInput(senior_cf, 'A');
    char second_cf[] = "second coefficient";
    users_trinomial->second_cf = GetInput(second_cf, 'B');
    char free_term[] = "free term";
    users_trinomial->free_term = GetInput(free_term, 'C');
}

double GetInput(char name_of_cf[], const char symbol)
{
    double temp = NAN; //temporary variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Enter the value of the %s: %s%c%s = ",
           name_of_cf, ESCYELLOW, symbol, ESCDEFAULT); //read the coefficient
    scanf_correctness_check_result = scanf("%lg", &temp);
    while (scanf_correctness_check_result == 0) {
        clearBUF();

        printf("\nOops, you entered the coefficent wrong, try again!\n"
               "Enter the value of the %s: %s%c%s = ",
               name_of_cf, ESCYELLOW,  symbol, ESCDEFAULT);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");
    clearBUF();
    return temp;
}

void clearBUF() {
    int c = 0;
    while((c = getchar()) != '\n')
        ;
}
