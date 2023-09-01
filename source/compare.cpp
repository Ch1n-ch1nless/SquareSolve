#include "solve_square_equation.h"

bool CompareDouble(const double number1, const double number2) //function which check the equation of 2 double numbers
{
    return (fabs(number1 - number2) < EPSILON);
}

bool IsZero(const double number)
{
    return CompareDouble(number, 0.0);
}
