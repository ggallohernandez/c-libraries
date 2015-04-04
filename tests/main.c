#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../own_string.h"
#include "test.h"

void run_string_tests();
void test_si_own_string_h_ejecuta_los_casos_de_uso_correctamente();

int main()
{
    puts(":::: TESTING ENVIROMENT ::::");

    run_string_tests();

    return 0;
}

void run_string_tests()
{
    puts(":: Own String Library ::");

    test_si_own_string_h_ejecuta_los_casos_de_uso_correctamente();
}

void test_si_own_string_h_ejecuta_los_casos_de_uso_correctamente()
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

    puts(".. executing test_si_ejecuta_los_casos_de_uso_correctamente\n");

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
