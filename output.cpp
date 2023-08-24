#include "IOput.h"

void PrintResult(const EquationRootsQuantity quantity, const RootsOfTrinomial Root) //function which print result of program
{
    switch (quantity)
    {
        case NO_ROOTS:
            printf("������ ��������� �� ����� ������");
            break;

        case ONE_ROOT:
            printf("������ ��������� ����� ���� ������������ ������: x = %.*lg",
                    OUTPUT_PRECISION, Root.first);
            break;

        case TWO_ROOTS:
            printf("������ ��������� ����� 2 �����: x1 = %.*lg � x2 = %.*lg",
                    OUTPUT_PRECISION, Root.first, OUTPUT_PRECISION, Root.second);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("������ ��������� ����� ����������� ���������� ������:)");
            break;

        default:
            printf("�������� ��������� ����������� ���������!\n"
                   "����������, �� �������� ������� �����, ������� �� �����, "
                   "����� ��� �� �����: 88005553535!\n"
                   "����� ������ ������, ��� ����� ��������)\b\b");

            assert("���-�� ����� �� ��� � ������� OutputResult");
            break;
    }
}

void ShowInstructionForUser()
{
    printf("# SolveSquareEquation program version 1.8\n"
           "# Directed by Aleksandrov Oleg\n\n"
           "������������, �� ��������� ��������� �� ������� ����������� ���������."
           "��� ��������� ������� ����� � ��������� �� %d ������!\n"
           "���������� ��������� ����� ��������� ��� A * x^2 + B * x + C = 0, ��� A, B, � C - ��������� �����\n"
           "����� ��������� ����� ������ ���������� ���������, �� ���������� ������ ��������� �������� ��� ������������.\n"
           "��������� �� ������ ������ ���������, ���� �� ������ �� �����, � \"��\", \"exp\", \"4/3\",\"sqrt(2)\".\n"
           "�� ������ ������ ����� ����� (0 ��� -123 ��� 228 � �.�.)"
           " ��� ������������ ����� � ���������� ������ � ������������ � ���� �����. ������: 1.5 (1,5 - �������� ����� ������)!\n", OUTPUT_PRECISION);
}
