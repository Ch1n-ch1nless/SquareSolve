#include "test.h"
#include "SolveSquareEquation.h"

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

                return 0;

            }

        case TWO_ROOTS:

            if (CountOfRoots == CorrectNumberOfRoots && CompareDouble(TestRoot.first, CorrectRoots->first)
                && CompareDouble(TestRoot.second, CorrectRoots->second)) {

                printf("OK\n");

                return 1;

            } else {

                 printf("FAILED!\n" "EXPECTED: count of roots = %d, root1 = %lg, root2 = %lg\n"
                       "RECEIVED: count of roots = %d, root1 = %lg, root2 = %lg\n\n",
                       CorrectNumberOfRoots, CorrectRoots->first, CorrectRoots->second,
                       CountOfRoots, TestRoot.first, TestRoot.second);

                return 0;

            }

        default:

            printf("ERROR!!!");
            assert(false);
            return 0;
    }
}

void RunTests()
{
    int count_of_OK_tests = 0;

    SquareTrinomialCoef RefTrinomial;
    EquationRootsQuantity CorrectNumberOfRoots = NO_ROOTS;
    RootsOfTrinomial RefRoots;

    for (int count_of_test = 1; count_of_test <= NUMBER_OF_TESTS; count_of_test++)
    {
        printf("Test №%d ", count_of_test);
        ReadCorrectSqrTrinomial(&RefTrinomial, &CorrectNumberOfRoots, &RefRoots);
        count_of_OK_tests += CheckCorrectnessOfSolve(&RefTrinomial, CorrectNumberOfRoots, &RefRoots);
    }

    printf("Тестов пройдено: %d / %d", count_of_OK_tests, NUMBER_OF_TESTS);
}

void ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
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
