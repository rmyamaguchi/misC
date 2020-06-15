#ifndef HEAP_H
#define HEAP_H

#include "HeapConf.h"

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