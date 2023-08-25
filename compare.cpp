#include "SolveSquareEquation.h"

bool CompareDouble(const double number1, const double number2) //function which check the equation of 2 double numbers
{
    return (fabs(number1 - number2) < EPS);
}

bool IsZero(const double number)
{
    return (fabs(number - 0.0) < EPS);
}
