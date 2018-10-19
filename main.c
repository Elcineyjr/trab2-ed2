#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_input_file(char* file_name, int* array_max_size);


int main(int argc, char* argv[]){
    
    int* N;
    int* sizes_array = read_input_file(argv[argc-1], N);

    // printf("printando \n\n");
    // for(int i = 0; i < *N; i++)
    //     printf("%d \n", sizes_array[i]);    

    return 0;
}



/*
 *  Reads the input file and stores the data in a array
 */
int* read_input_file(char* file_name, int* array_max_size){
    FILE* input_file = fopen(file_name, "r");    //opens the given input file

    if(!input_file){    //if input file doesn't exist
        printf("No such file %s. Aborting!\n", file_name);
        exit(1);
    }

    int N;
    fscanf(input_file, "%d", &N);   //reads the max number of files of the problem
    *array_max_size = N;        //stores the max size to be used outside the funcion


    int* sizes_array = malloc(N * sizeof(*sizes_array));    //mallocs the max size

    for(int i = 0; i < N; i++){ //reads all sizes of files of the problem 
        int file_size;
        fscanf(input_file, "%d", &file_size);
        sizes_array[i] = file_size;     //keep the sizes in a array to use in the diferent solutions
    }

    fclose(input_file);

    return sizes_array;
}