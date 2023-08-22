#include "SolveSquareEquation.h"

int main()
{

    OperatingInstructionForUser();      //Выводим на экран для пользователя инструкцию по использованию программы

    SquareTrinomial UsersTrinomial;     //Уравнение пользователя, которое требуется решить

    bool IsItSquareEquation = InputSquareTrinomialCF(&UsersTrinomial);     //Чтение коэффицентов многочлена

    if(IsItSquareEquation) {

        EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial);     //Решение квадратного уравнения и вычисление количества корней

        OutputResultOfSqrTrinom(CountOfRoots, UsersTrinomial);      //Вывод результата программы

    } else {

        LinearBinomial UsersBinomial; //Линейное уравнение пользователя

        TransformTrinomial2Binomial(UsersTrinomial, &UsersBinomial); //Превращаем Трёхчлен в двухчлен

        EquationRootsQuantity CountOfRoots = SolveLinearEquation(&UsersBinomial); //Решение линенйного уравнение

        OutputResultOfLinBinom(CountOfRoots, UsersBinomial);  //Вывод результат программы

    }

    return 0;

}
