#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "minHeap.h"


struct min{
    int max_size;
    Item* pq;
    int N;
};


//Creates a empty min heap
MinHeap* minheap_create(int max_size){
    MinHeap* new_minheap = malloc(sizeof(*new_minheap));

    new_minheap->max_size = max_size;

    new_minheap->pq = malloc((max_size+1) * sizeof(int));

    new_minheap->N = 0;

    return new_minheap;
}


void minheap_fix_up(MinHeap* heap, int k){
    while(k > 1 && greater(heap->pq[k/2], heap->pq[k])){
        exch(heap->pq[k], heap->pq[k/2]);
        k = k/2;
    }
}


void minheap_fix_down(MinHeap* heap, int k){
    while(2*k <= heap->N){ //while the index is not bigger than the heap size
        int child = 2*k;    //get child

        if(child < heap->N && greater(heap->pq[child], heap->pq[child+1]){    //checks which child is bigger
            child++;
        }

        if(!greater(heap->pq[child], heap->pq[k]))
            break;
        
        exch(heap->pq[k], heap->pq[child]);
        k = child;
    }
}


//Inserts an item in a given min heap
void minheap_insert(MinHeap* heap, Item i){
    heap->N++;
    heap->pq[heap->N] = i;
    minheap_fix_up(heap, heap->N);
}


void minheap_print(MinHeap* heap){
    for(int i = 1; i <= heap->N; i++)
        printf("%d\n", heap->pq[i]);
}


//  TODO     testar tudo