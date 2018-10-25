#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxHeap.h"
#include "minHeap.h"
#include "binPacking.h"

#define MAX_SPACE_LEFT 1000000      //max amount in KB that will have left in a disk


/*
 * Calculates the bin pack problem using the WORST FIT heuristic
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

    printf("worst fit %d\n", maxheap_size(heap)); //prints in the screen how many disks were necessary to fit all files

    maxheap_destroy(heap);  //destroys the allocated heap
}


int compare(const void* disk1, const void* disk2){
    int d1 = *(int*)disk1; 
    int d2 = *(int*)disk2;

    return d2 - d1;
}


/*
 * Calculates the bin pack problem using the BEST FIT heuristic
 */
void best_fit(int* files_size_array, int array_size){
    MinHeap* heap = minheap_create(array_size); 

    minheap_insert(heap, MAX_SPACE_LEFT);   //inserts the first disk

    for(int i = 0; i < array_size; i++){    

        //if the file is bigger than the biggest space left in a disk, creates a new disk 
        if(files_size_array[i] > minheap_get_item(heap, minheap_size(heap))){   //TODO acho q isso devia dar errado
            minheap_insert(heap, MAX_SPACE_LEFT - files_size_array[i]);
            continue;
        }

        for(int j = 1; j <= minheap_size(heap); j++){ //for every disk of the heap

            if(files_size_array[i] <= minheap_get_item(heap, j)){   //if the file fits int the current disk

                int new_space_left = minheap_get_item(heap, j) - files_size_array[i];   //recalculates the size of the disk

                minheap_change_item(heap, j, new_space_left);   //reorder the heap with the new size 

                goto NEXT_ITERATION;
            }
        }
        //minheap_insert(heap, MAX_SPACE_LEFT - files_size_array[i]);   //if the file didnt fit in any of the disks, creates a new one

        NEXT_ITERATION: ;
    }

    printf("best fit %d\n", minheap_size(heap));

    minheap_destroy(heap);
}