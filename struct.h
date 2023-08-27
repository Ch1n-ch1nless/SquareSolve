///@file struct.h
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

enum EquationRootsQuantity
{
    INFINITE_ROOTS_QUANTITY = -1,
<<<<<<< Updated upstream
    NO_ROOTS = 0,
    ONE_ROOT = 1,
=======
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
>>>>>>> Stashed changes
    TWO_ROOTS = 2
};

///struct 'SquareTrinomialCoef' is is the structure that contains the value of coefficients
struct SquareTrinomialCoef
{
<<<<<<< Updated upstream
    ///senior coefficient of polynomial
    double senior_cf = NAN;
    ///second coefficient of polynomial
    double second_cf = NAN;
    ///free term of polynomial
    double free_term = NAN;
=======
    double senior_cf = NAN; //!<senior coefficient of polynomial
    double second_cf = NAN; //!<second coefficient of polynomial
    double free_term = NAN; //!<free term of polynomial
>>>>>>> Stashed changes
};

///struct 'RootsOfTrinomial' is is the structure that contains the value of roots
struct RootsOfTrinomial
{
<<<<<<< Updated upstream
    ///first root of equation
    double first = NAN;
    ///second root of equation
    double second = NAN;
=======
    double first = NAN;  //!<first root of equation
    double second = NAN; //!<second root of equation
>>>>>>> Stashed changes
};

#endif // STRUCT_H_INCLUDED
