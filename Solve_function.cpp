#include "SolveSquareEquation.h"

const double EPS = 1e-7;

bool CompareDouble(double number1, double number2) //функция для проверки на равенство 2 вещественных чисел
{

    //Проверка чисел на значение NAN
    assert((isnan(number1) == false) && "Переменная number1 в функции CompareDouble() имеет значение NAN");
    assert((isnan(number2) == false) && "Переменная number2 в функции CompareDouble() имеет значение NAN");

    //Проверка чисел на значение на NAN
    assert((isfinite(number1)) && "Переменная number1 в функции CompareDouble() имеет значение INFINITY");
    assert((isfinite(number2)) && "Переменная number2 в функции CompareDouble() имеет значение INFINITY");

    return (fabs(number1 - number2) < EPS) ? true : false;

}

EquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial)
{

    // Проверка на нулевой указатель
    assert((UsersTrinomial != nullptr) && "Упс, структура указывает на нулевой указатель, "
                              "надо решить проблему c SolveSquareEquation!");

    //Проверка на инициализацию переменной
    assert((isnan(UsersTrinomial->senior_cf) == false) && "Старший коэффициент многочлена "
                                                          "в функции SolveSquareEquation = NAN");
    assert((isnan(UsersTrinomial->second_cf) == false) && "Второй коэффициент многочлена "
                                                          "в функции SolveSquareEquation = NAN");
    assert((isnan(UsersTrinomial->free_term) == false) && "Свободный член многочлена "
                                                          "в функции SolveSquareEquation = NAN");

    //Проверка на конечность переменной
    assert((isfinite(UsersTrinomial->senior_cf) == true) && "Старший коэффициент многочлена "
                                                          "в функции SolveSquareEquation = INFINITY");
    assert((isfinite(UsersTrinomial->second_cf) == true) && "Второй коэффициент многочлена "
                                                          "в функции SolveSquareEquation = INFINITY");
    assert((isfinite(UsersTrinomial->free_term) == true) && "Свободный член многочлена "

                                                          "в функции SolveSquareEquation = INFINITY");
    double Discriminant = UsersTrinomial->second_cf * UsersTrinomial->second_cf
                                - 4 * UsersTrinomial->senior_cf * UsersTrinomial->free_term;
    //Проверка на NAN
    assert((isnan(Discriminant) == false) && "Дискриминант в функции SolveSquareEquation = NAN");

    //Проверка на INF
    assert((isfinite(Discriminant)) && "Дискриминант в функции SolveSquareEquation = INFINITY");

    if (CompareDouble(Discriminant, 0.0)) { //проверка на равенство значение Дискриминанта с 0

        UsersTrinomial->root1 = -UsersTrinomial->second_cf / (2 * UsersTrinomial->senior_cf);

        return ONE_ROOT;

    } else if (Discriminant >= EPS) { //Дискриминант > 0            // почему не через comparedouble?

        double sqrt_Disc = sqrt(Discriminant);
        UsersTrinomial->root1 = (-(UsersTrinomial->second_cf) - sqrt_Disc)
                                                / (2 * UsersTrinomial->senior_cf);
        UsersTrinomial->root2 = (-(UsersTrinomial->second_cf) + sqrt_Disc)
                                                / (2 * UsersTrinomial->senior_cf);

        return TWO_ROOTS;

    }

    return NO_ROOTS; //Дискриминант отрицательный

}

EquationRootsQuantity SolveLinearEquation(LinearBinomial *UsersBinomial)
{

    //Проверка на ненулевой указатель
    assert((UsersBinomial != nullptr) && "Указатель на UsersBinomial = нулевому указателю "
                                         "в функции SolveLinearEquation()");

    //Проверка на NAN:
    assert((isnan(UsersBinomial->senior_cf) == false) && "Главный коэффициент линейного двухчлена = NAN "
                                                         "в функции SolveLinearEquation()");
    assert((isnan(UsersBinomial->free_term) == false) && "Свободный член линейного двухчлена = NAN "
                                                         "в функции SolveLinearEquation()");

    //Проверка на конечность
    assert((isfinite(UsersBinomial->senior_cf)) && "Главный коэффициент линейного двухчлена = INF "
                                                         "в функции SolveLinearEquation()");
    assert((isfinite(UsersBinomial->free_term)) && "Свободный член линейного двухчлена = INF "
                                                         "в функции SolveLinearEquation()");


    if (CompareDouble(UsersBinomial->senior_cf, 0.0)) {

        if(CompareDouble(UsersBinomial->free_term, 0.0)) {

            return INFINITE_ROOTS_QUANTITY;

        }

        return NO_ROOTS;

    }

    UsersBinomial->root = -UsersBinomial->free_term / UsersBinomial->senior_cf;

    return ONE_ROOT;


}

void TransformTrinomial2Binomial(SquareTrinomial UsersTrinomial, LinearBinomial *UsersBinomial)
{

    //Проверка на ненулевой указатель
    assert((UsersBinomial != nullptr) && "Указатель на UsersBinomial = нулевому указателю "
                                         "в функции TransformTrinomial2Binomial()");

    //Проверка на NAN:
    assert((isnan(UsersTrinomial.senior_cf) == false) && "Главный коэффициент квадратного трёхчлена = NAN "
                                                         "в функции TransformTrinomial2Binomial()");
    assert((isnan(UsersTrinomial.free_term) == false) && "Свободный член квадратного трёхчлена = NAN "
                                                         "в функции TransformTrinomial2Binomial()");
    assert((isnan(UsersTrinomial.second_cf) == false) && "Второй коэффициент квадратного трёхчлена = NAN "
                                                         "в функции TransformTrinomial2Binomial()");

    //Проверка на конечность
    assert((isfinite(UsersTrinomial.senior_cf)) && "Главный коэффициент квадратного трёхчлена = INF "
                                                         "в функции TransformTrinomial2Binomial()");
    assert((isfinite(UsersTrinomial.free_term)) && "Свободный член квадратного трёхчлена = INF "
                                                         "в функции TransformTrinomial2Binomial()");
    assert((isfinite(UsersTrinomial.second_cf)) && "Второй коэффициент квадратного трёхчлена = INF "
                                                         "в функции TransformTrinomial2Binomial()");

    UsersBinomial->senior_cf = UsersTrinomial.second_cf;
    UsersBinomial->free_term = UsersTrinomial.free_term;

}
