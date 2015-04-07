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

int assert_str_null(char * a)
{
    return a == NULL;
}

void print_done_str(char * received, t_test_case_str * test)
{
    printf("OK %s received, %s expected (a: %s, b: %s, n: %d)\n", received, test->expected, test->a, test->b, test->n);

}

void print_failed_str(char * received, t_test_case_str * test)
{
    printf(">> FAILED << %s received, %s expected (a: %s, b: %s, n: %d)\n", received, test->expected, test->a, test->b, test->n);
}

void print_done_matrix_int(t_test_case_matrix_int * test)
{
    printf("OK ");
    show_matrix(test->m, TAM, TAM);
    printf("%d received, %d expected\n", test->received, test->expected);

}

void print_failed_matrix_int(t_test_case_matrix_int * test)
{
    printf("FAILED ");
    show_matrix(test->m, TAM, TAM);
    printf("%d received, %d expected\n", test->received, test->expected);
}

void print_result(t_test_result * result)
{
    printf("\n ## %d executed tests, %d passed, %d failed\n\n", result->total, result->passed, result->failed);
}

void show_matrix(int * m, rows, cols)
{
    int col = 0, i, top = rows * cols;

    for (i = 0; i < top; i++) {
        printf("%3d", *m);
        col++;

        if (col == cols) {
            col = 0;
            puts("");
        }
    }

}
