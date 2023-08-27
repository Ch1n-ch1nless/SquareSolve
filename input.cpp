#include "IOput.h"

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial)
{
    assert((UsersTrinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "�������� ������������";
    UsersTrinomial->senior_cf = GetInput(senior_cf, 'A');
    char second_cf[] = "������� ������������";
    UsersTrinomial->second_cf = GetInput(second_cf, 'B');
    char free_term[] = "���������� �����";
    UsersTrinomial->free_term = GetInput(free_term, 'C');
}

double GetInput(char name_of_cf[], const char symbol)
{
    double temp = NAN; //time variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("������� �������� %s ����������: %c = ", name_of_cf, symbol); //read the coefficient
    scanf_correctness_check_result = scanf("%lg", &temp);
<<<<<<< Updated upstream
    while (scanf_correctness_check_result == 0)
    {
=======
    while (scanf_correctness_check_result == 0) {
>>>>>>> Stashed changes
        int c;
        while((c = getchar()) != '\n')
            ;

        printf("\n���, �� ������� ����� �������� �����������, ��������� �������!\n"
               "������� �������� %s ����������: %c = ", name_of_cf,  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");

    return temp;
}