#include "SolveSquareEquation.h"

const double EPS = 1e-7;

bool CompareDouble(double number1, double number2) //������� ��� �������� �� ��������� 2 ������������ �����
{

    //�������� ����� �� �������� NAN
    assert((isnan(number1) == false) && "���������� number1 � ������� CompareDouble() ����� �������� NAN");
    assert((isnan(number2) == false) && "���������� number2 � ������� CompareDouble() ����� �������� NAN");

    //�������� ����� �� �������� �� NAN
    assert((isfinite(number1)) && "���������� number1 � ������� CompareDouble() ����� �������� INFINITY");
    assert((isfinite(number2)) && "���������� number2 � ������� CompareDouble() ����� �������� INFINITY");

    return (fabs(number1 - number2) < EPS) ? true : false;

}

EquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial)
{

    // �������� �� ������� ���������
    assert((UsersTrinomial != nullptr) && "���, ��������� ��������� �� ������� ���������, "
                              "���� ������ �������� c SolveSquareEquation!");

    //�������� �� ������������� ����������
    assert((isnan(UsersTrinomial->senior_cf) == false) && "������� ����������� ���������� "
                                                          "� ������� SolveSquareEquation = NAN");
    assert((isnan(UsersTrinomial->second_cf) == false) && "������ ����������� ���������� "
                                                          "� ������� SolveSquareEquation = NAN");
    assert((isnan(UsersTrinomial->free_term) == false) && "��������� ���� ���������� "
                                                          "� ������� SolveSquareEquation = NAN");

    //�������� �� ���������� ����������
    assert((isfinite(UsersTrinomial->senior_cf) == true) && "������� ����������� ���������� "
                                                          "� ������� SolveSquareEquation = INFINITY");
    assert((isfinite(UsersTrinomial->second_cf) == true) && "������ ����������� ���������� "
                                                          "� ������� SolveSquareEquation = INFINITY");
    assert((isfinite(UsersTrinomial->free_term) == true) && "��������� ���� ���������� "

                                                          "� ������� SolveSquareEquation = INFINITY");
    double Discriminant = UsersTrinomial->second_cf * UsersTrinomial->second_cf
                                - 4 * UsersTrinomial->senior_cf * UsersTrinomial->free_term;
    //�������� �� NAN
    assert((isnan(Discriminant) == false) && "������������ � ������� SolveSquareEquation = NAN");

    //�������� �� INF
    assert((isfinite(Discriminant)) && "������������ � ������� SolveSquareEquation = INFINITY");

    if (CompareDouble(Discriminant, 0.0)) { //�������� �� ��������� �������� ������������� � 0

        UsersTrinomial->root1 = -UsersTrinomial->second_cf / (2 * UsersTrinomial->senior_cf);

        return ONE_ROOT;

    } else if (Discriminant >= EPS) { //������������ > 0            // ������ �� ����� comparedouble?

        double sqrt_Disc = sqrt(Discriminant);
        UsersTrinomial->root1 = (-(UsersTrinomial->second_cf) - sqrt_Disc)
                                                / (2 * UsersTrinomial->senior_cf);
        UsersTrinomial->root2 = (-(UsersTrinomial->second_cf) + sqrt_Disc)
                                                / (2 * UsersTrinomial->senior_cf);

        return TWO_ROOTS;

    }

    return NO_ROOTS; //������������ �������������

}

EquationRootsQuantity SolveLinearEquation(LinearBinomial *UsersBinomial)
{

    //�������� �� ��������� ���������
    assert((UsersBinomial != nullptr) && "��������� �� UsersBinomial = �������� ��������� "
                                         "� ������� SolveLinearEquation()");

    //�������� �� NAN:
    assert((isnan(UsersBinomial->senior_cf) == false) && "������� ����������� ��������� ��������� = NAN "
                                                         "� ������� SolveLinearEquation()");
    assert((isnan(UsersBinomial->free_term) == false) && "��������� ���� ��������� ��������� = NAN "
                                                         "� ������� SolveLinearEquation()");

    //�������� �� ����������
    assert((isfinite(UsersBinomial->senior_cf)) && "������� ����������� ��������� ��������� = INF "
                                                         "� ������� SolveLinearEquation()");
    assert((isfinite(UsersBinomial->free_term)) && "��������� ���� ��������� ��������� = INF "
                                                         "� ������� SolveLinearEquation()");


    if (CompareDouble(UsersBinomial->senior_cf, 0.0)) {

        if(CompareDouble(UsersBinomial->free_term, 0.0)) {

            return INFINITE_ROOTS_QUANTITY;

        }

        return NO_ROOTS;

    }

    UsersBinomial->root = -UsersBinomial->free_term / UsersBinomial->senior_cf;

    return ONE_ROOT;


}

void TransformTrinomial2Binomial(SquareTrinomial UsersTrinomial, LinearBinomial *UsersBinomial)
{

    //�������� �� ��������� ���������
    assert((UsersBinomial != nullptr) && "��������� �� UsersBinomial = �������� ��������� "
                                         "� ������� TransformTrinomial2Binomial()");

    //�������� �� NAN:
    assert((isnan(UsersTrinomial.senior_cf) == false) && "������� ����������� ����������� �������� = NAN "
                                                         "� ������� TransformTrinomial2Binomial()");
    assert((isnan(UsersTrinomial.free_term) == false) && "��������� ���� ����������� �������� = NAN "
                                                         "� ������� TransformTrinomial2Binomial()");
    assert((isnan(UsersTrinomial.second_cf) == false) && "������ ����������� ����������� �������� = NAN "
                                                         "� ������� TransformTrinomial2Binomial()");

    //�������� �� ����������
    assert((isfinite(UsersTrinomial.senior_cf)) && "������� ����������� ����������� �������� = INF "
                                                         "� ������� TransformTrinomial2Binomial()");
    assert((isfinite(UsersTrinomial.free_term)) && "��������� ���� ����������� �������� = INF "
                                                         "� ������� TransformTrinomial2Binomial()");
    assert((isfinite(UsersTrinomial.second_cf)) && "������ ����������� ����������� �������� = INF "
                                                         "� ������� TransformTrinomial2Binomial()");

    UsersBinomial->senior_cf = UsersTrinomial.second_cf;
    UsersBinomial->free_term = UsersTrinomial.free_term;

}
