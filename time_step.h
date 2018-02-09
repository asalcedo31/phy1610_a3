#ifndef TIME_STEP_H
#define TIME_STEP_H
//counts the ants currently on the table
int count_ants(int table_size, int **number_of_ants );
//moves each ant according to its crawl direction and updates it in new number of ants 
void move_ants(int table_size, float **crawl_direction, int **new_number_of_ants, int **number_of_ants);
//transfers values in new number of ants to the number of ants array 
void update_ant_arrays(int table_size, int **new_number_of_ants, int **number_of_ants);
#endif