#include <stdlib.h>

void insertion_sort(size_t len_a, int a[])
{
	size_t i;
	size_t j;
	int key;

	if (len_a < 2) {
		return;
	}

	for (j = 1; j < len_a; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i -= 1;
		}
		a[i+1] = key;
	}
}
