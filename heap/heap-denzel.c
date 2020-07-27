#include<stdio.h>

int leftChild(int parent);
int rightChild(int parent);
int parent(int child);
void swap(int i, int j, int arr[]);
void maxHeapify(int size, int index, int arr[]);
void buildMaxHeap(int size, int arr[]);
void heapSort(int size, int arr[]);


int leftChild(int parent)
{
    return 2 * parent + 1;
}

int rightChild(int parent)
{
    return 2 * parent + 2;
}

int parent(int curr)
{
    return (curr -1) / 2;
}

void swap(int first, int second, int arr[])
{
    int holder = arr[first];

    arr[first] = arr[second];
    arr[second] = holder;
}

   
void maxHeapify(int size, int index, int arr[])
{
    int largest,
        left = leftChild(index),
        right = rightChild(index);
    
    if(left < size && arr[left] > arr[index])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }

    if(right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != index)
    {
        swap(index, largest, arr);
        maxHeapify(size, largest, arr);
    }
}

void buildMaxHeap(int size, int arr[])
{
    for(int i = size/2; i >= 0; i--)
    {
        maxHeapify(size, i, arr);
    }
}

void heapSort(int size, int arr[])
{
    buildMaxHeap(size, arr);
    for(int i = size; i > 1; i--)
    {
        swap(0, i - 1, arr);
        size = size - 1;
        maxHeapify(size, 0, arr);
    }
}
