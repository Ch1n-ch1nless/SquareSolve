<<<<<<< Updated upstream
#include "SolveSquareEquation.h"
=======
#include "solve_square_equation.h"
>>>>>>> Stashed changes

bool CompareDouble(const double number1, const double number2) //function which check the equation of 2 double numbers
{
    return (fabs(number1 - number2) < EPS);
}

bool IsZero(const double number)
{
<<<<<<< Updated upstream
    return (fabs(number - 0.0) < EPS);
=======
    return CompareDouble(number, 0.0);
>>>>>>> Stashed changes
}
