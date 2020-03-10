
#include <time.h>
#include <stdlib.h>
#include "Heap.h"

#define MIN 0
#define MAX 100
#define SIZE 50

static int random(int rand, int min, int max)
{
    return rand % (max - min + 1) + min;
}

int main(void)
{
    Data array[SIZE];
    HeapPtr heap;

    srand(time(0));
    for (int i = 0; i < SIZE; i++)
        array[i] = random(rand(), MIN, MAX);

    heap = createHeap(array, SIZE);
    printHeap(heap);

    heapSort(heap);
    printHeap(heap);

    deleteHeap(heap);
}