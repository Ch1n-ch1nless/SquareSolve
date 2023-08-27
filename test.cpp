#include "test.h"
<<<<<<< Updated upstream
#include "SolveSquareEquation.h"
=======
#include "solve_square_equation.h"

const char* RED = "\033[0;31m";
const char* GRN = "\033[0;32m";
const char* DEFAULT = "\033[0m";
>>>>>>> Stashed changes

int CheckCorrectnessOfSolve(const SquareTrinomialCoef *CorrectTrinomial,
                            EquationRootsQuantity CorrectNumberOfRoots,
                            const RootsOfTrinomial *CorrectRoots)
{
    SquareTrinomialCoef TestTrinomial;
    RootsOfTrinomial TestRoot;

    TestTrinomial.senior_cf = CorrectTrinomial->senior_cf;
    TestTrinomial.second_cf = CorrectTrinomial->second_cf;
    TestTrinomial.free_term = CorrectTrinomial->free_term;

    EquationRootsQuantity CountOfRoots = SolveSquareEquation(&TestTrinomial, &TestRoot);

<<<<<<< Updated upstream
    switch(CountOfRoots)
    {
        case NO_ROOTS:
            if (CountOfRoots == CorrectNumberOfRoots) {

                printf("OK\n");

                return 1;

            } else {

                printf("FAILED!\n" "EXPECTED: count of roots = %d\n"
                       "RECEIVED: count of roots = %d\n",
                       CorrectNumberOfRoots, CountOfRoots);

                return 0;

            }

        case INFINITE_ROOTS_QUANTITY:

            if (CountOfRoots == CorrectNumberOfRoots) {

                printf("OK\n");

                return 1;

            } else {

                printf("FAILED!\n" "EXPECTED: count of roots = %d\n"
                       "RECEIVED: count of roots = %d\n\n",
                       CorrectNumberOfRoots, CountOfRoots);

                return 0;

            }

        case ONE_ROOT:

            if (CountOfRoots == CorrectNumberOfRoots && CompareDouble(TestRoot.first, CorrectRoots->first)) {

                printf("OK\n");

                return 1;

            } else {

                 printf("FAILED!\n" "EXPECTED: count of roots = %d, root = %lg\n"
                       "RECEIVED: count of roots = %d, root = %lg\n",
                       CorrectNumberOfRoots, CorrectRoots->first,
                       CountOfRoots, TestRoot.first);

=======
    if (CountOfRoots != CorrectNumberOfRoots)
    {
        printf("%s FAILED!\n"
              "EXPECTED: count of roots = %d\n"
              "RECEIVED: count of roots = %d\n %s",
              RED, CountOfRoots, CorrectNumberOfRoots, DEFAULT);

        PrintEquation(CorrectTrinomial);
        return 0;
    }

    switch(CountOfRoots)
    {
        case NO_ROOTS:
            printf("%s OK\n %s", GRN, DEFAULT);
            return 1;

        case INFINITE_ROOTS_QUANTITY:
            printf("%s OK\n %s", GRN, DEFAULT);
            return 1;

        case ONE_ROOT:
            if (CompareDouble(TestRoot.first, CorrectRoots->first))
            {
                printf("%s OK\n %s", GRN, DEFAULT);
                return 1;
            } else {
                 printf("%s FAILED!\n"
                        "EXPECTED: root = %lg\n"
                        "RECEIVED: count of roots = %lg\n %s",
                        RED, CorrectRoots->first,
                        TestRoot.first, DEFAULT);

                PrintEquation(CorrectTrinomial);
>>>>>>> Stashed changes
                return 0;

            }

        case TWO_ROOTS:
<<<<<<< Updated upstream

            if (CountOfRoots == CorrectNumberOfRoots && CompareDouble(TestRoot.first, CorrectRoots->first)
                && CompareDouble(TestRoot.second, CorrectRoots->second)) {

                printf("OK\n");

                return 1;

            } else {

                 printf("FAILED!\n" "EXPECTED: count of roots = %d, root1 = %lg, root2 = %lg\n"
                       "RECEIVED: count of roots = %d, root1 = %lg, root2 = %lg\n\n",
                       CorrectNumberOfRoots, CorrectRoots->first, CorrectRoots->second,
                       CountOfRoots, TestRoot.first, TestRoot.second);

=======
            if (CompareDouble(TestRoot.first,  CorrectRoots->first) &&
                CompareDouble(TestRoot.second, CorrectRoots->second))
            {
                printf("%s OK\n %s", GRN, DEFAULT);
                return 1;
            } else {
                 printf("%s FAILED!\n"
                        "EXPECTED: root1 = %lg and root2 = %lg\n"
                        "RECEIVED: root1 = %lg and root2 = %lg\n %s",
                        RED, CorrectRoots->first, CorrectRoots->second,
                        TestRoot.first, TestRoot.second, DEFAULT);

                PrintEquation(CorrectTrinomial);
>>>>>>> Stashed changes
                return 0;

            }

        default:
<<<<<<< Updated upstream

            printf("ERROR!!!");
            assert(false);
            return 0;
    }
}

void RunTests()
{
    int count_of_OK_tests = 0;
=======
            assert(false && "\033[0;31m ERROR!!! Shit happens \033[0m");
    }
    return 0;
}

void RunTests(const char *file_name)
{
    FILE *ptr_to_test = fopen(file_name, "r");
    if (ptr_to_test != nullptr) {
        printf("File %s wasn't found!!!\n", file_name);
        return;
    }

    int count_of_ok_tests = 0;
>>>>>>> Stashed changes

    SquareTrinomialCoef RefTrinomial;
    EquationRootsQuantity CorrectNumberOfRoots = NO_ROOTS;
    RootsOfTrinomial RefRoots;

    for (int count_of_test = 1; count_of_test <= NUMBER_OF_TESTS; count_of_test++)
    {
        printf("Test №%d ", count_of_test);
<<<<<<< Updated upstream
        ReadCorrectSqrTrinomial(&RefTrinomial, &CorrectNumberOfRoots, &RefRoots);
        count_of_OK_tests += CheckCorrectnessOfSolve(&RefTrinomial, CorrectNumberOfRoots, &RefRoots);
    }

    printf("Тестов пройдено: %d / %d", count_of_OK_tests, NUMBER_OF_TESTS);
=======
        ReadCorrectSqrTrinomial(&RefTrinomial, &CorrectNumberOfRoots, &RefRoots, ptr_to_test);
        count_of_ok_tests += CheckCorrectnessOfSolve(&RefTrinomial, CorrectNumberOfRoots, &RefRoots);
        printf("\n");
    }

    printf("Tests passed: %d / %d", count_of_ok_tests, NUMBER_OF_TESTS);
>>>>>>> Stashed changes
}

void ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
<<<<<<< Updated upstream
                             RootsOfTrinomial *RefRoots)
{
    FILE *ptr_to_test;
    ptr_to_test = fopen("test.txt", "r");

    assert(((ptr != NULL) && (ptr != nullptr)) && "File test.txt wasn't found!!!\n");

    double temp = NAN; //time variable
    bool scanf_correctness_check_result = 0; //variable that checks the correctness of reading from the file

    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (!scanf_correctness_check_result)
    {
        printf("Error! The program can't read the var!\n");
        assert(false);
    }
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");

    RefTrinomial->senior_cf = temp;

    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (!scanf_correctness_check_result)
    {
        printf("Error! The program can't read the var!\n");
        assert(false);
    }
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");

    RefTrinomial->second_cf = temp;

    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (!scanf_correctness_check_result)
    {
        printf("Error! The program can't read the var!\n");
        assert(false);
    }
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");

    RefTrinomial->free_term = temp;

    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (!scanf_correctness_check_result)
    {
        printf("Error! The program can't read the var!\n");
        assert(false);
    }
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");

    RefRoots->first = temp;

    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (!scanf_correctness_check_result)
    {
        printf("Error! The program can't read the var!\n");
        assert(false);
    }
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");

    RefRoots->second = temp;
    int Temp = NAN;
    scanf_correctness_check_result = fscanf(ptr_to_test, "%d", &Temp);
    if (!scanf_correctness_check_result)
    {
        printf("Error! The program can't read the var!\n");
        assert(false);
    }
    assert((isnan(temp) == false) && "Error! Variable 'Temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'Temp' = INF!\n");
=======
                             RootsOfTrinomial *RefRoots, FILE *ptr_to_test)
{
    RefTrinomial->senior_cf = ReadNumber(ptr_to_test);
    RefTrinomial->second_cf = ReadNumber(ptr_to_test);
    RefTrinomial->free_term = ReadNumber(ptr_to_test);

    RefRoots->first = ReadNumber(ptr_to_test);
    RefRoots->second = ReadNumber(ptr_to_test);

    int Temp = 0;
    bool scanf_correctness_check_result = fscanf(ptr_to_test, "%d", &Temp);
    if (!scanf_correctness_check_result)
    {
        assert(false && "Error! The program can't read the var!\n");
    }
>>>>>>> Stashed changes

    switch(Temp)
    {
        case(-1):
            *CorrectNumberOfRoots = INFINITE_ROOTS_QUANTITY;
            break;

        case(0):
            *CorrectNumberOfRoots = NO_ROOTS;
            break;

        case(1):
            *CorrectNumberOfRoots = ONE_ROOT;
            break;

        case(2):
            *CorrectNumberOfRoots = TWO_ROOTS;
            break;

        default:
            printf("Ooops, something goes wrong!\n");
            assert(false);
            break;
<<<<<<< Updated upstream

    }
}
=======
    }
}

double ReadNumber(FILE *ptr_to_test)
{
    double temp = NAN; //time variable
    bool scanf_correctness_check_result = 0; //variable that checks the correctness of reading from the file
    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (!scanf_correctness_check_result)
    {
        assert(0 && "Error! The program can't read the var!\n");
    }

    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");
    return temp;
}

/*void PrintEquation(const SquareTrinomialCoef *CorrectTrinomial)
{
    printf(RED("EQUATION: "));

    if (IsZero(CorrectTrinomial->senior_cf)) {
        if (IsZero(CorrectTrinomial->second_cf)) {

            printf(RED("%lg"), CorrectTrinomial->free_term);

        } else if (CompareDouble(CorrectTrinomial->second_cf, 1)) {
            printf(RED("x "));

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf(RED("- %lg"), c);

            } else {
                printf(RED("+ %lg"), CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, -1)) {
            printf("-x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CorrectTrinomial->second_cf < 0) {
            double b = fabs(CorrectTrinomial->second_cf);
            printf("-%lg" "x ", b);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else {
            printf("%lg" "x ", CorrectTrinomial->second_cf);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        }

    } else if (CompareDouble(CorrectTrinomial->senior_cf, 1)) {
        printf("x^2 ");

        if (IsZero(CorrectTrinomial->second_cf)) {

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, 1)) {
            printf("+ x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, -1)) {
            printf("- x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CorrectTrinomial->second_cf < 0) {
            double b = fabs(CorrectTrinomial->second_cf);
            printf("- %lg" "x ", b);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else {
            printf("+ %lg" "x ", CorrectTrinomial->second_cf);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        }

    } else if (CompareDouble(CorrectTrinomial->senior_cf, -1)) {
        printf("-x^2 ");

        if (IsZero(CorrectTrinomial->second_cf)) {

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, 1)) {
            printf("+ x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, -1)) {
            printf("- x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CorrectTrinomial->second_cf < 0) {
            double b = fabs(CorrectTrinomial->second_cf);
            printf("- %lg" "x ", b);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else {
            printf("+ %lg" "x ", CorrectTrinomial->second_cf);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        }

    } else {
        printf("%lg" "x^2 ", CorrectTrinomial->senior_cf);

        if (IsZero(CorrectTrinomial->second_cf)) {

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, 1)) {
            printf("+ x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CompareDouble(CorrectTrinomial->second_cf, -1)) {
            printf("- x ");

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else if (CorrectTrinomial->second_cf < 0) {
            double b = fabs(CorrectTrinomial->second_cf);
            printf("- %lg" "x ", b);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        } else {
            printf("+ %lg" "x ", CorrectTrinomial->second_cf);

            if (IsZero(CorrectTrinomial->free_term)) {

            } else if (CorrectTrinomial->free_term < 0) {
                double c = fabs(CorrectTrinomial->free_term);
                printf("- %lg", c);

            } else {
                printf("+ %lg", CorrectTrinomial->free_term);

            }

        }

    }

    printf(RED( = 0\n));
} */

void PrintEquation(const SquareTrinomialCoef *CorrectTrinomial)
{
    printf("%s EQUATION: %lg * x^2 + %lg * x + %lg\n %s",
           RED,
           CorrectTrinomial->senior_cf,
           CorrectTrinomial->second_cf,
           CorrectTrinomial->free_term,
           DEFAULT);
}
>>>>>>> Stashed changes
