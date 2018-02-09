#include <cmath>
#include<cstdlib>
#include <iostream>
void zero_array(int table_size, int **number_of_ants){
    for (int i=0;i<table_size;i++) { // iterates through each i and j coordinate
        for (int j=0;j<table_size;j++) {
            number_of_ants[i][j] = 0.0; // assigns a float of zero at each coordinate
        }
    }
}
void place_ants_t0(int table_size, int **number_of_ants, int total_ants){
    int n =0;
    srand(13);
    while (n < total_ants) {
        int i = rand() % table_size;  //randomly positions the ants on i table coordinates
        int j = rand() % table_size;  // randomly positions ants on the j table coordinates
        number_of_ants[i][j] ++;
        n ++;
    }
}
