#include "initialization.h"
#include "time_step.h"
#include "time_0.h"
#include "deallocation.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/included/unit_test.hpp>

// set up the objects the test functions will need 
struct myFixture{
	//declare variables
	int **number_of_ants;
	int **new_number_of_ants;
	float **crawl_direction;
	int table_size;
	int total_ants;
	//set up 
	myFixture(){
		table_size = 10;
		total_ants = 5;
		number_of_ants = init_number_of_ants(table_size); //initialize small test example array
		zero_array(table_size,number_of_ants); //zero it out
		place_ants_t0(table_size,number_of_ants,total_ants);
		new_number_of_ants = init_number_of_ants(table_size); //initialize small test example new ants array
		zero_array(table_size,new_number_of_ants); //zero it
		crawl_direction = init_crawl_direction(table_size);
	} //clean up 
	~myFixture(){
		deallocate_int_matrix(number_of_ants);
	    deallocate_int_matrix(new_number_of_ants);
	    deallocate_float_matrix(crawl_direction);
	}
	
};
//BOOST_GLOBAL_FIXTURE(myFixture);
BOOST_FIXTURE_TEST_SUITE(countAntsSuite, myFixture)

BOOST_AUTO_TEST_CASE(antCountsRight) // check if the count of ants matches the total after initialization
{
	int ant_count = count_ants(table_size, number_of_ants);
	std::cout << ant_count << std::endl;
	BOOST_CHECK(count_ants(table_size, number_of_ants) == total_ants); //check that the total number of ants counted is positive
}

BOOST_AUTO_TEST_CASE(moveAntsNotAdding)
{
	move_ants(table_size, crawl_direction, new_number_of_ants, number_of_ants); // move ants according to the crawl direction at that coordinate
	int new_ant_count = count_ants(table_size, new_number_of_ants); // count the ants in the repositioned array
	BOOST_CHECK(new_ant_count <= total_ants); // check to make sure the new total is less than or equal to the total we started with
}

BOOST_AUTO_TEST_CASE(moveAntsNotMoving)
{
	move_ants(table_size, crawl_direction, new_number_of_ants, number_of_ants); // move ants according to the crawl direction at that coordinate
	bool diff = false; // assume the arrays are identical
	int i = 0;
    while (i<table_size && diff == false) {  //iterates through table coordinates until it finds a cell where the values are different
        for (int j=0;j<table_size;j++) {
        	if(new_number_of_ants[i][j] != number_of_ants[i][j]){ // check the value of a given position in the old and new array
        		diff = true; // check if different 
        	}
        }
        i++;
    }
	BOOST_CHECK(diff == true); // make sure the arrays have at least one value that's different 
}

BOOST_AUTO_TEST_SUITE_END( )