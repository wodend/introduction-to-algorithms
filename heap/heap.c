#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

void max_heapify(size_t len_a, int a[], size_t i)
{
	int l;
	int r;
	int largest;


	l = LEFT(i);
	r = RIGHT(i);
	if (l < len_a && a[l] > a[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if (r < len_a && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		SWAP(a[i], a[largest]);
		max_heapify(len_a, a, largest);
	}
}

void build_max_heap(size_t len_a, int a[])
{
	int i;

	for (i = len_a / 2; i >= 0; --i) {
		max_heapify(len_a, a, i);
	}
}

int main(int argc, int *argv[])
{
	int len_a = 7;
	int a[] = {0, 1, 2, 3, 4, 5, 6};
	int j = 0;

	build_max_heap(len_a, a);
	// Print result.
	for (j = 0; j < len_a; j++) {
		printf("%d ", a[j]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
