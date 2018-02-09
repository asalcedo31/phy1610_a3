#include <cmath>
const double pi = 3.14159265358979323846264338327950288;  //define pi
void initialize( int &table_size, int &time_steps, int &total_ants){    //accept pointers to the table_size, time_steps, and total_ants values and assigns them values 
    table_size = 70;
    time_steps = 100;
    total_ants = 10000;
    }

int **init_number_of_ants(int table_size){  
    int **a = new int *[table_size];   //dynamically allocate the array of table size for rows
    a[0] = new int[table_size*table_size]; // dynamically allocate the arrays for columns of size table_size contiguously in memory at each row pointer
    for (int i = 1; i < table_size; i++){  
        a[i] = &a[0][i*table_size];
    }

    return a;
}

float **init_crawl_direction(int table_size){
    float **a = new float *[table_size];   //dynamically allocate the array of table size for rows
    a[0] = new float [table_size*table_size];  // dynamically allocate the arrays for columns of size table_size contiguously in memory at each row pointer
    for (int i = 1; i < table_size; i++){
        a[i] = &a[0][i*table_size];
    }

    for (int i=0;i<table_size;i++) {  // initialize a crawl direction for each value in the array. 
        for (int j=0;j<table_size;j++) {
            a[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    return a;
}