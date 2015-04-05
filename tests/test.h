#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <string.h>

#define STR_LENGTH 200

typedef struct
{
	int total;
	int passed;
	int failed;
} t_test_result;

typedef struct
{
	char a[STR_LENGTH];
	char b[STR_LENGTH];
	unsigned int n;
	char expected[STR_LENGTH];
} t_test_case_str;

int assert_int_equals(int, int);
int assert_str_equals(char *, char *);
int assert_str_null(char *);

void print_done_str(char * received, t_test_case_str * test);
void print_failed_str(char * received, t_test_case_str * test);
void print_result(t_test_result *);

#endif // TEST_H_INCLUDED
