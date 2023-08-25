///@file struct.h
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

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
    ///senior coefficient of polynomial
    double senior_cf = NAN;
    ///second coefficient of polynomial
    double second_cf = NAN;
    ///free term of polynomial
    double free_term = NAN;
};

///struct 'RootsOfTrinomial' is is the structure that contains the value of roots
struct RootsOfTrinomial
{
    ///first root of equation
    double first = NAN;
    ///second root of equation
    double second = NAN;
};

#endif // STRUCT_H_INCLUDED
