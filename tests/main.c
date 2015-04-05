#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../own_string.h"
#include "test.h"

void run_string_tests();
void test_si_own_strcat_ejecuta_los_casos_de_uso_correctamente();
void test_si_own_strncat_ejecuta_los_casos_de_uso_correctamente();
void test_si_own_strchr_ejecuta_los_casos_de_uso_correctamente();
void test_si_own_strchr_retorna_null_cuando_no_hay_coincidencia();

int main()
{
    puts(":::: TESTING ENVIROMENT ::::");

    run_string_tests();

    return 0;
}

void run_string_tests()
{
    puts(":: Own String Library ::");

    test_si_own_strcat_ejecuta_los_casos_de_uso_correctamente();
    test_si_own_strncat_ejecuta_los_casos_de_uso_correctamente();
    test_si_own_strchr_ejecuta_los_casos_de_uso_correctamente();
    test_si_own_strchr_retorna_null_cuando_no_hay_coincidencia();
}

void test_si_own_strcat_ejecuta_los_casos_de_uso_correctamente()
{
    int i;
    char * str;
    char  src[STR_LENGTH];
    t_test_case_str * test;

    t_test_case_str tests[] = {
        {.a = "destination",    .b = "source",      .expected = "destinationsource" },
        {.a = "luis",           .b = "guillermo",   .expected = "luisguillermo"     },
        {.a = "",               .b = "",            .expected = ""                  },
        {.a = "",               .b = "source",      .expected = "source"            },
        {.a = "destination",    .b = "",            .expected = "destination"       },
    };

    t_test_result result;
    result.total = result.passed = result.failed = 0;

    puts(".. executing void test_si_own_strcat_ejecuta_los_casos_de_uso_correctamente\n");

    for (i = 0; i < sizeof(tests) / sizeof(t_test_case_str); i++) {
        test = tests +i;
        strcpy(src, test->a);

        if (assert_str_equals(str = own_strcat(src, test->b), test->expected)) {
            result.passed++;
            print_done_str(str, test);
        } else {
            result.failed++;
            print_failed_str(str, test);
        }

        result.total++;
    }

    print_result(&result);
}

void test_si_own_strncat_ejecuta_los_casos_de_uso_correctamente()
{
    int i;
    char * str;
    char  src[STR_LENGTH];
    t_test_case_str * test;

    t_test_case_str tests[] = {
        {.a = "destination",    .b = "source",      .n = 3,     .expected = "destinationsou"    },
        {.a = "destinat",       .b = "ion",         .n = 5,     .expected = "destination"       },
        {.a = "dest",           .b = "",            .n = 3,     .expected = "dest"              },
        {.a = "",               .b = "source",      .n = 3,     .expected = "sou"               },
        {.a = "",               .b = "source",      .n = 6,     .expected = "source"            },
        {.a = "",               .b = "",            .n = 10,    .expected = ""                  },
        {.a = "dest",           .b = "src",         .n = 0,     .expected = "dest"              },
    };

    t_test_result result;
    result.total = result.passed = result.failed = 0;

    puts(".. executing test_si_own_strncat_ejecuta_los_casos_de_uso_correctamente\n");

    for (i = 0; i < sizeof(tests) / sizeof(t_test_case_str); i++) {
        test = tests +i;
        strcpy(src, test->a);

        if (assert_str_equals(str = own_strncat(src, test->b, test->n), test->expected)) {
            result.passed++;
            print_done_str(str, test);
        } else {
            result.failed++;
            print_failed_str(str, test);
        }

        result.total++;
    }

    print_result(&result);
}

void test_si_own_strchr_ejecuta_los_casos_de_uso_correctamente()
{
    int i;
    char * str;
    char  src[STR_LENGTH];
    t_test_case_str * test;

    t_test_case_str tests[] = {
        {.a = "string",         .n = 'r',   .expected = "ring" },
        {.a = "This is a test", .n = 't',   .expected = "test" },
        {.a = "This is a teSt", .n = 'S',   .expected = "St"   },
        {.a = "This is a test", .n = '\0',  .expected = ""     },
    };

    t_test_result result;
    result.total = result.passed = result.failed = 0;

    puts(".. executing test_si_own_strchr_ejecuta_los_casos_de_uso_correctamente\n");

    for (i = 0; i < sizeof(tests) / sizeof(t_test_case_str); i++) {
        test = tests +i;
        strcpy(src, test->a);

        if (assert_str_equals(str = own_strchr(src, test->n), test->expected)) {
            result.passed++;
            print_done_str(str, test);
        } else {
            result.failed++;
            print_failed_str(str, test);
        }

        result.total++;
    }

    print_result(&result);
}

void test_si_own_strchr_retorna_null_cuando_no_hay_coincidencia()
{
    int i;
    char * str;
    char  src[STR_LENGTH];
    t_test_case_str * test;

    t_test_case_str tests[] = {
        {.a = "This is a test", .n = 'b',   .expected = NULL   },
        {.a = "",               .n = 'a',   .expected = NULL   },
    };

    t_test_result result;
    result.total = result.passed = result.failed = 0;

    puts(".. executing test_si_own_strchr_retorna_null_cuando_no_hay_coincidencia\n");

    for (i = 0; i < sizeof(tests) / sizeof(t_test_case_str); i++) {
        test = tests +i;
        strcpy(src, test->a);

        if (assert_str_null(str = own_strchr(src, test->n))) {
            result.passed++;
            print_done_str(str, test);
        } else {
            result.failed++;
            print_failed_str(str, test);
        }

        result.total++;
    }

    print_result(&result);
}
