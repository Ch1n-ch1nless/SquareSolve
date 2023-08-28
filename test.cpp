#include "test.h"
#include "solve_square_equation.h"

static const char* RED = "\033[0;31m";
static const char* GRN = "\033[0;32m";
static const char* DEFAULT = "\033[0m";

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
                return 0;

            }

        case TWO_ROOTS:
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
                return 0;

            }

        default:
            printf("ERROR!!!");
            assert(false);
            return 0;
    }
}

void RunTests(const char *file_name)
{
    FILE *ptr_to_test = fopen(file_name, "r");
    if (ptr_to_test == nullptr) {
        printf("File %s wasn't found!!!\n", file_name);
        return;
    }

    int count_of_ok_tests = 0;

    SquareTrinomialCoef RefTrinomial;
    EquationRootsQuantity CorrectNumberOfRoots = NO_ROOTS;
    RootsOfTrinomial RefRoots;

    for (int count_of_test = 1; count_of_test <= NUMBER_OF_TESTS; count_of_test++)
    {
        printf("Test ¹%d ", count_of_test);
        ReadCorrectSqrTrinomial(&RefTrinomial, &CorrectNumberOfRoots, &RefRoots, ptr_to_test);
        count_of_ok_tests += CheckCorrectnessOfSolve(&RefTrinomial, CorrectNumberOfRoots, &RefRoots);
    }
    printf("Tests passed: %d / %d", count_of_ok_tests, NUMBER_OF_TESTS);
}

void ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
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
