#include "IOput.h"
#include "colors.h"

void ReadSquareTrinomial(SquareTrinomialCoef *users_trinomial)
{
    assert((users_trinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "senior coefficient";
    users_trinomial->senior_cf = GetNumber(senior_cf, 'A');
    char second_cf[] = "second coefficient";
    users_trinomial->second_cf = GetNumber(second_cf, 'B');
    char free_term[] = "free term";
    users_trinomial->free_term = GetNumber(free_term, 'C');
}

double GetNumber(char name_of_cf[], const char symbol)
{
    double temp = 0; //temporary variable
    int _minus = 1;
    bool check_symbol = true;
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Enter the value of the %s: %s%c%s = ",
           name_of_cf, ESCYELLOW, symbol, ESCDEFAULT); //read the coefficient
    while (!scanf_correctness_check_result) {
        int check_space_or_tab = false;
        int count_number = 0;
        int c = 0;
        while ((c = getchar()) != '\n') {
            if ('0' <= c && c <= '9') {
                if (count_number < 1) {
                    int x = c - '0';
                    temp *= 10;
                    temp += x;
                    if (check_space_or_tab) {
                        count_number++;
                        check_space_or_tab = false;
                    }
                } else {
                    check_symbol = false;
                    break;
                }
            } else if (c == '-' && _minus == 1) {
                _minus = -1;
            } else if ((c == ' ' or c == '\t') && count_number <= 1) {
                check_space_or_tab = true;
            }else {
                check_symbol = false;
                break;
            }
        }
        if (!check_symbol) {
            ClearBUF();
            printf("Oops, you have incorrectly entered coefficient!\n");
            printf("Enter the value of the %s: %s%c%s = ",
                    name_of_cf, ESCYELLOW, symbol, ESCDEFAULT);
        } else {
            scanf_correctness_check_result = true;
        }
    }
    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");
    return _minus * temp;
}

void ClearBUF() {
    int c = 0;
    while((c = getchar()) != '\n')
        ;
}
