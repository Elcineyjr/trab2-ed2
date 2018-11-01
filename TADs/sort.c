#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"


void insertion_sort(Item* a, int lo, int hi){
    for(int i  = hi; i > lo; i--)
        compexch(a[i-1], a[i]);     //places the smaller element in the first position to use it as a sentinel

    for(int i = 0; i <= lo+2; i++){
        int j = i;
        Item v = a[i];      //holds the elem to be compared
        while(less(v, a[j-1])){ //compares with every elem on its left
            a[j] = a[j-1];      //moves all the elements bigger than the compared to the right
            j--;
        }
        a[j] = v;   //places the element in the correct position
    }    
}

#define CUTOFF 7
void quick_sort(Item* a, int lo, int hi){
    if(hi <= lo + CUTOFF - 1){
        insertion_sort(a, lo, hi);
        return;  
    } 

    int v = a[lo];                      //TODO comentar esse codigo
    int lt = lo;                        //TA ERRADO TA ORDENANDO AO CONTRARIO
    int gt = hi;
    int i = lo;

    while(i <= gt){

        if(a[i] < v){
            exch(a[lt], a[i]);
            lt++;
            i++;
        } else if(a[i] > v){
            exch(a[i], a[gt]);
            gt--;
        }else{
            i++;
        }

    }

    quick_sort(a, lo, lt-1);
    quick_sort(a, gt+1, hi);
}