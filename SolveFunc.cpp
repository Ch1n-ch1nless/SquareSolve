#include "SolveSquareEquation.h"

const double EPS = 1e-7;

bool CompareDouble(double number1, double number2) //function which check the equation of 2 double numbers
{

    AssertDouble(number1);
    AssertDouble(number2);

    return (fabs(number1 - number2) < EPS) ? true : false;

}

EquationRootsQuantity SolveSquareEquation(SquareTrinomial *UsersTrinomial)
{

    AssertPtrSquareTrinomial(UsersTrinomial);

    if (CompareDouble(UsersTrinomial->senior_cf, 0.0)) {

        return SolveLinearEquation(UsersTrinomial);

    } else {

         double Discriminant = UsersTrinomial->second_cf * UsersTrinomial->second_cf
                                - 4 * UsersTrinomial->senior_cf * UsersTrinomial->free_term;

         AssertDouble(Discriminant);

        if (CompareDouble(Discriminant, 0.0)) { //Check for Discriminant equality from 0

            UsersTrinomial->root1 = -UsersTrinomial->second_cf / (2 * UsersTrinomial->senior_cf);

            UsersTrinomial->root1 = (CompareDouble(UsersTrinomial->root1, 0.0)) ?
                                                    0.0 : UsersTrinomial->root1;

            return ONE_ROOT;

        } else if (Discriminant >= EPS) { //Discriminant > 0

            double sqrt_Disc = sqrt(Discriminant);
            UsersTrinomial->root1 = (-(UsersTrinomial->second_cf) - sqrt_Disc)
                                                    / (2 * UsersTrinomial->senior_cf);
            UsersTrinomial->root2 = (-(UsersTrinomial->second_cf) + sqrt_Disc)
                                                    / (2 * UsersTrinomial->senior_cf);

            UsersTrinomial->root1 = (CompareDouble(UsersTrinomial->root1, 0.0)) ?
                                                    0.0 : UsersTrinomial->root1;
            UsersTrinomial->root2 = (CompareDouble(UsersTrinomial->root2, 0.0)) ?
                                                    0.0 : UsersTrinomial->root2;

            MakeMinRoot1AndMaxRoot2(UsersTrinomial);

            return TWO_ROOTS;

        }

        return NO_ROOTS; //Discriminant < 0

    }

}

EquationRootsQuantity SolveLinearEquation(SquareTrinomial *UsersTrinomial)
{

    AssertPtrSquareTrinomial(UsersTrinomial);


    if (CompareDouble(UsersTrinomial->second_cf, 0.0)) {

        if(CompareDouble(UsersTrinomial->free_term, 0.0)) {

            return INFINITE_ROOTS_QUANTITY;

        }

        return NO_ROOTS;

    }

    UsersTrinomial->root1 = -UsersTrinomial->free_term / UsersTrinomial->second_cf;

    UsersTrinomial->root1 = (CompareDouble(UsersTrinomial->root1, 0.0)) ? 0.0 : UsersTrinomial->root1;

    return ONE_ROOT;


}

void MakeMinRoot1AndMaxRoot2(SquareTrinomial *UsersTrinomial)
{

    if ((UsersTrinomial->root2 - UsersTrinomial->root1) < EPS) {

        double temp = NAN;
        temp = UsersTrinomial->root2;
        UsersTrinomial->root2 = UsersTrinomial->root1;
        UsersTrinomial->root1 = temp;

        AssertDouble(temp);
        AssertDouble(UsersTrinomial->root1);
        AssertDouble(UsersTrinomial->root2);

    }

}

