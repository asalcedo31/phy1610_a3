#include "initialization.h"
#include "time_step.h"
#include "time_0.h"
#include "deallocation.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/included/unit_test.hpp>

struct myFixture{
	int **number_of_ants;
	myFixture(){
		number_of_ants = init_number_of_ants(10);
		zero_array(10,number_of_ants); //initialize small test example array
		place_ants_t0(10,number_of_ants,5);
	}
	~myFixture(){
		deallocate_int_matrix(number_of_ants);
	//    deallocate_int_matrix(new_number_of_ants);
	  //  deallocate_float_matrix(crawl_direction);
	}
	
};
//BOOST_GLOBAL_FIXTURE(myFixture);
//BOOST_FIXTURE_TEST_SUITE(countAntsSuite, Fixture)

BOOST_FIXTURE_TEST_CASE(antCountsRight,myFixture)
{
	int ant_count = count_ants(10, number_of_ants);
	std::cout << ant_count << std::endl;
	BOOST_CHECK(count_ants(10, number_of_ants) ==5); //check that the total number of ants counted is positive
}

// BOOST_AUTO_TEST_CASE(moveAntsNotAdding)
// {
// 	int **number_of_ants = init_number_of_ants(10);
// 	int **new_number_of_ants = init_number_of_ants(10);
// 	float **crawl_direction = init_crawl_direction(table_size);
// 	zero_array(10,number_of_ants); //initialize small test example array
// 	place_ants_t0(10,number_of_ants,5);
// 	int ant_count = count_ants(10, number_of_ants);
// 	zero_array(10,new_number_of_ants); // zero new number of ants array
//     move_ants(10, crawl_direction, new_number_of_ants, number_of_ants); // move ants according to the crawl direction at that coordinate
// }

//BOOST_AUTO_TEST_SUITE_END( )