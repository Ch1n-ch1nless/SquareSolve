//            WARNING!!!!
//        Не работает программа, скорее всего ошибка в get_input(), но это неточно.


#include <assert.h>
#include <math.h>
#include <stdio.h>

const double EPS = 1e-7; // константы большими буквами

const int OUTPUT_PRECISION = 6;

enum SquareEquationRootsQuantity
{
    INFINITE_ROOTS_QUANTITY = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

SquareEquationRootsQuantity SolveSquareEquation(double a, double b, double c, double *x1, double *x2);
int comparedouble(double a, double b);
void get_input(double *a, double *b, double *c); //скорее всего не работает на данный момент
void output_result(SquareEquationRootsQuantity quantity, double x1, double x2);
void operating_instruction_for_user();

int main()
{

    operating_instruction_for_user(); //выводим на экран для пользователя инструкцию по использованию программы

    double A_senior_cf = 0.0;      //старший коэффицент многочлена, который ввёл пользователь
    double B_2_cf = 0.0;           //второй коэффицент многочлена, который ввёл пользователь
    double C_free_term = 0.0;      //свободный член многочлена, который ввёл пользователь
    double root_1 = 0.0;           //корень №1 многочлена, который ввёл пользователь
    double root_2 = 0.0;            //корень №2 многочлена, который ввёл пользователь

    get_input(&A_senior_cf, &B_2_cf, &C_free_term);     //чтение коэффицентов многочлена

    SquareEquationRootsQuantity CountOfRoots = SolveSquareEquation(A_senior_cf, B_2_cf, C_free_term, &root_1, &root_2);     //решение квадартного уравнения и вычисление количества корненй

    output_result(CountOfRoots, root_1, root_2);      //вывод результата программы

    return 0;
}

int comparedouble(double a, double b) //функция для проверки на равенство 2 вещественных чисел
{
    if (fabs(a-b) < EPS) {

        return 1;

    } else {

        return 0;

    }
}

SquareEquationRootsQuantity SolveSquareEquation(double a, double b, double c, double *x1, double *x2)
{
    assert((x1 != nullptr) && "Упс, корень №1 уравнения указывает на нулевой указатель, надо решить проблему c SolveSquareEquation!");
    assert((x2 != nullptr) && "Упс, корень №2 первого уравнения указывает на нулевой указатель, надо решить проблему c SolveSquareEquation!");
    assert((x1 != x2) && "Упс, корень №1 и корень №2 указывают на одну и ту же ячейку памяти, надо решить проблему c SolveSquareEquation!");


    //Проверка равенства между старшим коэффицентом и 0
    if (comparedouble(a, 0.0)) {

        if (comparedouble(b, 0.0)) {

            if (comparedouble(c, 0.0)) {

                return INFINITE_ROOTS_QUANTITY; //Юзер ввёл уравнение вида 0*x^2+0*x+0=0

            } else {

                return NO_ROOTS; //Юзер ввёл уравнение типа 0*x^2+0*x+const = 0, где const != 0
            }

        } else {

            *x1 = -c/b; // Юзер ввёл обычное линейное уравнение
            return ONE_ROOT;
        }

    } else { //старший коэффицент не 0, далее решаем обычное квадратное уравнение
        double Discriminant = b * b - 4 * a * c;

        if (comparedouble(Discriminant, 0.0)) { //проверка на равенство значение Дискриминанта с 0

            *x1 = -b / (2 * a);
            return ONE_ROOT;

        } else if (Discriminant >= EPS) { //Дискриминант > 0

            double sqrt_Disc = sqrt(Discriminant);
            *x1 = (-b - sqrt_Disc) / (2 * a);
            *x2 = (-b + sqrt_Disc) / (2 * a);

            return TWO_ROOTS;

        } else { //Дискриминант < 0

            return NO_ROOTS;

        }

    }
}

void output_result(SquareEquationRootsQuantity quantity, double root_1, double root_2) { //функция принимает количество корней уравнения и указатели на корни многочлена

    switch (quantity) {

        case NO_ROOTS:
            printf("Данное уравнение не имеет корней");
            break;

        case ONE_ROOT:
            printf("Данное уравнение имеет один единственный корень: x = %.*lg", OUTPUT_PRECISION, root_1);
            break;

        case TWO_ROOTS:
            printf("Данное уравнение имеет 2 корня: x1 = %.*lg и x2 = %.*lg", OUTPUT_PRECISION, OUTPUT_PRECISION, root_1, root_2);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("Данное уравнение имеет бесконечное количество корней:)");
            break;

        default:
            printf("Возникли небольшие технические шоколадки!\n"
                   "Пожалуйста, не забудьте скинуть числа, которые вы ввели, через смс на номер: 88005553535!\n"
                   "Проще самому решить, чем прогу вызывать)\b\b");

    }

}

void get_input(double *senior_cf, double *second_cf, double *free_term) { //не работает(

    double x = 0.0; //временная переменная
    int check_correctness_of_coef = 0; //переменная, которая проверяет верно ли ввёл юзер коэффицент

    printf("Введите значение старшего коэффицента многочлена: A = "); //чтение старшего коэффицента
    check_correctness_of_coef = scanf("%lg", x);
    while (check_correctness_of_coef == 0) {
        printf("\nУпс, вы неверно ввели значение коэффицента, повторите попытку!\n"
               "Введите значение старшего коэффицента многочлена: A = ");
        check_correctness_of_coef = scanf("%lg", x);
    }
    *senior_cf = x;

    printf("\nВведите значение второго коэффицента многочлена: B = "); //чтение второго коэффицента многочлена
    check_correctness_of_coef = scanf("%lg", x);
    while (check_correctness_of_coef == 0) {
        printf("\nУпс, вы неверно ввели значение коэффицента, повторите попытку!\n"
               "Введите значение второго коэффицента многочлена: B = ");
        check_correctness_of_coef = scanf("%lg", x);
    }
    *second_cf = x;

    printf("\nВведите значение свободного члена многочлена: C = "); //чтение свободного члена коэффицента
    check_correctness_of_coef = scanf("%lg", x);
    while (check_correctness_of_coef == 0) {
        printf("\nУпс, вы неверно ввели значение коэффицента, повторите попытку!\n"
               "Введите значение свободного члена многочлена: C = ");
        check_correctness_of_coef = scanf("%lg", x);
    }
    *free_term = x;
    check_correctness_of_coef = 0;

}

void operating_instruction_for_user() {

    printf("Здравствуйте, вы запустили программу по решению квадратного уравнения."
           "Эта программа находит корни с точностью до 6 знаков!\n"
           "Квадратное уравнение имеет следующий вид A * X^2 + B * x + C = 0, где A, B, и C - некоторые числа\n"
           "Чтобы программа могла решить квадартное уравнение, то необходимо ввести численное значение трёх коэффицентов.\n"
           "Программа не сможет решить уравнение, если вы введёте не число, а \"пи\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "Вы должны ввести целое число (0 или -123 или 228 и т.п.)"
           "Или вещественное число в десятичной записи с разделителем в виде точки. Пример: 1.5 (1,5 - неверная форма записи)!\n");

}
