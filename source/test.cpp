#include "test.h"
#include "solve_square_equation.h"

static const char* RED = "\033[0;31m";
static const char* GRN = "\033[0;32m";
static const char* DEFAULT = "\033[0m";


#define READ_DOUBLE_FROM_FILE(struct_ptr, field_name)                               \
do {                                                                                \
    int prev_correct_numbers_test = check_correct_numbers_test;                     \
    struct_ptr->field_name = ReadNumber(ptr_to_test, &check_correct_numbers_test);  \
    if (prev_correct_numbers_test == check_correct_numbers_test)                    \
    {                                                                               \
        return 0;                                                                   \
    }                                                                               \
} while (0);

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
    int NUMBER_OF_TESTS = 0;
    FILE *ptr_to_test = fopen(file_name, "r");
    if (ptr_to_test == nullptr) {
        printf("File %s wasn't found!!!\n", file_name);
        return;
    }

    int count_of_ok_tests = 0;

    SquareTrinomialCoef RefTrinomial;
    EquationRootsQuantity CorrectNumberOfRoots = NO_ROOTS;
    RootsOfTrinomial RefRoots;

    while (ReadCorrectSqrTrinomial(&RefTrinomial, &CorrectNumberOfRoots, &RefRoots, ptr_to_test))
    {
        NUMBER_OF_TESTS++;
        printf("Test ¹%d ", NUMBER_OF_TESTS);
        count_of_ok_tests += CheckCorrectnessOfSolve(&RefTrinomial, CorrectNumberOfRoots, &RefRoots);
    }
    printf("Tests passed: %d / %d", count_of_ok_tests, NUMBER_OF_TESTS);
}

bool ReadCorrectSqrTrinomial(SquareTrinomialCoef *RefTrinomial,
                             EquationRootsQuantity *CorrectNumberOfRoots,
                             RootsOfTrinomial *RefRoots, FILE *ptr_to_test)
{

    int check_correct_numbers_test = 0;

    READ_DOUBLE_FROM_FILE(RefTrinomial, senior_cf) //immediately return from function by mistake
    READ_DOUBLE_FROM_FILE(RefTrinomial, second_cf)
    READ_DOUBLE_FROM_FILE(RefTrinomial, free_term)
    READ_DOUBLE_FROM_FILE(RefRoots,     first)
    READ_DOUBLE_FROM_FILE(RefRoots,     second)

    int Temp = 0;
    int scanf_correctness_check_result = fscanf(ptr_to_test, "%d", &Temp);
    if (scanf_correctness_check_result == EOF) {
        return 0;
    }
    check_correct_numbers_test++;

    *CorrectNumberOfRoots = (EquationRootsQuantity) Temp;

    return check_correct_numbers_test == 6;
}

double ReadNumber(FILE *ptr_to_test, int *check_correct_numbers_test)
{
    double temp = NAN; //time variable
    int scanf_correctness_check_result = 0; //variable that checks the correctness of reading from the file
    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (scanf_correctness_check_result == EOF) {
        //assert(0 && "Error! The program can't read the var!\n");
        return -1;
    }
    (*check_correct_numbers_test)++;
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");
    return temp;
}

void PrintEquation(const SquareTrinomialCoef *CorrectTrinomial)
{
    printf("%s EQUATION: %lg * x^2 + %lg * x + %lg\n %s",
           RED,
           CorrectTrinomial->senior_cf,
           CorrectTrinomial->second_cf,
           CorrectTrinomial->free_term,
           DEFAULT);
}
