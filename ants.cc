#include <cmath>
#include <iostream>

const double pi = 3.14159265358979323846264338327950288;

int main()
{
    // ants walk on a table
    int table_size = 70;
    int time_steps = 100;
    int number_of_ants[table_size][table_size];
    int new_number_of_ants[table_size][table_size];
    float crawl_direction[table_size][table_size];
    int total_ants = 10000; // initial number of ants
    // initialize a direction field; where do the ants go at each point?
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            crawl_direction[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    // "randomly" place ants on the table
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            number_of_ants[i][j] = 0.0;
        }
    }
    int n = 0;
    srand(13);
    while (n < total_ants) {
        int i = rand() % table_size;
        int j = rand() % table_size;
        number_of_ants[i][j] ++;
        n ++;
    }
    // count ants
    total_ants = 0.0;
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            total_ants += number_of_ants[i][j];
        }
    }
    // report
    std::cout << 0 << " " << total_ants << std::endl;
    // run time steps
    for (int t = 0; t < time_steps; t++) {
        // ants move 
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                new_number_of_ants[i][j] = 0.0;
            }
        }
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                int di = 1.9*sin(crawl_direction[i][j]);
                int dj = 1.9*cos(crawl_direction[i][j]);
                int i2 = i + di;
                int j2 = j + dj;
                // put onlu new table if not off table
                if (i2>=0 and i2<table_size and j2>=0 and j2<table_size) {
                    new_number_of_ants[i2][j2] += number_of_ants[i][j];
                } 
            }
        }
        // update
        total_ants = 0.0;
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                number_of_ants[i][j] = new_number_of_ants[i][j];
            }
        }        
        // count ants
        for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                total_ants += number_of_ants[i][j];
            }
        }
        // report
        std::cout << t+1 << " " << total_ants << std::endl;
    }
    return 0;
}             
