#include "SolveSquareEquation.h"

bool InputSquareTrinomialCF(SquareTrinomial *UsersTrinomial)
{

    assert((UsersTrinomial != nullptr) && "Нулевой указатель в функции InputSquareTrinomialCF");

    UsersTrinomial->senior_cf = GetInput('A');
    UsersTrinomial->second_cf = GetInput('B');
    UsersTrinomial->free_term = GetInput('C');

    return (CompareDouble(UsersTrinomial->senior_cf, 0.0)) ? false : true;

}

double GetInput(char symbol)
{

    double temp = NAN; //временная переменная
    bool scanf_correctness_check_result = false; //переменная, которая проверяет верно ли ввёл юзер коэффицент

    printf("Введите значение старшего коэффицента многочлена: %c = ", symbol); //чтение старшего коэффицента
    scanf_correctness_check_result = scanf("%lg", &temp);

    while (scanf_correctness_check_result == false) {                                        // если было бы больше одного процента в scanfe, то случай ввода
        printf("\nУпс, вы неверно ввели значение коэффицента, повторите попытку!\n" // одного правильного и одного неправильного процента не рассмотрится. лучше
               "Введите значение старшего коэффицента многочлена: %c= ",  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "Проблемы в функции GetInput()");

    return temp;

}

void OperatingInstructionForUser()
{

    printf("Здравствуйте, вы запустили программу по решению квадратного уравнения."
           "Эта программа находит корни с точностью до %d знаков!\n"
           "Квадратное уравнение имеет следующий вид A * x^2 + B * x + C = 0, где A, B, и C - некоторые числа\n"
           "Чтобы программа могла решить квадартное уравнение, то необходимо ввести численное значение трёх коэффицентов.\n"
           "Программа не сможет решить уравнение, если вы введёте не число, а \"пи\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "Вы должны ввести целое число (0 или -123 или 228 и т.п.)"
           "Или вещественное число в десятичной записи с разделителем в виде точки. Пример: 1.5 (1,5 - неверная форма записи)!\n", OUTPUT_PRECISION);

}
