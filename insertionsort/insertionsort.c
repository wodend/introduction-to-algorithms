void insertionsort(int size, int arr[])
{
	int i;
	int j;
	int key;

	if (size < 2) {
		return;
	}

	for (j = 1; j < size; j++) {
		key = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i -= 1;
		}
		arr[i+1] = key;
	}
}
