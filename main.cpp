#include "SolveSquareEquation.h"

int main()
{

    OperatingInstructionForUser();      //������� �� ����� ��� ������������ ���������� �� ������������� ���������

    SquareTrinomial UsersTrinomial;     //��������� ������������, ������� ��������� ������

    bool IsItSquareEquation = InputSquareTrinomialCF(&UsersTrinomial);     //������ ������������ ����������

    if(IsItSquareEquation) {

        EquationRootsQuantity CountOfRoots = SolveSquareEquation(&UsersTrinomial);     //������� ����������� ��������� � ���������� ���������� ������

        OutputResultOfSqrTrinom(CountOfRoots, UsersTrinomial);      //����� ���������� ���������

    } else {

        LinearBinomial UsersBinomial; //�������� ��������� ������������

        TransformTrinomial2Binomial(UsersTrinomial, &UsersBinomial); //���������� ������� � ��������

        EquationRootsQuantity CountOfRoots = SolveLinearEquation(&UsersBinomial); //������� ���������� ���������

        OutputResultOfLinBinom(CountOfRoots, UsersBinomial);  //����� ��������� ���������

    }

    return 0;

}
