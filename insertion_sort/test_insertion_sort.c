#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "insertion_sort.h"

int tests_run = 0;

size_t test0_size = 0;
int test0[0];

size_t test1_size = 2;
int test1[2] = { 1, 0 };

size_t test2_size = 6;
int test2[6] = {4,2,5,1,3,0};

static int arrayequal(size_t len, int a1[], int a2[]) // Assume arrays are the same size
{
	size_t i;
	
	for (i = 0; i < len; i++) {
		if (a1[i] != a2[i]) {
			return 0;
		}
	}
	return 1;
}

static char *insertion_sort_test0()
{
	int expected[0];

	insertion_sort(test0_size, test0);
	mu_assert("Failed test0, expected []",
			  arrayequal(test0_size, test0, expected));
	return 0;
}

static char *insertion_sort_test1()
{
	int expected[2] = { 0, 1 };

	insertion_sort(test1_size, test1);
	mu_assert("Failed test1, expected [0, 1]",
			  arrayequal(test1_size, test1, expected));
	return 0;
}

static char *insertion_sort_test2()
{
	int expected[6] = {0,1,2,3,4,5};

	insertion_sort(test2_size, test2);
	mu_assert("Failed test2, expected [0, 1, 2, 3, 4, 5]",
			  arrayequal(test2_size, test2, expected));
	return 0;
}

static char *all_tests()
{
	mu_run_test(insertion_sort_test0);
	mu_run_test(insertion_sort_test1);
	mu_run_test(insertion_sort_test2);
	return 0;
}

int main(int argc, char *argv[])
{
	char *result;

	result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	} else {
		printf("Passed all %d tests.\n", tests_run);
	}

	return result != 0;
}
