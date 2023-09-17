// Compile this assignment with: gcc -g -Wall main.c -o main
// Use this file to implement testing for your
// doubly linked list implementation
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include <malloc.h>

// Our library that we have written.
// Also, by a really smart engineer!

// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

#include "my_dll.h"

// ====================================================
// ================== Program Entry ===================
// ====================================================
// test push front and push back. If we receive the correct number of size and correct location then pass
void create_dll_test(dll_t* test){
        dll_push_front(test, 1);
        dll_push_front(test, 2);
        dll_push_front(test, 3);
        dll_push_front(test, 4);
        dll_push_back(test, 5);
        dll_push_back(test, 6);
        dll_push_back(test, 7);
        dll_push_back(test, 8);
}


int unitTest1(int status){
	int passed = 0;
	dll_t* test = create_dll();
	create_dll_test(test);
	if (8==dll_size(test)){
       		if ((4==dll_get(test, 0)) && (8==dll_get(test, 7))){
			passed = 1;
      	 	}
   	}
  	else{
		passed = 0;
   	}
	free_dll(test);
	return passed;	
}


// test delete front and delete back by geting the first and last stack then compare the size
int unitTest2(int status){
	int passed = 0;
	dll_t* test = create_dll();
	create_dll_test(test);
	dll_pop_front(test);
	dll_pop_back(test);
	if (6==dll_size(test)){
		if ((3==dll_get(test, 0)) && (7==dll_get(test,5))){
			passed = 1;
		}
	}
	else{
		passed = 0;
	}
	free_dll(test);
	return passed;
}

// test insert to certain position. Validate by check the size and dll_get
int unitTest3(int status){
	int passed = 0;
	dll_t* test = create_dll();
	create_dll_test(test);
	dll_insert(test, 1, 25);
	dll_insert(test, 1, 26);
	if ((10==dll_size(test)) && (26==dll_get(test,1))){
		passed = 1;
	} 
	else{
		passed = 0;
	}
	free_dll(test);
	return passed;
}

// test removed node at certain location and compare it with the dll_get
int unitTest4(int status){
	int passed = 0;
	dll_t* test = create_dll();
	create_dll_test(test);
	dll_remove(test, 2);
	dll_remove(test, 0);
	dll_remove(test, 5);
	if ((5==dll_size(test)) && (1==dll_get(test,1))){
		passed = 1;
	}
	else{
		passed = 0;
	}
	free_dll(test);
	return passed;
}

// test push front, push back, pop back and pop front by comparing the size and dll_get 
int unitTest5(int status){
	int passed = 0;
	dll_t* test = create_dll();
	create_dll_test(test);
	dll_push_front(test, 50);
	dll_push_back(test, 51);
	if ((10==dll_size(test)) && (50==dll_get(test,0)) && (51==dll_get(test,9))){
		int deleted_back, deleted_front;
		deleted_back = dll_pop_back(test);
		deleted_front = dll_pop_front(test);
		if ((deleted_back==51) && (deleted_front==50) && (8==dll_size(test))){
			passed = 1;
		}
	}
	else{
		passed = 0;
	}
	free_dll(test);
	return passed;
}

int unitTest6(int status){
	int passed = 0;
	dll_t* test = create_dll();
	create_dll_test(test);
	dll_pop_back(test);
	dll_pop_front(test);
	dll_remove(test, 4);
	dll_remove(test,1);
	if (3==dll_get(test,0)){
		dll_remove(test,0);
		dll_remove(test,1);
		dll_remove(test,1);
		if (1==dll_get(test,0)){
			dll_remove(test,0);
			if (1==dll_empty(test)){
				passed = 1;
			}
		}
	}
	else{
		passed = 0;
	}
	free_dll(test);
	return passed;
}


int (*unitTests[])(int)={
   unitTest1,
   unitTest2,
   unitTest3,
   unitTest4,
   unitTest5,
   unitTest6,
};

int main(){
	unsigned int testsPassed = 0;
    	// List of Unit Tests to test your data structure
	int counter =0;
	while(unitTests[counter]!=NULL){
		printf("========unitTest %d========\n",counter);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
             		testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
		counter++;
	}
	printf("%d of %d tests passed\n",testsPassed,counter);
	return 0;
}
