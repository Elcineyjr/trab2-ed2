#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "worst-fit.h"

#define MAX_SPACE_LEFT 1000000      //max amount in KB that will have left in a disk


/*
 * Calculates the bin pack problem using the worst fit heuristic
 */
void worst_fit(int* files_size_array, int array_size){
    MaxHeap* heap = maxheap_create(array_size);

    maxheap_insert(heap, MAX_SPACE_LEFT);   //inserts the first disk to avoid checking if the heap is empty inside the loop

    for(int i = 0; i < array_size; i++){
        if(maxheap_get_max(heap) >= files_size_array[i]){   //there is space to save the file in the biggest disk
            
            //removes the disk from the heap and calculates how much space will be left after saving the file in this disk
            int space_left = maxheap_delmax(heap) - files_size_array[i];

            //inserts the disk in the heap again
            maxheap_insert(heap, space_left);

        }else{  //the file doesnt fit in the disk with the biggest space left

            //creates a new disk, saves the file in the disk and inserts it in the heap
            maxheap_insert(heap, (MAX_SPACE_LEFT - files_size_array[i]) );
        }
    }

    printf("%d\n", maxheap_size(heap)); //prints in the screen how many disks were necessary to fit all files

    maxheap_destroy(heap);  //destroys the allocated heap
}


int compare(const void* disk1, const void* disk2){
    int d1 = *(int*)disk1; 
    int d2 = *(int*)disk2;

    return d2 - d1;
}