#ifndef HEAP_H
#define HEAP_H

#include "HeapConf.h"

#define P(i) (i - 1) / 2 // Parent node
#define L(i) 2 * i + 1   // Left child
#define R(i) 2 * i + 2   // Right child

#define MIN_ID(arr, i1, i2) arr[i1] > arr[i2] ? i2 : i1
#define MAX_ID(arr, i1, i2) arr[i1] > arr[i2] ? i1 : i2

typedef struct Heap *HeapPtr;

/**
 * @brief Create a Max Heap from data
 * 
 * @param[in] data 
 * @param[in] size 
 * @return HeapPtr to the new heap
 */
HeapPtr createHeap(const Data *data, int size);

/**
 * @brief Delete the heap
 * 
 * @param[in] heap 
 */
void deleteHeap(HeapPtr heap);

/**
 * @brief Heapsort
 * 
 * @param[in] heap 
 */
void heapSort(HeapPtr heap);

/**
 * @brief Prints the heap in array form
 * 
 * @param[in] heap 
 */
void printHeap(const HeapPtr heap);

#endif /* HEAP_H */