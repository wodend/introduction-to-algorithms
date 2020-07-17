#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "int_arr.h"

// Test whether a1 is equal to a2.
int arr_eq(size_t len_a1, int a1[], size_t len_a2, int a2[])
{
	size_t i;

	if (len_a1 != len_a2) {
		return 0;
	}
	for (i = 0; i < len_a1; i++) {
		if (a1[i] != a2[i]) {
			return 0;
		}
	}
	return 1;
}

// Allocate a buffer to store a string representing an array.
// Result must be freed by the caller.
char *arr_to_str(size_t len_arr, int *arr)
{
	size_t len_buf;
	char *buf;
	size_t cur;
	size_t i;
	size_t int_width;
	len_buf = len_arr + 3;
	if (!(buf = malloc(sizeof(char) * len_buf))) {
		printf("Failed to malloc (%s).", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (len_arr == 0) {
		snprintf(buf, len_buf, "[]");
		return buf;
	}
	cur = 0;
	buf[cur++] = '[';
	for (i = 0; i < len_arr; i++) {
		int_width = (int) ((ceil(log10(arr[i])) + 1) * sizeof(char));
		if (cur + int_width + 2 > len_buf) {
			len_buf *= 2;
			if ((buf = realloc(buf, len_buf)) == NULL) {
				printf("Failed to realloc (%s).", strerror(errno));
				exit(EXIT_FAILURE);
			}
		}
		cur += snprintf(&buf[cur], len_buf-cur, "%d, ", arr[i]);
	}
	buf[cur-2] = ']';
	buf[cur-1] = '\0';
	if ((buf = realloc(buf, cur*sizeof(char))) == NULL) {
		printf("Failed to realloc (%s).", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return buf;
}
