#ifndef BIN_PACKING_H
#define BIN_PACKING_H

void worst_fit(int* files_size_array, int array_size);

int compare(const void* disk1, const void* disk2);

void best_fit(int* files_size_array, int array_size);

#endif // BIN_PACKING_H