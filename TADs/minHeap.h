#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <stdbool.h>
#include "item.h"

typedef struct min MinHeap;

MinHeap* minheap_create(int max_size);

void minheap_fix_up(MinHeap* heap, int k);

void minheap_fix_down(MinHeap* heap, int k);

void minheap_insert(MinHeap* heap, Item i);

Item minheap_delmin(MinHeap* heap);

Item minheap_get_item(MinHeap* heap, int k);

void minheap_change_item(MinHeap* heap, int k, Item new);

bool minheap_empty(MinHeap* heap);

int minheap_size(MinHeap* heap);

void minheap_destroy(MinHeap* heap);

void minheap_print(MinHeap* heap);

#endif //MIN_HEAP_H