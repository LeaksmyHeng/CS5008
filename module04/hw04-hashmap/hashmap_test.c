// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//
// Compile this assignment with: gcc -g -Wall hashmap_test.c -o hashmap_test
//
// Run with: ./hashmap_test
//
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include <string.h>
// Our library that we have written.
// Also, by a really smart engineer!
#include "my_hashmap.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample collection of tests for your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.


// Tests creation and deletion of the hashmap
// Ideally does not cause any segfaults, and this
// is considered passing.
int unitTest1(int status) {
    int passed = 0;
    hashmap_t* test = hashmap_create(12);    
    hashmap_delete(test);
    passed = 1;
    return passed;
}

// Tests has_key for a missing key
int unitTest2(int status) {
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    
    if(hashmap_hasKey(test, "cow")==0){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}


// Tests insert and has_key
int unitTest3(int status) {
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    
    if(hashmap_hasKey(test, "cow")==1) {
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}

// Tests insert and has_key and remove key
int unitTest4(int status) {
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    hashmap_removeKey(test, "cow");
    
    if(hashmap_hasKey(test, "cow")==0) {
      passed = 1;
    }
    
    hashmap_delete(test);

    return passed;
}

// Tests update_key
int unitTest5(int status) {
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    hashmap_update(test, "cow", "A common farm animal in Ohio.");
    
    if(hashmap_hasKey(test, "cow")==1) {
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}

// Test insert, has_key, getValue
int unitTest6(int status){
	int passed = 0;
	hashmap_t* test = hashmap_create(8);
    	hashmap_insert(test, "Mike", "15");
    	hashmap_insert(test, "Dan", "35");
   	hashmap_insert(test, "Sophana", "45");
    	hashmap_insert(test, "San", "35");

	if ((hashmap_hasKey(test, "Dan")==1) && (hashmap_hasKey(test, "Daniel")==0)){
        	char* value;
        	value = hashmap_getValue(test, "Dan");
        	if (strcmp(value, "35") == 0){
            		passed = 1;
		}
	}
	hashmap_delete(test);
	return passed;	
}

// Test insert, get_value, haskey, update, removekey
int unitTest7(int status){
	int passed = 0;
	hashmap_t* test = hashmap_create(8);
	hashmap_insert(test, "Table", "15");
	hashmap_insert(test, "Tenis", "35");
	hashmap_insert(test, "Water", "45");
	hashmap_insert(test, "Lamp", "10");
	hashmap_insert(test, "Pencil", "5");
	hashmap_insert(test, "Ruler", "5");
	hashmap_insert(test, "Labtop", "835");
    
	if ((hashmap_hasKey(test, "Dan")==0) && (hashmap_hasKey(test, "Table")==1)){
		char* value;
		char*  value_m;
		value = hashmap_getValue(test, "Table");
		value_m = hashmap_getValue(test, "Labtop");
		if (strcmp(value,"15")==0 && strcmp(value_m,"835")==0){
			hashmap_removeKey(test, "Water");
			if (hashmap_hasKey(test, "Water")!=1){
				hashmap_update(test, "Lamp", "newValue");
				char* newvalue;
                		value = hashmap_getValue(test, "Lamp");
                		if (strcmp(value, "newValue")==0){
                			passed = 1;
				}
            		}
            	}
	}
	hashmap_delete(test);
	return passed;
}

// TODO: Add more tests here at your discretion
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
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
