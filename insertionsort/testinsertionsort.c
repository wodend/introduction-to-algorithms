#include <stdio.h>
#include "minunit.h"
#include "insertionsort.h"

int tests_run = 0;

int test0[0];
int test1[2] = { 1, 0 };

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

	insertionsort(test0); // Arrays are pass by reference
	mu_assert("Failed test0, expected []", arrayequal(0, test0, expected));
	return 0;
}

static char *insertionsort_test1()
{
	int expected[2] = { 0, 1 };

	insertionsort(test1);
	mu_assert("Failed test1, expected [0, 1]", arrayequal(2, test1, expected));
	return 0;
}

static char *all_tests()
{
	mu_run_test(insertionsort_test0);
	mu_run_test(insertionsort_test1);
	return 0;
}

int main(int argc, char *argv[])
{
	char *result;

	printf("Run all %d tests.\n", tests_run);
	result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	} else {
		printf("Passed all tests.\n");
	}

	return result != 0;
}
