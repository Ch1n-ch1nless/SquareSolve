#include "solve_square_equation.h"

void SolveSquareEquation(const SquareTrinomialCoef *users_trinomial, RootsOfTrinomial *root)
{
    assert((users_trinomial != nullptr) && "Pointer to Polynomial is nullptr!!!");
    assert((root != nullptr) && "Pointer to Polynomial is nullptr!!!");

    assert((isnan(users_trinomial->senior_cf) == false) && "Senior coefficient = NAN!!!");
    assert((isnan(users_trinomial->second_cf) == false) && "Second coefficient = NAN!!!");
    assert((isnan(users_trinomial->free_term) == false) && "Free term = NAN!!!");

    assert((isfinite(users_trinomial->senior_cf)) && "Senior coefficient = INF!!!");
    assert((isfinite(users_trinomial->second_cf)) && "Second coefficient = INF!!!");
    assert((isfinite(users_trinomial->free_term)) && "Free term = INF!!!");

    if (IsZero(users_trinomial->senior_cf)) {
        return SolveLinearEquation(users_trinomial, root);
    }

    double discriminant = users_trinomial->second_cf * users_trinomial->second_cf - 4 *
                          users_trinomial->senior_cf * users_trinomial->free_term;

     assert((isnan(discriminant) == false) && "Oops, Discriminant is NAN!!!");
     assert((isfinite(discriminant)) && "Oops, Discriminant is very big! D = INF!!!");

    if (IsZero(discriminant)) {
        root->first = -users_trinomial->second_cf / (2 * users_trinomial->senior_cf);
        root->first = (IsZero(root->first)) ? 0.0 : root->first;
        root->number = ONE_ROOT;
        return;
    }
    else if (discriminant >= EPS) {//Discriminant > 0
        double sqrt_disc = sqrt(discriminant);

        root->first  = (-(users_trinomial->second_cf) - sqrt_disc) / (2 * users_trinomial->senior_cf);
        root->second = (-(users_trinomial->second_cf) + sqrt_disc) / (2 * users_trinomial->senior_cf);

        root->first = (IsZero(root->first)) ? 0.0 : root->first;
        root->second = (IsZero(root->second)) ? 0.0 : root->second;

        SortRoots(root);
        root->number = TWO_ROOTS;
        return;
    }
    root->number = NO_ROOTS; //Discriminant < 0
}

void SolveLinearEquation(const SquareTrinomialCoef *users_trinomial, RootsOfTrinomial *root)
{
    if (IsZero(users_trinomial->second_cf)) {
        if(IsZero(users_trinomial->free_term)) {
            root->number = INFINITE_ROOTS_QUANTITY;
            return;
        }
        root->number = NO_ROOTS;
        return;
    }
    root->first = -users_trinomial->free_term / users_trinomial->second_cf;
    root->first = (IsZero(root->first)) ? 0.0 : root->first;

    root->number = ONE_ROOT;
}

void SortRoots(RootsOfTrinomial *root)
{
    if (root->second < root->first) {
        double temp = NAN;
        temp = root->second;
        root->second = root->first;
        root->first = temp;
    }
}
