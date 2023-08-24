<<<<<<< HEAD
#include "IOput.h"

void ReadSquareTrinomial(SquareTrinomialCoef *UsersTrinomial)
{
    assert((UsersTrinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "ñòàğøåãî êîıôôèöèåíòà";
    UsersTrinomial->senior_cf = GetInput(senior_cf, 'A');
    char second_cf[] = "âòîğîãî êîıôôèöèåíòà";
    UsersTrinomial->second_cf = GetInput(second_cf, 'B');
    char free_term[] = "ñâîáîäíîãî ÷ëåíà";
    UsersTrinomial->free_term = GetInput(free_term, 'C');
}

double GetInput(char name_of_cf[], const char symbol)
{
    double temp = NAN; //time variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Ââåäèòå çíà÷åíèå %s ìíîãî÷ëåíà: %c = ", name_of_cf, symbol); //read the coefficient
    scanf_correctness_check_result = scanf("%lg", &temp);
    while (scanf_correctness_check_result == 0)
    {
        int c;
        while((c = getchar()) != '\n')
            ;

        printf("\nÓïñ, âû íåâåğíî ââåëè çíà÷åíèå êîıôôèöåíòà, ïîâòîğèòå ïîïûòêó!\n"
               "Ââåäèòå çíà÷åíèå %s ìíîãî÷ëåíà: %c = ", name_of_cf,  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");

    return temp;
}
=======
#include "SolveSquareEquation.h"

void ReadSquareTrinomial(SquareTrinomial *UsersTrinomial)
{

    assert((UsersTrinomial != nullptr) && "Pointer to polynomial is nullptr!!!");

    char senior_cf[] = "ñòàğøåãî êîıôôèöèåíòà";
    UsersTrinomial->senior_cf = GetInput(senior_cf, 'A');
    char second_cf[] = "âòîğîãî êîıôôèöèåíòà";
    UsersTrinomial->second_cf = GetInput(second_cf, 'B');
    char free_term[] = "ñâîáîäíîãî ÷ëåíà";
    UsersTrinomial->free_term = GetInput(free_term, 'C');

}

double GetInput(char name_of_cf[], char symbol)
{

    double temp = NAN; //time variable
    bool scanf_correctness_check_result = false; //value which check the correctness of input

    printf("Ââåäèòå çíà÷åíèå %s ìíîãî÷ëåíà: %c = ", name_of_cf, symbol); //read the coefficient
    scanf_correctness_check_result = scanf("%lg", &temp);
    while (scanf_correctness_check_result == false) {
        printf("\nÓïñ, âû íåâåğíî ââåëè çíà÷åíèå êîıôôèöåíòà, ïîâòîğèòå ïîïûòêó!\n"
               "Ââåäèòå çíà÷åíèå %s ìíîãî÷ëåíà: %c= ", name_of_cf,  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "temp = NAN");
    assert((isfinite(temp)) && "temp = INFINITY");

    return temp;

}

>>>>>>> 3659babd8f3d49b19163bea42c4930e613fde677
