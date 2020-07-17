#define PARENT(i) i / 2
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2
#define SWAP(a,b) a ^= b ^= a ^= b

void max_heapify(size_t len_a, int a[], size_t i);
void build_max_heap(size_t len_a, int a[]);
