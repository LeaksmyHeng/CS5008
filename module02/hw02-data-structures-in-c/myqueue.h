// =================== Support Code =================
// Queue
//
//
//
// - Implement each of the functions to create a working circular queue.
// - Do not change any of the function declarations
//   - (i.e. queue_t* create_queue(unsigned int _capacity) should not have additional arguments)
// - You should not have any 'printf' statements in your queue functions. 
//   - (You may consider using these printf statements to debug, 
//     but they should be removed from your final version)
// ==================================================
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h>
#include <stdio.h>

// The main data structure for the queue
struct queue{
	unsigned int back;	    // The next free position in the queue
				    		// (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
				    		// (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we currently have enqueued.
	unsigned int capacity;  // Maximum number of items the queue can hold
	int* data; 		    	// The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity){
	// TODO: Implement me!
	queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
	if (myQueue == NULL){
		return NULL;
	}
	//Allocate memory for queue and initialize it
	myQueue->back = -1;
	myQueue->front = 0;
	myQueue->size = 0;
	myQueue->capacity = _capacity;
	myQueue->data = (int*)malloc(sizeof(int)*_capacity);

	return myQueue;
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
int queue_empty(queue_t* q){
	// TODO: Implement me!
	if (q == NULL){
		return 1;
	}
	if (q->size == 0){
		return 1;
	}
	return 0;
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
int queue_full(queue_t* q){
	// TODO: Implement me!
	if (q->size == q->capacity){
		return 1;
	}
	return 0;
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t* q, int item){
	// TODO: Implement me!
	if (queue_full(q)){
		printf("queue full\n");
		return -1;
	}
	else {	
		q->size = q->size+1;
		q->back = q->back+1;
		if (q->back == q->capacity){
			q->back = 0;
		};
		q->data[q->back] = item;
		return 0;
	}
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should crash the program, call exit(1)
int queue_dequeue(queue_t *q){
	// TODO: Implement me!
	if (q == NULL){
		printf("Empty q");
		exit(1);
	};
	if (q->size == 0){
		printf("Empty q with size 0");
		exit(1);
	}
	else {
		q->size--;
		q->front++;
		if (q->front==q->capacity){
			q->front=0;
		}
	};
	return 1; // Note: This line is a filler so the code compiles.
}


// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL queue cannot return the size, call exit(1))
unsigned int queue_size(queue_t* q){
	// TODO: Implement me!
	if (q == NULL){
		exit(1);
	};
	printf("Queue size is %d\n", q->size);	
	return q->size;
}


// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
	// TODO: Implement me!
	if (q == NULL){
		return;
	}
	if (q->data != NULL){
		free(q->data);
	};
	free(q);
}

#endif
