#include <iostream>
#include "initialization.h"
#include "time_0.h"
#include "time_step.h"
#include "deallocation.h"


int main()
{
    // ants walk on a table
    // declare variables
    int table_size = 0;
    int time_steps = 0;
    int total_ants = 0;
    int n = 0;
    initialize(table_size, time_steps,total_ants); // initialize table_size = 70, time_steps=100, total_ants=10000
    int **number_of_ants = init_number_of_ants(table_size); // itialize 2D arrays of size table_size for the number of ants, new number of ants, and crawl direction
    int **new_number_of_ants = init_number_of_ants(table_size);
    float **crawl_direction = init_crawl_direction(table_size);
    
       
    //set seed
    srand(13);
    
    // step 0 
    zero_array(table_size,number_of_ants);  //clear number of ants array
    place_ants_t0(table_size,number_of_ants,total_ants);  // initial random placement of ants on the table
    total_ants = count_ants(table_size, number_of_ants);  // count the total number of ants on the table

    // report
    std::cout << 0 << " " << total_ants << std::endl;
    // run time steps
    for (int t = 0; t < time_steps; t++) {
        // ants move 
        zero_array(table_size,new_number_of_ants); // zero new number of ants array
        move_ants(table_size, crawl_direction, new_number_of_ants, number_of_ants); // move ants according to the crawl direction at that coordinate
        update_ant_arrays(table_size, new_number_of_ants, number_of_ants); // update the number of ants array so the positioning is saved for the next time step
        // update
        total_ants = count_ants(table_size,number_of_ants);  // count the ants left on the table 
              
        // count ants
        // report
        std::cout << t+1 << " " << total_ants << std::endl;
    }
    //deallocating the matrices
    deallocate_int_matrix(number_of_ants);
    deallocate_int_matrix(new_number_of_ants);
    deallocate_float_matrix(crawl_direction);
    return 0;
}             
