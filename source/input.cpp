#include "IOput.h"
#include "colors.h"

void ReadSquareTrinomial(SquareTrinomialCoef *users_trinomial)
{
    assert((users_trinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    users_trinomial->senior_cf = GetNumber("senior coefficient", 'A');
    users_trinomial->second_cf = GetNumber("second coefficient", 'B');
    users_trinomial->free_term = GetNumber("free term", 'C');
}

double GetNumber(const char name_of_cf[], const char symbol)
{
    double temp = 0; //temporary variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Enter the value of the %s: %s%c%s = ",
           name_of_cf, ESCYELLOW, symbol, ESCDEFAULT); //read the coefficient
    while (!scanf_correctness_check_result) {
        scanf_correctness_check_result = scanf("%lg", &temp);
        if (!scanf_correctness_check_result) {
            printf("Oops, you have incorrectly entered coefficients!\n");
            printf("Enter the value of the %s: %s%c%s = ",
                    name_of_cf, ESCYELLOW, symbol, ESCDEFAULT);
            ClearBuf();
            continue;
        }
        int c = 0;
        while ((c = getchar()) != '\n') {
            if (c != ' ' && c != '\t') {
                scanf_correctness_check_result = false;
                printf("Oops, you have incorrectly entered coefficients!\n");
                printf("Enter the value of the %s: %s%c%s = ",
                        name_of_cf, ESCYELLOW, symbol, ESCDEFAULT);
                ClearBuf();
                break;
            } else {
                scanf_correctness_check_result = true;
            }
        }
    }
    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");
    return temp;
}

void ClearBuf() {
    int c = 0;
    while((c = getchar()) != '\n')
        ;
}
