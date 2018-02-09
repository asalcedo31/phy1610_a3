#Makefile
#set up flags
CXX = g++
CXXFLAGS = -std=c++11
BOOST_LIB = -I /home/asalcedo/clibs/boost_1_66_0/
BOOST_FLAG = -g

unitTest: test_time_step
	./test_time_step
#link the time step test
test_time_step: test_time_step.o initialization.o time_0.o time_step.o
	${CXX} ${CXXFLAGS} ${BOOST_FLAG} ${BOOST_LIB}  test_time_step.o initialization.o time_step.o time_0.o -o test_time_step
#compile the time step unit test module
test_time_step.o: test_time_step.cc
	${CXX} ${CXXFLAGS} ${BOOST_FLAG} ${BOOST_LIB} -c test_time_step.cc

integratedTest: myAnts.out ants.out
	diff myAnts.out ants.out

#phony target make all	
all: myAnts

#run the modularized executable and put the output in a file
myAnts.out: myAnts
	./myAnts > myAnts.out

#run the ants baseline executable and put the output in a file
ants.out: ants
	./ants >ants.out
#compile the baseline executable
ants: 
	${CXX} ${CXXFLAGS} ants.cc -o ants

#compile final executable
myAnts: initialization.o time_0.o time_step.o deallocation.o myAnts.o
	${CXX} ${CXXFLAGS} initialization.o time_0.o time_step.o myAnts.o deallocation.o -o myAnts

#compile initialization module
initialization.o: initialization.cc
	${CXX} ${CXXFLAGS} initialization.cc -c -o initialization.o

#compile the module setting things up at the first time step 
time_0.o: time_0.cc
	${CXX} ${CXXFLAGS} time_0.cc -c -o time_0.o

#compile the module for a single time step after the first
time_step.o: time_step.cc
	${CXX} ${CXXFLAGS} time_step.cc -c -o time_step.o
#compile the module to deallocate arrays 
deallocation.o: deallocation.cc
	${CXX} ${CXXFLAGS} deallocation.cc -c -o deallocation.o

#compile module with main function 
myAnts.o: myAnts.cc initialization.h time_0.h time_step.h deallocation.h
	${CXX} ${CXXFLAGS} myAnts.cc -c -o myAnts.o

#remove all compiled files
clean:
	rm -f myAnts -f ants -f test_time_step -f integratedTest *.o *.out