#include "IOput.h"

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial)
{
    assert((UsersTrinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "старшего коэффициента";
    UsersTrinomial->senior_cf = GetInput(senior_cf, 'A');
    char second_cf[] = "второго коэффициента";
    UsersTrinomial->second_cf = GetInput(second_cf, 'B');
    char free_term[] = "свободного члена";
    UsersTrinomial->free_term = GetInput(free_term, 'C');
}

double GetInput(char name_of_cf[], const char symbol)
{
    double temp = NAN; //time variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Введите значение %s многочлена: %c = ", name_of_cf, symbol); //read the coefficient
    scanf_correctness_check_result = scanf("%lg", &temp);
    while (scanf_correctness_check_result == 0)
    {
        int c;
        while((c = getchar()) != '\n')
            ;

        printf("\nУпс, вы неверно ввели значение коэффицента, повторите попытку!\n"
               "Введите значение %s многочлена: %c = ", name_of_cf,  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");

    return temp;
}
