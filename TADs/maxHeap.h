#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <stdbool.h>
#include "item.h"

typedef struct max MaxHeap;

MaxHeap* maxheap_create(int max_size);

void maxheap_fix_up(MaxHeap* heap, int k);

void maxheap_fix_down(MaxHeap* heap, int k);

void maxheap_insert(MaxHeap* heap, Item item);

Item maxheap_delmax(MaxHeap* heap);

Item maxheap_get_max(MaxHeap* heap);

bool maxheap_empty(MaxHeap* heap);

int maxheap_size(MaxHeap* heap);

void maxheap_destroy(MaxHeap* heap);

void maxheap_print(MaxHeap* heap);

#endif //MAX_HEAP_H