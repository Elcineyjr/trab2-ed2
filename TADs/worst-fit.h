#ifndef WORST_FIT_H
#define WORST_FIT_H
#include "maxHeap.h"

void worst_fit(int* files_size_array, int array_size);

int compare(const void* disk1, const void* disk2);

#endif // WORST_FIT_H