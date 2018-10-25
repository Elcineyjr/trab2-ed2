#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TADs/binPacking.h"

int array_max_size;
int* read_input_file(char* file_name);


int main(int argc, char* argv[]){

    //read the input file that contains all sizes from the problem
    int* sizes_array = read_input_file(argv[argc-1]);

    //normal worst fit heuristic
    worst_fit(sizes_array, array_max_size);

    //best fit
    best_fit(sizes_array, array_max_size);

    //sorts the array to do the decreasing heuristics
    qsort(sizes_array, array_max_size, sizeof(int), compare);

    //decreasing worst fit
    worst_fit(sizes_array, array_max_size);

    //decreasing best fit 
    best_fit(sizes_array, array_max_size);

    free(sizes_array);  //frees the array from the problem

    return 0;
}









/*
 *  Reads the input file and stores the data in a array
 */
int* read_input_file(char* file_name){
    FILE* input_file = fopen(file_name, "r");    //opens the given input file

    if(!input_file){    //if input file doesn't exist
        printf("No such file %s. Aborting!\n", file_name);
        exit(1);
    }
    
    fscanf(input_file, "%d", &array_max_size);   //reads the max number of files of the problem        
    
    int* sizes_array = malloc(array_max_size * sizeof(*sizes_array));    //mallocs the max size
    
    for(int i = 0; i < array_max_size; i++){ //reads all sizes of files of the problem 
        int file_size;
        fscanf(input_file, "%d", &file_size);
        sizes_array[i] = file_size;     //keep the sizes in a array to use in the diferent solutions
    }

    fclose(input_file);

    return sizes_array;
}