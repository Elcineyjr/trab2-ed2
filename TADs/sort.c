#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define CUTOFF 10       //used to decrease the height of the recursive sorts


/*
 *  Insertion sort, linear if array is already sorted (good with small arrays)
 *  Decreasing sort version
 */
void insertion_sort(Item* a, int lo, int hi){
    for(int i  = lo; i < hi; i++)
        compexch(a[i+1], a[i]);     //places the smaller element in the last position to use it as a sentinel

    for(int i = hi-2; i >= lo; i--){
        int j = i;
        Item v = a[i];      //holds the elem to be compared
        while(less(v, a[j+1])){ //compares with every elem on its right
            a[j] = a[j+1];      //moves all the elements bigger than the compared to the left
            j++;
        }
        a[j] = v;   //places the element in the correct position
    }
}


/*
 * Quick sort 3-way from Dijkstra, with cutoff to insertion sort when array is small 
 * Decreasing sort version
 */
void quick_sort(Item* a, int lo, int hi){
    if(hi <= lo + CUTOFF - 1){
        insertion_sort(a, lo, hi);
        return;  
    } 

    Item v = a[lo];     //uses the elem as a pivot
    int lt = hi;
    int gt = lo;

    int i = lo;
    while(i <= lt){     

        //partition that keeps all the bigger elem to the left and the smaller ones to the right
        if(a[i] > v){   //if is bigger than v goes to the left
            exch(a[gt], a[i]);
            gt++;
            i++;
        }else if(a[i] < v){    //if is less than v goes to the right
            exch(a[i], a[lt]);
            lt--;
        }else{
            i++;
        }

    }

    quick_sort(a, lo, gt-1); //recursive sorting of the left array
    quick_sort(a, lt+1, hi); //recursive sorting of the right array
}