#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "disk.h"


struct disk{
    int space_left;
};


Disk disk_create(){
    Disk new_disk;

    new_disk.space_left = 1000000;

    return new_disk;
}


int disk_space_left(Disk disk){
    return disk.space_left;
}


void disk_add_new_file(Disk disk, int file_size){
    disk.space_left -= file_size;
}