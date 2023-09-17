// Use this file to write tests. We have started this process for you but
// there is much more than you can and should do. Writing simple tests
// and slowly making them more and more complicated as you develop
// your library is recommended.

// Compile this assignment with: gcc -g -Wall linked_hashmap_tests.c -o tests
//
// Run with: ./tests
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "linked_hashmap.h"

// write a comment of what you are testing in this function
int unitTest1(int status) {
    int passed = 0;
    // TODO: Implement a test
    return passed;
}

// TODO: Add more tests here at your discretion
int (*unitTests[])(int)={
    unitTest1,
    NULL
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main() {
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter]!=NULL){
	printf("========unitTest %d========\n", counter);
        if(1==unitTests[counter](1)){
		printf("passed test\n");
		testsPassed++;	
	}else{
		printf("failed test, missing functionality, or incorrect test\n");
	}
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}
