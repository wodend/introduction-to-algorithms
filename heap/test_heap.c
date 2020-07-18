#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"
#include "int_arr.h"
#include "minunit.h"

int tests_run = 0;

size_t len_test0 = 0;
int test0[0];

size_t len_test1 = 2;
int test1[2] = {0, 1};

size_t len_test2 = 7;
int test2[7] = {0, 1, 2, 3, 4, 5, 6};

// Result must be freed by the caller.
static char *message_arr(char *test, int len_a1, int *a1, int len_a2, int *a2)
{
	char *str_a1;
	char *str_a2;
	size_t len_message;
	char *message;

	str_a1 = arr_to_str(len_a1, a1);
	str_a2 = arr_to_str(len_a2, a2);
	len_message = strlen(test) + strlen(str_a1) + strlen(str_a2) + 32;
	if (!(message = malloc(len_message * sizeof(char)))) {
		printf("Failed to malloc (%s).", strerror(errno));
		exit(EXIT_FAILURE);
	}
	snprintf(message,
			 len_message,
			 "Failed %s, got: %s, expected: %s",
			 test,
			 str_a1,
			 str_a2);
	free(str_a1);
	free(str_a2);
	return message;
}

static char *build_max_heap_test0()
{
	char *message;

	size_t len_expected = 0;
	int expected[0];

	build_max_heap(len_test0, test0);
	message = message_arr("build_max_heap_test0",
	                      len_test0,
	                      test0,
	                      len_expected,
	                      expected);
	mu_assert(message, arr_eq(len_test0, test0, len_expected, expected));
	free(message);
	return 0;
}

static char *build_max_heap_test1()
{
	char *message;

	size_t len_expected = 2;
	int expected[2] = {1, 0};

	build_max_heap(len_test1, test1);
	message = message_arr("build_max_heap_test1",
	                      len_test1,
	                      test1,
	                      len_expected,
	                      expected);
	mu_assert(message, arr_eq(len_test1, test1, len_expected, expected));
	free(message);
	return 0;
}

static char *build_max_heap_test2()
{
	char *message;

	size_t len_expected = 7;
	int expected[7] = {6, 4, 5, 3, 1, 0, 2};

	build_max_heap(len_test2, test2);
	message = message_arr("build_max_heap_test2",
	                      len_test2,
	                      test2,
	                      len_expected,
	                      expected);
	mu_assert(message, arr_eq(len_test2, test2, len_expected, expected));
	free(message);
	return 0;
}

static char *all_tests()
{
	mu_run_test(build_max_heap_test0);
	mu_run_test(build_max_heap_test1);
	mu_run_test(build_max_heap_test2);
	return 0;
}

int main(int argc, char *argv[])
{
	char *result;

	result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
		free(result);
	} else {
		printf("Passed all %d tests.\n", tests_run);
	}

	return result != 0;
}
