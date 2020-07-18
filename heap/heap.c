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
