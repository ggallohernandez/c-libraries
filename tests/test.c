#include "test.h"

int assert_int_equals(int a, int b)
{
    return a == b;
}

int assert_str_equals(char * a, char * b)
{
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }

    return *a == *b;
}

void print_done_str(char * received, t_test_case_str * test)
{
    printf("OK %s received, %s expected (a: %s, b: %s, n: %d)\n", received, test->expected, test->a, test->b, test->n);

}

void print_failed_str(char * received, t_test_case_str * test)
{
    printf(">> FAILED << %s received, %s expected (a: %s, b: %s, n: %d)\n", received, test->expected, test->a, test->b, test->n);
}

void print_result(t_test_result * result)
{
    printf("\n ## %d executed tests, %d passed, %d failed\n\n", result->total, result->passed, result->failed);
}
