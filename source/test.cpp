#include "test.h"
#include "solve_square_equation.h"

static const char* ESCRED = "\033[0;31m";
static const char* ESCGREEN = "\033[0;32m";
static const char* ESCDEFAULT = "\033[0m";


#define READ_DOUBLE_FROM_FILE(struct_ptr, field_name)                               \
do {                                                                                \
    int prev_correct_numbers_test = check_correct_numbers_test;                     \
    struct_ptr->field_name = ReadNumber(ptr_to_test, &check_correct_numbers_test);  \
    if (prev_correct_numbers_test == check_correct_numbers_test)                    \
    {                                                                               \
        return 0;                                                                   \
    }                                                                               \
} while (0);

int CheckCorrectnessOfSolve(const SquareTrinomialCoef *correct_trinomial,
                            const RootsOfTrinomial *correct_root)
{
    assert(correct_trinomial != nullptr);
    assert(correct_root != nullptr);
    SquareTrinomialCoef test_trinomial;
    RootsOfTrinomial test_root;

    test_trinomial.senior_cf = correct_trinomial->senior_cf;
    test_trinomial.second_cf = correct_trinomial->second_cf;
    test_trinomial.free_term = correct_trinomial->free_term;

    SolveSquareEquation(&test_trinomial, &test_root);

    if (test_root.number != correct_root->number)
    {
        printf("%s FAILED!\n"
              "EXPECTED: count of roots = %d\n"
              "RECEIVED: count of roots = %d\n %s",
              ESCRED, test_root.number, correct_root->number, ESCDEFAULT);

        PrintEquation(correct_trinomial);
        return 0;
    }

    switch(correct_root->number)
    {
        case NO_ROOTS:
            printf("%s OK\n %s", ESCGREEN, ESCDEFAULT);
            return 1;

        case INFINITE_ROOTS_QUANTITY:
            printf("%s OK\n %s", ESCGREEN, ESCDEFAULT);
            return 1;

        case ONE_ROOT:
            if (CompareDouble(test_root.first, correct_root->first))
            {
                printf("%s OK\n %s", ESCGREEN, ESCDEFAULT);
                return 1;
            } else {
                 printf("%s FAILED!\n"
                        "EXPECTED: root = %lg\n"
                        "RECEIVED: count of roots = %lg\n %s",
                        ESCRED, correct_root->first,
                        test_root.first, ESCDEFAULT);

                PrintEquation(correct_trinomial);
                return 0;

            }

        case TWO_ROOTS:
            if (CompareDouble(test_root.first,  correct_root->first) &&
                CompareDouble(test_root.second, correct_root->second))
            {
                printf("%s OK\n %s", ESCGREEN, ESCDEFAULT);
                return 1;
            } else {
                 printf("%s FAILED!\n"
                        "EXPECTED: root1 = %lg and root2 = %lg\n"
                        "RECEIVED: root1 = %lg and root2 = %lg\n %s",
                        ESCRED, correct_root->first, correct_root->second,
                        test_root.first, test_root.second, ESCDEFAULT);

                PrintEquation(correct_trinomial);
                return 0;

            }

        default:
            printf("ERROR!!!");
            assert(false);
            return 0;
    }
    return 0;
}

void RunTests(const char *file_name)
{
    int number_of_tests = 0;
    FILE *ptr_to_test = fopen(file_name, "r");
    if (ptr_to_test == nullptr) {
        printf("File %s wasn't found!!!\n", file_name);
        assert(0);
        return;
    }

    int count_of_ok_tests = 0;

    SquareTrinomialCoef ref_trinomial;
    RootsOfTrinomial ref_roots;

    while (ReadCorrectSqrTrinomial(&ref_trinomial, &ref_roots, ptr_to_test))
    {
        number_of_tests++;
        printf("Test ¹%d ", number_of_tests);
        count_of_ok_tests += CheckCorrectnessOfSolve(&ref_trinomial, &ref_roots);
    }
    printf("Tests passed: %d / %d", count_of_ok_tests, number_of_tests);
}

bool ReadCorrectSqrTrinomial(SquareTrinomialCoef *ref_trinomial,
                             RootsOfTrinomial *ref_roots, FILE *ptr_to_test)
{

    int check_correct_numbers_test = 0;

    READ_DOUBLE_FROM_FILE(ref_trinomial, senior_cf) //immediately return from function by mistake
    READ_DOUBLE_FROM_FILE(ref_trinomial, second_cf)
    READ_DOUBLE_FROM_FILE(ref_trinomial, free_term)
    READ_DOUBLE_FROM_FILE(ref_roots,     first)
    READ_DOUBLE_FROM_FILE(ref_roots,     second)

    int Temp = 0;
    int scanf_correctness_check_result = fscanf(ptr_to_test, "%d", &Temp);
    if (scanf_correctness_check_result == EOF) {
        return 0;
    }
    check_correct_numbers_test++;

    ref_roots->number = (EquationRootsQuantity) Temp;

    return check_correct_numbers_test == 6;
}

double ReadNumber(FILE *ptr_to_test, int *check_correct_numbers_test)
{
    double temp = NAN; //temporary variable
    int scanf_correctness_check_result = 0; //variable that checks the correctness of reading from the file
    scanf_correctness_check_result = fscanf(ptr_to_test, "%lg", &temp);
    if (scanf_correctness_check_result == EOF) {
        return -1;
    }
    (*check_correct_numbers_test)++;
    assert((isnan(temp) == false) && "Error! Variable 'temp' = NAN!\n");
    assert((isfinite(temp)) && "Error! Variable 'temp' = INF!\n");
    return temp;
}

void PrintEquation(const SquareTrinomialCoef *correct_trinomial)
{
    printf("%s EQUATION: %lg * x^2 + %lg * x + %lg\n %s",
           ESCRED,
           correct_trinomial->senior_cf,
           correct_trinomial->second_cf,
           correct_trinomial->free_term,
           ESCDEFAULT);
}
