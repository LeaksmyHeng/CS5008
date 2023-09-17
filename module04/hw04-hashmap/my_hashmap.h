// =================== Support Code =================
// Hashmap 
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other 
//   than functions that explicitly ask for printf output. 
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
// - You may add any helper functions that you think you need
//   (if any, or otherwise for debugging)
// ==================================================
#ifndef MY_HASHMAP_T
#define MY_HASHMAP_T

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// An entry consisting of a key-value pair.
// This is specifically for a (char*, char*) key-value pair
typedef struct pair {
    char* key;
    char* value;
} pair_t;

// Each node holds a key and a value
typedef struct node {
    pair_t* kv; // key/value pair
    struct node* next; // pointer to the next node and is stored the key value pair
} node_t;


// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// we define a new type and the type is int(*hashFunctionPOinter)(char*, int)
// This is called FunctionPointer definition
// Create a function prototype to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*, int); 

// Chained implementation of a hashmap
typedef struct hashmap {
    unsigned int buckets;   // i.e. size of the hashmap
    node_t** arrayOfLists;  // An array of linked lists for our buckets
                            // Read another way -- an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
} hashmap_t;

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
// The algorithm is:
//  - allocate memory for our hashmap
//  - set the number of buckets
//  - initialize our array of lists for each bucket
//  - setup our hash function to point to our stringHash function
//  - return new map that we have created
hashmap_t* hashmap_create(unsigned int _buckets) {
	// create a new hashmap called map and initialize it
	hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
	map->buckets = _buckets;
	node_t** arrayOfLists = (node_t**)malloc(sizeof(node_t*)*_buckets);
	map->arrayOfLists = arrayOfLists;
	
	int i = 0;
	for (i; i<_buckets; i++){
		map->arrayOfLists[i] = NULL;
	}
	// set up hashfunction to point to our stringhash function
	int (*hashFunction)(char*, int);
	hashFunction = &stringHash;
	map->hashFunction = hashFunction;
	// return new map that we have created
	return map;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap) {
	if (_hashmap == NULL){
		free(_hashmap);
	}
	else{
		int i = 0;
		for (i; i<_hashmap->buckets; i++){
			node_t* loop = _hashmap->arrayOfLists[i];
			if (loop != NULL) {
				free(loop->next);
			}
        	}
        free(_hashmap);
    	}
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key) {
	if (_hashmap == NULL){
		return -9999;
    	}
	
	unsigned int buckets = _hashmap->hashFunction(key, _hashmap->buckets);
	node_t* loop = _hashmap->arrayOfLists[buckets];
	while (loop != NULL){
		if (strcmp(loop->kv->key, key) == 0){
			return 1;
		}
        loop = loop->next;
    	}
	return 0;
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value) {
	int hashmaphaskey = 1;
	if (hashmaphaskey = hashmap_hasKey(_hashmap, key)){
		return;
    	}

	pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
	newpair->key = (char*)malloc(strlen(key)*sizeof(char)+1);
	newpair->value = (char*)malloc(strlen(value)*sizeof(char)+1);

	strcpy(newpair->key, key);
	strcpy(newpair->value, value);
	node_t* newnode = (node_t*)malloc(sizeof(node_t));
	newnode->next = NULL;
	newnode->kv = newpair;
	
	// figure out where the node could go in the hashmap like which bucket
	unsigned int buckets = _hashmap->hashFunction(key, _hashmap->buckets);
	node_t* loop = _hashmap->arrayOfLists[buckets];
    	if (loop != NULL) {
        	while (loop->next != NULL) {
            		loop = loop->next;
      		}
		loop->next = newnode;
    	}
	else {
		_hashmap->arrayOfLists[buckets] = newnode;
   	}
    	return;
	
}

// Return a value from a key 
// Returns NULL if the _hashmap is NULL
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key) {
	if (_hashmap == NULL){
		return NULL;
	}
	int hashmap_no_key = 0;
	if (hashmap_hasKey(_hashmap, key) == hashmap_no_key){
		return NULL;
	}
	else{
		unsigned int buckets = _hashmap->hashFunction(key, _hashmap->buckets);
		node_t* loop = _hashmap->arrayOfLists[buckets];
		while (loop != NULL){
			if (strcmp(loop->kv->key, key) == 0){
				return loop->kv->value;
			}
			loop = loop->next;
		}
	}
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key) {
	int key_not_exit = 0;
	if (hashmap_hasKey(_hashmap, key) == 0) {
      		return;
	}
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);
	node_t* loop = _hashmap->arrayOfLists[bucket];
	node_t* previous = NULL;
	while (loop != NULL) {
		if (strcmp(loop->kv->key, key) == 0) {
			if (previous == NULL) {
				_hashmap->arrayOfLists[bucket] = loop->next;
			}
			else{
				previous->next = loop->next;
			}
		free(loop);
		return;
		}
		previous = loop;
		loop = loop->next;
	}
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue) {
	int key_exist = 1;
	if (hashmap_hasKey(_hashmap, key) != key_exist){
		return;
	}
	else{
		unsigned int buckets = _hashmap->hashFunction(key, _hashmap->buckets);
		node_t* loop = _hashmap->arrayOfLists[buckets];
		node_t* previous = NULL;
		while (loop != NULL){
			if (strcmp(loop->kv->key, key) == 0){
				loop->kv->value = newValue;
			}
		loop = loop->next;
		}
	}
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
	int i = 0;
	for (i; i < _hashmap->buckets; i++) {
		node_t* loop = _hashmap->arrayOfLists[i];
		while (loop != NULL) {
			printf("%s\n", loop->kv->key);
			loop = loop->next;
		}
	} 
}

#endif
