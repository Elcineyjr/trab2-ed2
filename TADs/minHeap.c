#include <stdio.h>
#include <stdlib.h>
#include "minHeap.h"


struct min{
    Item* pq;   //priority queue that represents the binary heap
    int size;      //current size of pq
};


//Creates a empty min heap
MinHeap* minheap_create(int max_size){
    MinHeap* new_minheap = malloc(sizeof(*new_minheap));

    new_minheap->pq = malloc((max_size+1) * sizeof(int));   //mallocs the pq with max_size+1 cuz its starts from 1

    new_minheap->size = 0;         //pq starts empty

    return new_minheap;
}


void minheap_fix_up(MinHeap* heap, int k){
    while(k > 1 && greater(heap->pq[k/2], heap->pq[k])){    //while didnt hit the top of the binary heap and if is great than its father
        exch(heap->pq[k], heap->pq[k/2]);       //exchange positions 
        k = k/2;
    }
}


void minheap_fix_down(MinHeap* heap, int k){
    while(2*k <= heap->size){ //while the index is not bigger than the heap size
        int child = 2*k;    //get the left child

        if(child < heap->size && greater(heap->pq[child], heap->pq[child+1]))    //checks which child is smaller
            child++;

        if(greater(heap->pq[child], heap->pq[k]))     //if the smaller child is bigger than the father, its ordered, then stops
            break;
        
        exch(heap->pq[k], heap->pq[child]);         //exchange the smaller child with its father
        k = child;
    }
}


//Inserts an item in a given min heap
void minheap_insert(MinHeap* heap, Item i){
    heap->size++;     //increments the heap size 
    heap->pq[heap->size] = i;      //insert the item in the end of the heap 
    minheap_fix_up(heap, heap->size);      //propagates to the top until is heap ordered
}


//deletes the top elem of the min heap
Item minheap_delmin(MinHeap* heap){
    Item min = heap->pq[1]; 

    exch(heap->pq[1], heap->pq[heap->size]);   //exchange the min elem with the last elem 
    heap->size--;
    minheap_fix_down(heap, 1);      //propagates the top elem down util the heap is ordered again

    return min;
}


//returns the k item in the min heap
Item minheap_get_item(MinHeap* heap, int k){
    return heap->pq[k];
}


//change an specific item to a new, and reorder the heap 
void minheap_change_item(MinHeap* heap, int k, Item new){
    heap->pq[k] = new;
    minheap_fix_up(heap, k);        //if the new item is less than the previous one, it needs to go up
    minheap_fix_down(heap, k);      //if its bigger it goes down
}


//returns if the min heap is empty 
bool minheap_empty(MinHeap* heap){
    return heap->size == 0;
}


//returns the size of the min heap
int minheap_size(MinHeap* heap){
    return heap->size;
}


//frees the allocated memory for the min heap
void minheap_destroy(MinHeap* heap){
    free(heap->pq);
    free(heap);
}


//prints the elements of the min heap 
void minheap_print(MinHeap* heap){
    for(int i = 1; i <= heap->size; i++)
        printf("%d\n", heap->pq[i]);
}