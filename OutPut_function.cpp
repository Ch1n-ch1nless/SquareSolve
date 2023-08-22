#include "SolveSquareEquation.h"

void OutputResultOfSqrTrinom(EquationRootsQuantity quantity, SquareTrinomial UsersTrinomial) //������� ��������� ���������� ������ ��������� � ��������� �� ����� ����������
{

    //�������� ������������� ����������� �������� �� NAN
    assert((isnan(UsersTrinomial.senior_cf) == false) && "������� ����������� ����������� ��������� "
                                                         "=  NAN � ������� OutputResult");
    assert((isnan(UsersTrinomial.second_cf) == false) && "������ ����������� ����������� ��������� "
                                                         "=  NAN � ������� OutputResult");
    assert((isnan(UsersTrinomial.free_term) == false) && "��������� ���� ����������� ��������� "
                                                         "=  NAN � ������� OutputResult");

    //�������� ������������� ����������� �������� �� ����������
    assert((isfinite(UsersTrinomial.senior_cf)) && "������� ����������� ����������� ��������� "
                                                   "=  INFINITY � ������� OutputResult");
    assert((isfinite(UsersTrinomial.second_cf)) && "������ ����������� ����������� ��������� "
                                                    "=  INFINITY � ������� OutputResult");
    assert((isfinite(UsersTrinomial.free_term)) && "��������� ���� ����������� ��������� "
                                                    "=  INFINITY � ������� OutputResult");

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

            assert("���-�� ����� �� ��� � ������� OutputResult");

    }

}

void OutputResultOfLinBinom(EquationRootsQuantity quantity, LinearBinomial UsersBinomial)
{

    //�������� ������������� ����������� �������� �� NAN
    assert((isnan(UsersBinomial.senior_cf) == false) && "������� ����������� ��������� ��������� "
                                                         "=  NAN � ������� OutputResult");
    assert((isnan(UsersBinomial.free_term) == false) && "��������� ���� ��������� ��������� "
                                                         "=  NAN � ������� OutputResult");

    //�������� ������������� ����������� �������� �� ����������
    assert((isfinite(UsersBinomial.senior_cf)) && "������� ����������� ��������� ��������� "
                                                   "=  INFINITY � ������� OutputResult");
    assert((isfinite(UsersBinomial.free_term)) && "��������� ���� ��������� ��������� "
                                                    "=  INFINITY � ������� OutputResult");

    switch (quantity) {

        case NO_ROOTS:
            printf("������ ��������� �� ����� ������");
            break;

        case ONE_ROOT:
            printf("������ ��������� ����� ���� ������������ ������: x = %.*lg",
                    OUTPUT_PRECISION, UsersBinomial.root);
            break;

        case INFINITE_ROOTS_QUANTITY:
            printf("������ ��������� ����� ����������� ���������� ������:)");
            break;

        case TWO_ROOTS:
            printf("����������!");
            assert(false);
            break;

        default:
            printf("�������� ��������� ����������� ���������!\n"
                   "����������, �� �������� ������� �����, ������� �� �����, "
                   "����� ��� �� �����: 88005553535!\n"
                   "����� ������ ������, ��� ����� ��������)\b\b");

            assert("���-�� ����� �� ��� � ������� OutputResulttOfLinBinom");

    }
}
