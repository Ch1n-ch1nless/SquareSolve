#include "SolveSquareEquation.h"

bool InputSquareTrinomialCF(SquareTrinomial *UsersTrinomial)
{

    assert((UsersTrinomial != nullptr) && "������� ��������� � ������� InputSquareTrinomialCF");

    UsersTrinomial->senior_cf = GetInput('A');
    UsersTrinomial->second_cf = GetInput('B');
    UsersTrinomial->free_term = GetInput('C');

    return (CompareDouble(UsersTrinomial->senior_cf, 0.0)) ? false : true;

}

double GetInput(char symbol)
{

    double temp = NAN; //��������� ����������
    bool scanf_correctness_check_result = false; //����������, ������� ��������� ����� �� ��� ���� ����������

    printf("������� �������� �������� ����������� ����������: %c = ", symbol); //������ �������� �����������
    scanf_correctness_check_result = scanf("%lg", &temp);

    while (scanf_correctness_check_result == false) {                                        // ���� ���� �� ������ ������ �������� � scanfe, �� ������ �����
        printf("\n���, �� ������� ����� �������� �����������, ��������� �������!\n" // ������ ����������� � ������ ������������� �������� �� ������������. �����
               "������� �������� �������� ����������� ����������: %c= ",  symbol);
        scanf_correctness_check_result = scanf("%lg", &temp);
    }

    assert((isnan(temp) == false) && "�������� � ������� GetInput()");

    return temp;

}

void OperatingInstructionForUser()
{

    printf("������������, �� ��������� ��������� �� ������� ����������� ���������."
           "��� ��������� ������� ����� � ��������� �� %d ������!\n"
           "���������� ��������� ����� ��������� ��� A * x^2 + B * x + C = 0, ��� A, B, � C - ��������� �����\n"
           "����� ��������� ����� ������ ���������� ���������, �� ���������� ������ ��������� �������� ��� ������������.\n"
           "��������� �� ������ ������ ���������, ���� �� ������ �� �����, � \"��\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "�� ������ ������ ����� ����� (0 ��� -123 ��� 228 � �.�.)"
           "��� ������������ ����� � ���������� ������ � ������������ � ���� �����. ������: 1.5 (1,5 - �������� ����� ������)!\n", OUTPUT_PRECISION);

}
