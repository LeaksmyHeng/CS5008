// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node {
	int data;
	struct node* next;
	struct node* previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count; 
	node_t* head; 
	node_t* tail; 
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll() {
	dll_t* dll = (dll_t*) malloc(sizeof(dll_t));
	dll->count = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return dll;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l) {
	if (l == NULL){
		return -1;
	}
	if (l->count == 0){
		return 1;
	}
	else{
		return 0;
	}
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item) {
	if (l == NULL){
		return -1;
	}
	// initialize the new node to push it to the front
	node_t* node_to_insert = (node_t*)malloc(sizeof(node_t));
	node_to_insert->data = item;
	node_to_insert->next = NULL;
	node_to_insert->previous = NULL;
	// if there is no node, initialize the new node as head
	if(l->count == 0){
		l->head = node_to_insert;
		l->tail = node_to_insert;
		l->count++;
		return 1;
	}
	// if there is already data in there, put it to the front and push the previous node
	else{
		node_to_insert->next = l->head;
		l->head->previous = node_to_insert;
		l->head = node_to_insert;
		l->count++;
		return 1;
	}
	return 0;
}


// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item) {
	if (l == NULL){
		return -1;
	}
	// initialize node to push back
	node_t* node_to_insert = (node_t*)malloc(sizeof(node_t));
	node_to_insert->data = item;
	node_to_insert->next = NULL;
	node_to_insert->previous = NULL;
	// if there is no node, we will only have 1 node 
	if(l->count == 0) {
		l->tail = node_to_insert;
		l->head = node_to_insert;
		l->count++;
	return 1;
	}
	// if there is already a data, push it to the tail by pointing l->tail to it
	else {
		node_to_insert->previous = l->tail;
		l->tail->next = node_to_insert;
		l->tail = node_to_insert;
		l->count++;
		return 1;
	}
	return 0;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL. 
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* t) {
	if (t == NULL){
		return -1;
	}
	// if there is nothing in the node then can't pop it so return 0
	if(t->count == 0){
		return 0;
	}; 
	// initialize the deleted item by having it poiting to the head of the node
	int deleted_item = t->head->data;
	if(t->count == 1){
		free(t->head);
		t->head = NULL;
		t->tail = NULL;
		t->count--;
	}else{
		node_t* init_node = t->head;
		init_node->next->previous = NULL;
		t->head = init_node->next;
		free(init_node);
		t->count--;
	}
	return deleted_item;
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL. 
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* t){
	if(t == NULL){
		return -1;
	}
	if(t->count == 0){
		return 0;
	}
	// initialize the deleted item by having it pointing to the tail as we have to return it at the end
	int deleted_item = t->tail->data;
	if(t->count == 1) {
		free(t->tail);
		t->head = NULL;
		t->tail = NULL;
	}else{
		node_t* init_node = t->tail;
		init_node->previous->next = NULL;
		t->tail = init_node->previous;
		free(init_node);
	}
	t->count--;
	return deleted_item;
}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t* l, int pos, int item){
	if (l == NULL){
		return -1;
	}
	if(l->count<= pos < 0){
		return 0;
	};
	if(pos == 0){
		return dll_push_front(l, item);
	};
	// if possition is positive interger greater than 0 and less than the size (we initize at 0) so need to be size-1
	// initize the node pointer and allocate its memory
	if (0<pos<l->count-1){
		node_t* inserted_node = (node_t*)malloc(sizeof(node_t));
		if(inserted_node == NULL){
			return 0;
		};
		inserted_node->data = item;
		inserted_node->next = NULL;
		inserted_node->previous = NULL;
	
		int loop = 0;
		node_t* temp = l->head;
		// loop to get to the possition of the insert
		while(loop != pos) {
			temp = temp->next;
			loop++;
		}
		inserted_node->next = temp;
		inserted_node->previous = temp->previous;
		temp->previous->next = inserted_node;
		temp->previous = inserted_node;
		l->count++;
		return 1;
	}
	return 0;
}

//  Returns the item at position pos starting at 0 ( 0 being the first item )
//  Returns -1 if the list is NULL
//  (does not remove the item)
//  Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t* l, int pos){
	if (l==NULL){
		return -1;
	};
	if (l->count<=pos<0 || l->count==0){
		return -1;
	}; 
   	int loop = 0;
   	node_t* temp = l->head;
   	while(loop != pos) {
      		temp = temp -> next;
       		loop++;
   	}
	return temp->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
// * we tried to remove at a negative location.
// * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_remove(dll_t* l, int pos){
	if (l == NULL ||  l->count == 0 || l->count<=pos < 0){
		return -1;
		}
	if(pos == 0){
		return dll_pop_front(l);
	};
	if(pos == l->count-1){
		return dll_pop_back(l);
	};
	if(0<pos<l->count-1){
		int loop = 0;
		node_t* temp = l->head;
		// loop to get to the position
		while(loop != pos) {
			temp = temp->next;
			loop++;
		}
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		free(temp);
		l->count--;
	}
	return 0;
}


// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t* t){
	if (t == NULL){
		return -1;
	}
	else {
		return t->count;
	}
	return -1;
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
	if (t == NULL){
		return;
	}
	if(t->count == 0){
		free(t);
	}else{
		node_t* node = t->head;
		while(node->next != NULL) {
		node_t* temp = node;
		node = node->next;
		free(temp);
	}
	free(node);
	free(t);
	}
}

#endif
