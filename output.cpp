#include "IOput.h"

void PrintResult(const EquationRootsQuantity quantity, const RootsOfTrinomial Root) //function which print result of program
{
    switch (quantity)
    {
        case NO_ROOTS:
            printf("Данное уравнение не имеет корней");
            break;

        case ONE_ROOT:
            printf("Данное уравнение имеет один единственный корень: x = %.*lg",
                    OUTPUT_PRECISION, Root.first);
            break;

        case TWO_ROOTS:
            printf("Данное уравнение имеет 2 корня: x1 = %.*lg и x2 = %.*lg",
                    OUTPUT_PRECISION, Root.first, OUTPUT_PRECISION, Root.second);
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
            break;
    }
}

void ShowInstructionForUser()
{
    printf("# SolveSquareEquation program version 1.8\n"
           "# Directed by Aleksandrov Oleg\n\n"
           "Здравствуйте, вы запустили программу по решению квадратного уравнения."
           "Эта программа находит корни с точностью до %d знаков!\n"
           "Квадратное уравнение имеет следующий вид A * x^2 + B * x + C = 0, где A, B, и C - некоторые числа\n"
           "Чтобы программа могла решить квадартное уравнение, то необходимо ввести численное значение трёх коэффицентов.\n"
           "Программа не сможет решить уравнение, если вы введёте не число, а \"пи\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "Вы должны ввести целое число (0 или -123 или 228 и т.п.)"
           " или вещественное число в десятичной записи с разделителем в виде точки. Пример: 1.5 (1,5 - неверная форма записи)!\n", OUTPUT_PRECISION);
}
