#include <assert.h>
#include <math.h>
#include <stdio.h>

const double EPS = 1e-7;

const int OUTPUT_PRECISION = 6;

enum SquareEquationRootsQuantity
{
    INFINITE_ROOTS_QUANTITY = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

struct SquareTrinomial {
    double senior_cf = 0.0;     //старший коэффициент многочлена
    double second_cf = 0.0;     //второй коэффициент многочлена
    double free_term = 0.0;     //свободный член многочлена
    double root1 = 0.0;         //корень №1 многочлена
    double root2 = 0.0;         //корень №2 многочлена
};

SquareEquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial);

bool CompareDouble(double number1, double number2);

double GetInput(char symbol);

void OutputResult(SquareEquationRootsQuantity quantity, SquareTrinomial UsersTrinomial);

void OperatingInstructionForUser();

void MakePolynomial(SquareTrinomial *UsersTrinomial);

int main()
{

    OperatingInstructionForUser();      //выводим на экран для пользователя инструкцию по использованию программы

    SquareTrinomial UsersTrinomial;     //уравнение пользователя, которое требуется решить

    MakePolynomial(&UsersTrinomial);     //чтение коэффицентов многочлена

    SquareEquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial);     //решение квадартного уравнения и вычисление количества корненй

    OutputResult(CountOfRoots, UsersTrinomial);      //вывод результата программы

    return 0;
}

bool CompareDouble(double number1, double number2) //функция для проверки на равенство 2 вещественных чисел
{
    return (fabs(number1 - number2) < EPS) ? true : false;
}

SquareEquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial)
{
    assert((UsersTrinomial->root1 != nullptr) && "Упс, корень №1 уравнения указывает на нулевой указатель, "
                              "надо решить проблему c SolveSquareEquation!");

    assert((UsersTrinomial->root2 != nullptr) && "Упс, корень №2 первого уравнения указывает на нулевой указатель, "
                              "надо решить проблему c SolveSquareEquation!");

    assert((UsersTrinomial->root1 != UsersTrinomial->root2) && "Упс, корень №1 и корень №2 указывают на одну и ту же "
                         "ячейку памяти, "
                         "надо решить проблему c SolveSquareEquation!");


    //Проверка равенства между старшим коэффицентом и 0
    if (comparedouble((*UsersTrinomial).senior_cf, 0.0)) {

        if (comparedouble((*UsersTrinomial).second_cf, 0.0)) {

            if (comparedouble((*UsersTrinomial).free_term, 0.0)) {

                return INFINITE_ROOTS_QUANTITY; //Юзер ввёл уравнение вида 0*x^2+0*x+0=0

            } else {

                return NO_ROOTS; //Юзер ввёл уравнение типа 0*x^2+0*x+const = 0, где const != 0
            }

        } else {

            *x1 = -(*UsersTrinomial).free_term / (*UsersTrinomial).second_cf; //Юзер ввёл обычное линейное уравнение
            return ONE_ROOT;
        }

    } else { //старший коэффицент не 0, далее решаем обычное квадратное уравнение
        double Discriminant = (*UsersTrinomial).second_cf * (*UsersTrinomial).second_cf - 4 * (*UsersTrinomial).senior_cf * (*UsersTrinomial).free_term;

        if (comparedouble(Discriminant, 0.0)) { //проверка на равенство значение Дискриминанта с 0

            *x1 = -(*UsersTrinomial).second_cf / (2 * (*UsersTrinomial).senior_cf);
            return ONE_ROOT;

        } else if (Discriminant >= EPS) { //Дискриминант > 0

            double sqrt_Disc = sqrt(Discriminant);
            (*UsersTrinomial).root1 = (-(*UsersTrinomial).second_cf - sqrt_Disc) / (2 * (*UsersTrinomial).senior_cf);
            (*UsersTrinomial).root2 = (-(*UsersTrinomial).second_cf + sqrt_Disc) / (2 * (*UsersTrinomial).senior_cf);

            return TWO_ROOTS;

        } else { //Дискриминант < 0

            return NO_ROOTS;
        }
    }
}

void OutputResult(SquareEquationRootsQuantity quantity, SquareTrinomial UsersTrinomial) { //функция принимает количество корней уравнения и указатели на корни многочлена

    switch (quantity) {

        case NO_ROOTS:
            printf("Данное уравнение не имеет корней");
            break;

        case ONE_ROOT:
            printf("Данное уравнение имеет один единственный корень: x = %.*lg", OUTPUT_PRECISION, UsersTrinomial.root1);
            break;

        case TWO_ROOTS:
            printf("Данное уравнение имеет 2 корня: x1 = %.*lg и x2 = %.*lg", OUTPUT_PRECISION, OUTPUT_PRECISION, UsersTrinomial.root1, UsersTrinomial.root2);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("Данное уравнение имеет бесконечное количество корней:)");
            break;

        default:
            printf("Возникли небольшие технические шоколадки!\n"
                   "Пожалуйста, не забудьте скинуть числа, которые вы ввели, "
                   "через смс на номер: 88005553535!\n"
                   "Проще самому решить, чем прогу вызывать)\b\b");

    }

}

double GetInput(char symbol) {

    double  temp = 0.0; //временная переменная
    int check_correctness_of_coef = 0; //переменная, которая проверяет верно ли ввёл юзер коэффицент

    printf("Введите значение старшего коэффицента многочлена: %c = ", symbol); //чтение старшего коэффицента
    check_correctness_of_coef = scanf("%lg", &temp);
    while (check_correctness_of_coef == 0) {
        printf("\nУпс, вы неверно ввели значение коэффицента, повторите попытку!\n"
               "Введите значение старшего коэффицента многочлена: %c= ",  symbol);
        check_correctness_of_coef = scanf("%lg", &xtemp);
    }
    return temp;

}

void OperatingInstructionForUser() {

    printf("Здравствуйте, вы запустили программу по решению квадратного уравнения."
           "Эта программа находит корни с точностью до 6 знаков!\n"
           "Квадратное уравнение имеет следующий вид A * X^2 + B * x + C = 0, где A, B, и C - некоторые числа\n"
           "Чтобы программа могла решить квадартное уравнение, то необходимо ввести численное значение трёх коэффицентов.\n"
           "Программа не сможет решить уравнение, если вы введёте не число, а \"пи\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "Вы должны ввести целое число (0 или -123 или 228 и т.п.)"
           "Или вещественное число в десятичной записи с разделителем в виде точки. Пример: 1.5 (1,5 - неверная форма записи)!\n");

}

void MakePolynomial(SquareTrinomial *UsersTrinomial) {
    (*UsersTrinomial).senior_cf = GetInput('A');
    (*UsersTrinomial).second_cf = GetInput('B');
    (*UsersTrinomial).free_term = GetInput('C');
}
