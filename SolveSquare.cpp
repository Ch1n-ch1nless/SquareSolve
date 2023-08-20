#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <TXLib.h>

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
    double senior_cf = 0.0;     //������� ����������� ����������
    double second_cf = 0.0;     //������ ����������� ����������
    double free_term = 0.0;     //��������� ���� ����������
    double root1 = 0.0;         //������ �1 ����������
    double root2 = 0.0;         //������ �2 ����������
};

SquareEquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial);

bool CompareDouble(double number1, double number2);

double GetInput(char symbol);

void OutputResult(SquareEquationRootsQuantity quantity, SquareTrinomial UsersTrinomial);

void OperatingInstructionForUser();

void MakePolynomial(SquareTrinomial *UsersTrinomial);

int main()
{

    OperatingInstructionForUser();      //������� �� ����� ��� ������������ ���������� �� ������������� ���������

    SquareTrinomial UsersTrinomial;     //��������� ������������, ������� ��������� ������

    MakePolynomial(&UsersTrinomial);     //������ ������������ ����������

    SquareEquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial);     //������� ����������� ��������� � ���������� ���������� �������

    OutputResult(CountOfRoots, UsersTrinomial);      //����� ���������� ���������

    return 0;
}

bool CompareDouble(double number1, double number2) //������� ��� �������� �� ��������� 2 ������������ �����
{
    return (fabs(number1 - number2) < EPS) ? true : false;
}

SquareEquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial)
{
    assert((UsersTrinomial != nullptr) && "���, ��������� ��������� �� ������� ���������, "
                              "���� ������ �������� c SolveSquareEquation!");


    if (CompareDouble((*UsersTrinomial).senior_cf, 0.0)) {

        if (CompareDouble((*UsersTrinomial).second_cf, 0.0)) {

            if (CompareDouble((*UsersTrinomial).free_term, 0.0)) {

                return INFINITE_ROOTS_QUANTITY; //���� ��� ��������� ���� 0*x^2+0*x+0=0

            } else {

                return NO_ROOTS; //���� ��� ��������� ���� 0*x^2+0*x+const = 0, ��� const != 0
            }

        } else {

            (*UsersTrinomial).root1 = -(*UsersTrinomial).free_term / (*UsersTrinomial).second_cf; //���� ��� ������� �������� ���������
            return ONE_ROOT;
        }

    } else { //������� ���������� �� 0, ����� ������ ������� ���������� ���������
        double Discriminant = (*UsersTrinomial).second_cf * (*UsersTrinomial).second_cf
                                - 4 * (*UsersTrinomial).senior_cf * (*UsersTrinomial).free_term;

        if (CompareDouble(Discriminant, 0.0)) { //�������� �� ��������� �������� ������������� � 0

            (*UsersTrinomial).root1 = -(*UsersTrinomial).second_cf / (2 * (*UsersTrinomial).senior_cf);
            return ONE_ROOT;

        } else if (Discriminant >= EPS) { //������������ > 0

            double sqrt_Disc = sqrt(Discriminant);
            (*UsersTrinomial).root1 = (-((*UsersTrinomial).second_cf) - sqrt_Disc)
                                                / (2 * (*UsersTrinomial).senior_cf);
            (*UsersTrinomial).root2 = (-((*UsersTrinomial).second_cf) + sqrt_Disc)
                                                / (2 * (*UsersTrinomial).senior_cf);

            return TWO_ROOTS;

        } else { //������������ < 0

            return NO_ROOTS;
        }
    }
}

void OutputResult(SquareEquationRootsQuantity quantity, SquareTrinomial UsersTrinomial) //������� ��������� ���������� ������ ��������� � ��������� �� ����� ����������
{

    switch (quantity) {

        case NO_ROOTS:
            printf("������ ��������� �� ����� ������");
            break;

        case ONE_ROOT:
            printf("������ ��������� ����� ���� ������������ ������: x = %.*lg",
                    OUTPUT_PRECISION, UsersTrinomial.root1);
            break;

        case TWO_ROOTS:
            printf("������ ��������� ����� 2 �����: x1 = %.*lg � x2 = %.*lg",
                    OUTPUT_PRECISION, UsersTrinomial.root1, OUTPUT_PRECISION, UsersTrinomial.root2);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("������ ��������� ����� ����������� ���������� ������:)");
            break;

        default:
            printf("�������� ��������� ����������� ���������!\n"
                   "����������, �� �������� ������� �����, ������� �� �����, "
                   "����� ��� �� �����: 88005553535!\n"
                   "����� ������ ������, ��� ����� ��������)\b\b");

    }

}

double GetInput(char symbol) {

    double  temp = 0.0; //��������� ����������
    int check_correctness_of_coef = 0; //����������, ������� ��������� ����� �� ��� ���� ����������

    printf("������� �������� �������� ����������� ����������: %c = ", symbol); //������ �������� �����������
    check_correctness_of_coef = scanf("%lg", &temp);
    while (check_correctness_of_coef == 0) {
        printf("\n���, �� ������� ����� �������� �����������, ��������� �������!\n"
               "������� �������� �������� ����������� ����������: %c= ",  symbol);
        check_correctness_of_coef = scanf("%lg", &temp);
    }
    return temp;

}

void OperatingInstructionForUser() {

    printf("������������, �� ��������� ��������� �� ������� ����������� ���������."
           "��� ��������� ������� ����� � ��������� �� 6 ������!\n"
           "���������� ��������� ����� ��������� ��� A * X^2 + B * x + C = 0, ��� A, B, � C - ��������� �����\n"
           "����� ��������� ����� ������ ���������� ���������, �� ���������� ������ ��������� �������� ��� ������������.\n"
           "��������� �� ������ ������ ���������, ���� �� ������ �� �����, � \"��\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "�� ������ ������ ����� ����� (0 ��� -123 ��� 228 � �.�.)"
           "��� ������������ ����� � ���������� ������ � ������������ � ���� �����. ������: 1.5 (1,5 - �������� ����� ������)!\n");

}

void MakePolynomial(SquareTrinomial *UsersTrinomial) {
    assert((UsersTrinomial != nullptr) && "���, ��������� ��������� �� ������� ���������, "
                              "���� ������ �������� c MakePolynomial!");
    (*UsersTrinomial).senior_cf = GetInput('A');
    (*UsersTrinomial).second_cf = GetInput('B');
    (*UsersTrinomial).free_term = GetInput('C');
}
