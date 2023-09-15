# Makefile for testing functions submitted with a main function
# It uses catch testing library
# Compile your program: make
# Run your program:  ./a.out
# Run tests: make run_tests
#

#Variables
CFLAGS = -Wall -std=c++11
CC = g++
	
########################### DO NOT MODIFY THIS RULE ############################
#                           make and run the tests                             #
run_tests: _TEST/TEST_cases.cc
	head myset.h
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc -o _TEST/run_tests && ./_TEST/run_tests -sr compact

################################################################################


clean:
	rm -rf a.out *.o _TEST/NO_MAIN.cc _TEST/run_tests
