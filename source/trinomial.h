///@file trinomial.h
#ifndef TRINOMIAL_H_INCLUDED
#define TRINOMIAL_H_INCLUDED

enum EquationRootsQuantity
{
    INFINITE_ROOTS_QUANTITY = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

///struct 'SquareTrinomialCoef' is is the structure that contains the value of coefficients
struct SquareTrinomialCoef
{
    double senior_cf = NAN; //!<senior coefficient of polynomial
    double second_cf = NAN; //!<second coefficient of polynomial
    double free_term = NAN; //!<free term of polynomial
};

///struct 'RootsOfTrinomial' is is the structure that contains the value of roots
struct RootsOfTrinomial
{
    double first = NAN;  //!<first root of equation
    double second = NAN; //!<second root of equation
    EquationRootsQuantity number = NO_ROOTS; //!<number of roots
};

#endif // TRINOMIAL_H_INCLUDED
