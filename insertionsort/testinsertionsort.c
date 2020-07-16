#include <stdio.h>
#include "minunit.h"
#include "insertionsort.h"

int tests_run = 0;

int test0_size = 0;
int test0[0];

int test1_size = 2;
int test1[2] = { 1, 0 };

int test2_size = 6;
int test2[6] = {4,2,5,1,3,0};

static int arrayequal(int size, int arr1[], int arr2[]) // Assume arrays are the same size
{
	int i;
	
	for (i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}
	return 1;
}

static char *insertionsort_test0()
{
	int expected[0];

	insertionsort(test0_size, test0);
	mu_assert("Failed test0, expected []",
			  arrayequal(test0_size, test0, expected));
	return 0;
}

static char *insertionsort_test1()
{
	int expected[2] = { 0, 1 };

	insertionsort(test1_size, test1);
	mu_assert("Failed test1, expected [0, 1]",
			  arrayequal(test1_size, test1, expected));
	return 0;
}

static char *insertionsort_test2()
{
	int expected[6] = {0,1,2,3,4,5};

	insertionsort(test2_size, test2);
	mu_assert("Failed test2, expected [0, 1, 2, 3, 4, 5]",
			  arrayequal(test2_size, test2, expected));
	return 0;
}

static char *all_tests()
{
	mu_run_test(insertionsort_test0);
	mu_run_test(insertionsort_test1);
	mu_run_test(insertionsort_test2);
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
