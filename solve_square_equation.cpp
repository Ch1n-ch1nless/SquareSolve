#include "SolveSquareEquation.h"

EquationRootsQuantity SolveSquareEquation(SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root) //TODO: убрать *
{
    assert((UsersTrinomial != nullptr) && "Pointer to Polynomial is nullptr!!!");

    assert((isnan(UsersTrinomial->senior_cf) == false) && "Senior coefficient = NAN!!!");
    assert((isnan(UsersTrinomial->second_cf) == false) && "Second coefficient = NAN!!!");
    assert((isnan(UsersTrinomial->free_term) == false) && "Free term = NAN!!!");

    assert((isfinite(UsersTrinomial->senior_cf)) && "Senior coefficient = INF!!!");
    assert((isfinite(UsersTrinomial->second_cf)) && "Second coefficient = INF!!!");
    assert((isfinite(UsersTrinomial->free_term)) && "Free term = INF!!!");

    if (IsZero(UsersTrinomial->senior_cf))
    {
        return SolveLinearEquation(UsersTrinomial, Root);
    }
    else
    {
        double Discriminant = UsersTrinomial->second_cf * UsersTrinomial->second_cf
                                - 4 * UsersTrinomial->senior_cf * UsersTrinomial->free_term;

         assert((isnan(Discriminant) == false) && "Oops, Discriminant is NAN!!!");
         assert((isfinite(Discriminant)) && "Oops, Discriminant is very big! D = INF!!!");

        if (IsZero(Discriminant))
        {
            Root->first = -UsersTrinomial->second_cf / (2 * UsersTrinomial->senior_cf);

            Root->first = (IsZero(Root->first)) ? 0.0 : Root->first;

            return ONE_ROOT;
        }
        else if (Discriminant >= EPS) //Discriminant > 0
        {
            double sqrt_Disc = sqrt(Discriminant);

            Root->first = (-(UsersTrinomial->second_cf) - sqrt_Disc) / (2 * UsersTrinomial->senior_cf);

            Root->second = (-(UsersTrinomial->second_cf) + sqrt_Disc) / (2 * UsersTrinomial->senior_cf);

            Root->first = (IsZero(Root->first)) ? 0.0 : Root->first;

            Root->second = (IsZero(Root->second)) ? 0.0 : Root->second;

            MakeMinRoot1AndMaxRoot2(Root);

            return TWO_ROOTS;
        }
        return NO_ROOTS; //Discriminant < 0
    }
}

EquationRootsQuantity SolveLinearEquation(SquareTrinomialCoef *UsersTrinomial, RootsOfTrinomial *Root) //Убрать *
{
    assert((UsersTrinomial != nullptr) && "Pointer to Polynomial is nullptr!!!");

    assert((isnan(UsersTrinomial->senior_cf) == false) && "Senior coefficient = NAN!!!");
    assert((isnan(UsersTrinomial->second_cf) == false) && "Second coefficient = NAN!!!");
    assert((isnan(UsersTrinomial->free_term) == false) && "Free term = NAN!!!");

    assert((isfinite(UsersTrinomial->senior_cf)) && "Senior coefficient = INF!!!");
    assert((isfinite(UsersTrinomial->second_cf)) && "Second coefficient = INF!!!");
    assert((isfinite(UsersTrinomial->free_term)) && "Free term = INF!!!");


    if (IsZero(UsersTrinomial->second_cf))
    {
        if(IsZero(UsersTrinomial->free_term))
        {
            return INFINITE_ROOTS_QUANTITY;
        }
        return NO_ROOTS;
    }
    Root->first = -UsersTrinomial->free_term / UsersTrinomial->second_cf;
    Root->first = (IsZero(Root->first)) ? 0.0 : Root->first;

    return ONE_ROOT;
}

void MakeMinRoot1AndMaxRoot2(RootsOfTrinomial *Root)
{

    if (Root->second < Root->first)
    {
        double temp = NAN;
        temp = Root->second;
        Root->second = Root->first;
        Root->first = temp;
    }

}

