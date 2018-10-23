// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "backup.h"


// struct backup{
//     Disk* disk_array; //array to keep all the disks of the backup
//     int max_size;
//     int N;
// };



// Backup* backup_create(int max_size){
//     Backup* new_backup = malloc(sizeof(*new_backup));

//     new_backup->max_size = max_size;

//     new_backup->disk_array = malloc(max_size * sizeof(Disk));   //the max amount of disk we will have is in the worst case the number of files

//     new_backup->N = 0;  //backup starts with 0 disks 

//     return new_backup;
// }


// //returns the number of disks the backup currently have
// int backup_number_of_disks(Backup* backup){
//     return backup->N;
// }


// //add a new disk to the backup
// void backup_add_new_disk(Backup* backup, Disk disk){
//     if(backup->N+1 <= backup->max_size)
//         backup->disk_array[++backup->N] = disk; //adds the disk in the last position of the array, and increments the current size of the array
// }


// //frees the allocated memory
// void backup_destroy(Backup* backup){
//     free(backup->disk_array);
//     free(backup);
// }
