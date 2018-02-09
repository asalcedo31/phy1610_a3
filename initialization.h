#ifndef INITIALIZATION_H
#define INITIALIZATION_H
//assigns values to table size, time steps, and total ants
void initialize( int &table_size, int &time_steps, int &total_ants);
// sets up a, empty 2D array of table_size x table_size for the number of ants and crawl direction
int **init_number_of_ants(int table_size);
float **init_crawl_direction(int table_size);
#endif