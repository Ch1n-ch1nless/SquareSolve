#include <stdio.h>
#include <math.h>

const double eps = 1e-8;

int SolveSquareEqual(double a, double b, double c, double *x1, double *x2);

int main()
{
    printf("Привет, данная программа умеет решать квадратное уравнение типа A*x^2 + B*x+ C = 0\n");
    double A, B, C; //старший коэффицент, второй коэффицент и свободный член соответственно
    double x1, x2; //roots
    printf("Для того, чтобы узнать значение корней вашего уравнения с точностью до 6 знаков после запятой, введитие зачение старшего коэффицента: ");
    scanf("%lg", &A);
    printf("\nТеперь введите значение второго коэффиента: ");
    scanf("%lg", &B);
    printf("\nВведите значение свободного члена: ");
    scanf("%lg", &C);
    int CountOfRoots = SolveSquareEqual(A, B, C, &x1, &x2);
    switch(CountOfRoots)
    {
        case 0:
            printf("\nДанное уравнение не имеет корней\n");
            break;
        case 1:
            printf("\nДанное уравнение имеет единственный корень, который равен %.6lg\n", x1);
            break;
        case 2:
            printf("\nДанное уравнение имеет 2 корня: x1 = %.6lg и x2 = %.6lg\n", x1, x2);
            break;
        case 10:
            printf("\nДанное уравнение имеет бесконенчое количество корней:)\n");
            break;
        default:
            printf("\nПрограмма не смогла распознать введенные вами символы. \nПерезапустите её ещё раз и введите корректно\n");
            break;
    }
    return 0;
}

int SolveSquareEqual(double A, double B, double C, double *x1, double *x2)
{
    //Проверка равенства между старшим коэффицентом и 0
    if (fabs(A - 0.0) < eps) {
        if (fabs(B - 0.0) < eps) {
            if (fabs(C - 0.0) < eps) {
                return 10; //Юзер ввёл уравнение вида 0*x^2+0*x+0=0
            } else {
                return 0; //Юзер ввёл уравнение типа 0*x^2+0*x+const = 0, где const != 0
            }
        } else {
            *x1 = -1.0 * C / B;
            return 1;
        }
    } else {
        double D = B*B - 4*A*C;
        if (fabs(D - 0.0) < eps) {
            *x1 = -1.0 * B / (2*A);
            return 1;
        } else if (D - 0.0 >= eps) {
            *x1 = (-B - sqrt(D)) / (2*A);
            *x2 = (-B + sqrt(D)) / (2*A);
            return 2;
        } else { //D < 0
            return 0;
        }
    }
}
