#include <stdio.h>
#include <stdlib.h>
#include "maxHeap.h"

//struct to represent a MAX HEAP
struct max{
    int max_size;
    Item* pq;       //priority queue to represent the binary heap
    int size;       //current size of the pq
};


//creates a new max heap
MaxHeap* maxheap_create(int max_size){
    MaxHeap* new_maxheap = malloc(sizeof(*new_maxheap));

    new_maxheap->max_size = max_size;           //TODO ver se isso vai ser usado

    new_maxheap->pq = malloc((max_size+1) * sizeof(Item));  //malloc an array with max_size+1 cuz the pq starts at 1

    new_maxheap->size = 0;      //pq size is empty

    return new_maxheap;
}


void maxheap_fix_up(MaxHeap* heap, int k){
    while(k > 1 && greater(heap->pq[k], heap->pq[k/2])){  //while son is greater than father
        exch(heap->pq[k], heap->pq[k/2]);             //exchange positions 
        k = k/2;
    }
}


void maxheap_fix_down(MaxHeap* heap, int k){
    while(2*k <= heap->size){   //while didnt hit the bottom of the heap 
        int son = 2*k;  //get the left son

        if(son < heap->size && less(heap->pq[son], heap->pq[son+1])) //checks which son is greater and update it
            son++;
        
        if(less(heap->pq[son], heap->pq[k]))    //if the biggest son is smaller than its father, the heap is ordered
            break;

        exch(heap->pq[k], heap->pq[son]);   //exchange the biggest son with the father
        k = son;
    }
}


//inserts an item in a given max heap
void maxheap_insert(MaxHeap* heap, Item item){
    heap->size++;   //updates the heap size
    heap->pq[heap->size] = item;    //inserts the item in the last position
    maxheap_fix_up(heap, heap->size);   //do a fix up to keep the heap ordered
}


//deletes the top value of the max heap
Item maxheap_delmax(MaxHeap* heap){
    int max = heap->pq[1];  //get the top of the heap

    exch(heap->pq[1], heap->pq[heap->size]); //puts the last elem of the heap on top
    heap->size--;
    maxheap_fix_down(heap, 1);  //do a fix down from the top to keep the heap ordered

    return max;
}


//get max elem of the max heap
Item maxheap_get_max(MaxHeap* heap){
    return heap->pq[1];
}


//returns if the max heap is empty
bool maxheap_empty(MaxHeap* heap){
    return heap->size == 0;
}


//returns the size of the max heap
int maxheap_size(MaxHeap* heap){
    return heap->size;
}


//destroys the allocated memory for the max heap
void maxheap_destroy(MaxHeap* heap){
    free(heap->pq);
    free(heap);
}


//prints the max heap
void maxheap_print(MaxHeap* heap){
    for(int i = 1; i <= heap->size; i++)
        printf("%d\n", heap->pq[i]);
}