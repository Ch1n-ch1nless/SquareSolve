#include "SolveSquareEquation.h"

void OutputResultOfSqrTrinom(EquationRootsQuantity quantity, SquareTrinomial UsersTrinomial) //функция принимает количество корней уравнения и указатели на корни многочлена
{

    //Проверка коэффициентов квадратного трёхчлена на NAN
    assert((isnan(UsersTrinomial.senior_cf) == false) && "Старший коэффициент квадратного уравнения "
                                                         "=  NAN в функции OutputResult");
    assert((isnan(UsersTrinomial.second_cf) == false) && "Второй коэффициент квадратного уравнения "
                                                         "=  NAN в функции OutputResult");
    assert((isnan(UsersTrinomial.free_term) == false) && "Свободный член квадратного уравнения "
                                                         "=  NAN в функции OutputResult");

    //Проверка коэффициентов квадратного трёхчлена на конечность
    assert((isfinite(UsersTrinomial.senior_cf)) && "Старший коэффициент квадратного уравнения "
                                                   "=  INFINITY в функции OutputResult");
    assert((isfinite(UsersTrinomial.second_cf)) && "Второй коэффициент квадратного уравнения "
                                                    "=  INFINITY в функции OutputResult");
    assert((isfinite(UsersTrinomial.free_term)) && "Свободный член квадратного уравнения "
                                                    "=  INFINITY в функции OutputResult");

    switch (quantity) {

        case NO_ROOTS:
            printf("Данное уравнение не имеет корней");
            break;

        case ONE_ROOT:
            printf("Данное уравнение имеет один единственный корень: x = %.*lg",
                    OUTPUT_PRECISION, UsersTrinomial.root1);
            break;

        case TWO_ROOTS:
            printf("Данное уравнение имеет 2 корня: x1 = %.*lg и x2 = %.*lg",
                    OUTPUT_PRECISION, UsersTrinomial.root1, OUTPUT_PRECISION, UsersTrinomial.root2);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("Данное уравнение имеет бесконечное количество корней:)");
            break;

        default:
            printf("Возникли небольшие технические шоколадки!\n"
                   "Пожалуйста, не забудьте скинуть числа, которые вы ввели, "
                   "через смс на номер: 88005553535!\n"
                   "Проще самому решить, чем прогу вызывать)\b\b");

            assert("Что-то пошло не так в функции OutputResult");

    }

}

void OutputResultOfLinBinom(EquationRootsQuantity quantity, LinearBinomial UsersBinomial)
{

    //Проверка коэффициентов квадратного трёхчлена на NAN
    assert((isnan(UsersBinomial.senior_cf) == false) && "Старший коэффициент линейного уравнения "
                                                         "=  NAN в функции OutputResult");
    assert((isnan(UsersBinomial.free_term) == false) && "Свободный член линейного уравнения "
                                                         "=  NAN в функции OutputResult");

    //Проверка коэффициентов квадратного трёхчлена на конечность
    assert((isfinite(UsersBinomial.senior_cf)) && "Старший коэффициент линейного уравнения "
                                                   "=  INFINITY в функции OutputResult");
    assert((isfinite(UsersBinomial.free_term)) && "Свободный член линейного уравнения "
                                                    "=  INFINITY в функции OutputResult");

    switch (quantity) {

        case NO_ROOTS:
            printf("Данное уравнение не имеет корней");
            break;

        case ONE_ROOT:
            printf("Данное уравнение имеет один единственный корень: x = %.*lg",
                    OUTPUT_PRECISION, UsersBinomial.root);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("Данное уравнение имеет бесконечное количество корней:)");
            break;

        case TWO_ROOTS:
            printf("Невозможно!");
            assert(false);
            break;

        default:
            printf("Возникли небольшие технические шоколадки!\n"
                   "Пожалуйста, не забудьте скинуть числа, которые вы ввели, "
                   "через смс на номер: 88005553535!\n"
                   "Проще самому решить, чем прогу вызывать)\b\b");

            assert("Что-то пошло не так в функции OutputResulttOfLinBinom");

    }
}
