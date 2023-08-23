#include "SolveSquareEquation.h"

void AssertSquareTrinomial(SquareTrinomial InterestingTrinom)
{

    assert((isnan(InterestingTrinom.senior_cf) == false) && "Senior coefficient = NAN!!!");
    assert((isnan(InterestingTrinom.second_cf) == false) && "Second coefficient = NAN!!!");
    assert((isnan(InterestingTrinom.free_term) == false) && "Free term = NAN!!!");

    assert((isfinite(InterestingTrinom.senior_cf)) && "Senior coefficient = INF!!!");
    assert((isfinite(InterestingTrinom.second_cf)) && "Second coefficient = INF!!!");
    assert((isfinite(InterestingTrinom.free_term)) && "Free term = INF!!!");

}

void AssertPtrSquareTrinomial(SquareTrinomial *InterestingTrinom)
{

    assert((InterestingTrinom != nullptr) && "Pointer to Polynomial is nullptr!!!");

    assert((isnan(InterestingTrinom->senior_cf) == false) && "Senior coefficient = NAN!!!");
    assert((isnan(InterestingTrinom->second_cf) == false) && "Second coefficient = NAN!!!");
    assert((isnan(InterestingTrinom->free_term) == false) && "Free term = NAN!!!");

    assert((isfinite(InterestingTrinom->senior_cf)) && "Senior coefficient = INF!!!");
    assert((isfinite(InterestingTrinom->second_cf)) && "Second coefficient = INF!!!");
    assert((isfinite(InterestingTrinom->free_term)) && "Free term = INF!!!");

}

void AssertDouble(double number)
{

    assert((isnan(number) == false) && "Number = NAN");

    assert((isfinite(number)) && "Number = INFINITY");
}
