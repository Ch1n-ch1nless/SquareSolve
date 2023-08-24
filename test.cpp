<<<<<<< HEAD
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
    double temp = NAN;
    fscanf(ptr_to_test, "%lg", &temp);
    RefTrinomial->senior_cf = temp;
    fscanf(ptr_to_test, "%lg", &temp);
    RefTrinomial->second_cf = temp;
    fscanf(ptr_to_test, "%lg", &temp);
    RefTrinomial->free_term = temp;
    fscanf(ptr_to_test, "%lg", &temp);
    RefRoots->first = temp;
    fscanf(ptr_to_test, "%lg", &temp);
    RefRoots->second = temp;
    int Temp = NAN;
    fscanf(ptr_to_test, "%d", &Temp);
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
=======
#include "SolveSquareEquation.h"

int count_of_test = 1;

int CheckCorrectnessOfSolve(SquareTrinomial *CorrectTrinomial, EquationRootsQuantity CorrectNumberOfRoots, RootsOfTrinomial *CorrectRoots)
{

    SquareTrinomial TestTrinomial;
    RootsOfTrinomial TestRoot;

    TestTrinomial.senior_cf = CorrectTrinomial->senior_cf;
    TestTrinomial.second_cf = CorrectTrinomial->second_cf;
    TestTrinomial.free_term = CorrectTrinomial->free_term;

    EquationRootsQuantity CountOfRoots = SolveSquareEquation(&TestTrinomial, &TestRoot);

    switch(CountOfRoots) {

        case NO_ROOTS:
            if (CountOfRoots == CorrectNumberOfRoots) {

                printf("TEST №%d: OK\n\n", count_of_test);

                return 1;

            } else {

                printf("TEST №%d: FAILED!\n\n" "EXPECTED: count of roots = %d\n"
                       "RECEIVED: count of roots = %d\n",
                       count_of_test, CorrectNumberOfRoots, CountOfRoots);

                return 0;

            }

        case INFINITE_ROOTS_QUANTITY:

            if (CountOfRoots == CorrectNumberOfRoots) {

                printf("TEST №%d: OK\n\n", count_of_test);

                return 1;

            } else {

                printf("TEST №%d: FAILED!\n" "EXPECTED: count of roots = %d\n"
                       "RECEIVED: count of roots = %d\n\n",
                       count_of_test, CorrectNumberOfRoots, CountOfRoots);

                return 0;

            }

        case ONE_ROOT:

            if (CountOfRoots == CorrectNumberOfRoots && CompareDouble(TestRoot.first, CorrectRoots->first)) {

                printf("TEST №%d: OK\n\n", count_of_test);

                return 1;

            } else {

                 printf("TEST №%d: FAILED!\n" "EXPECTED: count of roots = %d, root = %lg\n"
                       "RECEIVED: count of roots = %d, root = %lg\n\n",
                       count_of_test, CorrectNumberOfRoots, CorrectRoots->first,
                       CountOfRoots, TestRoot.first);

                return 0;

            }

        case TWO_ROOTS:

            if (CountOfRoots == CorrectNumberOfRoots && CompareDouble(TestRoot.first, CorrectRoots->first)
                && CompareDouble(TestRoot.second, CorrectRoots->second)) {

                printf("TEST №%d: OK\n\n", count_of_test);

                return 1;

            } else {

                 printf("TEST №%d: FAILED!\n" "EXPECTED: count of roots = %d, root1 = %lg, root2 = %lg\n"
                       "RECEIVED: count of roots = %d, root1 = %lg, root2 = %lg\n\n",
                       count_of_test, CorrectNumberOfRoots, CorrectRoots->first, CorrectRoots->second,
                       CountOfRoots, TestRoot.first, TestRoot.second);

                return 0;

            }

        default:

            printf("ERROR!!!");
            assert(false);
            return 0;


    }

}

void GroupOfTests() {

    int count_of_OK_tests = 0;

    SquareTrinomial TestTrinomial;
    EquationRootsQuantity NumberOfRoots;
    RootsOfTrinomial TestRoots;

    //Test #1
    TestTrinomial.senior_cf = 1;
    TestTrinomial.second_cf = -3;
    TestTrinomial.free_term = 2;
    TestRoots.first = 1;
    TestRoots.second = 2;
    NumberOfRoots = TWO_ROOTS;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #2
    TestTrinomial.senior_cf = 4;
    TestTrinomial.second_cf = -4;
    TestTrinomial.free_term = 1;
    TestRoots.first = 0.5;
    NumberOfRoots = ONE_ROOT;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #3
    TestTrinomial.senior_cf = 0;
    TestTrinomial.second_cf = 0;
    TestTrinomial.free_term = 0;
    NumberOfRoots = INFINITE_ROOTS_QUANTITY;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #4
    TestTrinomial.senior_cf = 0;
    TestTrinomial.second_cf = 0;
    TestTrinomial.free_term = 1;
    NumberOfRoots = NO_ROOTS;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #5
    TestTrinomial.senior_cf = 1;
    TestTrinomial.second_cf = -1;
    TestTrinomial.free_term = 2;
    NumberOfRoots = NO_ROOTS;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #6
    TestTrinomial.senior_cf = 1;
    TestTrinomial.second_cf = 2;
    TestTrinomial.free_term = 1;
    TestRoots.first = -1;
    NumberOfRoots = ONE_ROOT;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #7
    TestTrinomial.senior_cf = 0;
    TestTrinomial.second_cf = 2;
    TestTrinomial.free_term = -0.5;
    TestRoots.first= 0.25;
    NumberOfRoots = ONE_ROOT;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #8
    TestTrinomial.senior_cf = 4;
    TestTrinomial.second_cf = 0;
    TestTrinomial.free_term = -9;
    TestRoots.first= -1.5;
    TestRoots.second= 1.5;
    NumberOfRoots = TWO_ROOTS;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #9
    TestTrinomial.senior_cf = 1;
    TestTrinomial.second_cf = 0;
    TestTrinomial.free_term = 0;
    TestRoots.first= 0;
    NumberOfRoots = ONE_ROOT;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

    //Test #10
    TestTrinomial.senior_cf = 4;
    TestTrinomial.second_cf = -4;
    TestTrinomial.free_term = 0;
    TestRoots.first= 0;
    TestRoots.second= 1;
    NumberOfRoots = TWO_ROOTS;

    count_of_OK_tests += CheckCorrectnessOfSolve(&TestTrinomial, NumberOfRoots, &TestRoots);
    count_of_test++;

}
>>>>>>> 3659babd8f3d49b19163bea42c4930e613fde677
