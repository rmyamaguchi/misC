
#include <stdlib.h>
#include <string.h>
#include "Heap.h"

#ifdef FANCY_PRINT_HEAP
#include <math.h>
#endif /* FANCY_PRINT_HEAP */

struct Heap
{
    int size;
    Data *data;
};

/**
 * @brief  Swap two data
 * 
 * @param data1 
 * @param data2 
 */
static void swap(Data *data1, Data *data2)
{
    Data temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

/**
 * @brief Perform a step heapify'ing the data with root in i
 * 
 * @param[in] data to heapify
 * @param[in] size of data
 * @param[in] i is the root of the subtree to be heapify'd
 */
static void heapifyStep(Data *data, int size, int i)
{
    int mi = i; // root

    /* Check whether left child exists and is larger than right child if this exists */
    if (L(i) < size)
        mi = R(i) < size ? MAX_ID(data, L(i), R(i)) : L(i);
    /* Put the larger one in the root and heapify the branch down */
    if (data[mi] > data[i])
    {
        swap(&data[mi], &data[i]);
        heapifyStep(data, size, mi);
    }
}

/**
 * @brief Completely heapify the data with size
 * 
 * @param[in] data to heapify
 * @param[in] size of data
 */
static void heapify(Data *data, int size)
{
    /* Start from the last non-leaf node */
    for (int i = P(size - 1); i >= 0; i--)
        heapifyStep(data, size, i);
}

/**
 * @brief Create a Max Heap from data
 */
HeapPtr createHeap(const Data *data, int size)
{
    HeapPtr heap = malloc(sizeof(*heap));
    heap->data = malloc(size * sizeof(*heap->data));

    heap->size = size;
    memcpy(heap->data, data, size * sizeof(*heap));

    heapify(heap->data, heap->size);
    return heap;
}

/**
 * @brief Delete the heap
 */
void deleteHeap(HeapPtr heap)
{
    free(heap->data);
    free(heap);
}

/**
 * @brief Heapsort
 */
void heapSort(HeapPtr heap)
{
    /* Largest is always root */
    for (int i = heap->size - 1; i >= 0; i--)
    {
        /* Put root in the end and heapify ignoring it */
        swap(&heap->data[0], &heap->data[i]);
        heapify(heap->data, i);
    }
}

/**
 * @brief Prints the heap in array form
 */
void printHeap(const HeapPtr heap)
{
    PRINT("\r\n");
    for (int i = 0; i < heap->size; i++)
        PRINT("%d ", heap->data[i]);
}

#ifdef FANCY_PRINT_HEAP
static void printChild(Data *data, int i)
{
    PRINT("%d %d|", data[L(i)], data[R(i)]);
}

void fancyPrintHeap(Data *data, int size)
{
    int i, n;
    int depth = log2(size);
    PRINT("%d|", data[0]);
    for (int d = 0; d <= depth; d++)
    {
        PRINT("\r\n");
        i = pow(2, d) - 1;
        n = pow(2, d);
        while (n-- > 0 && i < P(size))
            printChild(data, i++);
    }
}
#endif /* FANCY_PRINT_HEAP */
