<<<<<<< HEAD
#include "SolveSquareEquation.h"

bool CompareDouble(const double number1, const double number2) //function which check the equation of 2 double numbers
{
    return (fabs(number1 - number2) < EPS);
}

bool IsZero(const double number)
{
    return (fabs(number - 0.0) < EPS);
}
=======
#include "SolveSquareEquation.h"

bool CompareDouble(double number1, double number2) //function which check the equation of 2 double numbers
{

    return (fabs(number1 - number2) < EPS);

}

bool IsZero(double number) {

    return (fabs(number - 0.0) < EPS);

}
>>>>>>> 3659babd8f3d49b19163bea42c4930e613fde677
