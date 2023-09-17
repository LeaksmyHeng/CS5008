// =================== Support Code =================
// Linked Hashmap 
//
// - Implement each of the functions to create a working linked hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other 
//   than functions that explicitly ask for printf output. 
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
// - You may add any helper functions that you think you need
//   (if any, or otherwise for debugging)
// ==================================================
#ifndef LINKED_HASHMAP_T
#define LINKED_HASHMAP_T

#include <stdlib.h>
#include <string.h>


// An entry consisting of a key-value pair.
// This is specifically for a (char*, char*) key-value pair
typedef struct pair {
    char* key;
    char* value
} pair_t;

// Each node holds a key and a value
typedef struct node {
    // TODO: Add data required for a node
} node_t;


// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Create a function prototype to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*, int); 

// Chained implementation of a hashmap
typedef struct hashmap {
    // TODO: add data required for a linked hash map

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
} hashmap_t;


// Creates a new hashmap
hashmap_t* hashmap_create(unsigned int _buckets) {
	// TODO: Implement me!!
    return NULL;
}

// Frees a hashmap
void hashmap_delete(hashmap_t* _hashmap) {
    // TODO: Implement me!!
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' for invalid hashmaps
int hashmap_hasKey(hashmap_t* _hashmap, char* key) {
	// TODO: Implement me!!
}

// Insert a new key/value pair into a hashmap
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value) {
    // TODO: IMplement me!!
}

// Return the first key-value pair in the ordering
//  - Returns NULL if there is no pair
pair_t* hashmap_getFirst(hashmap_t* _hashmap) {
    // TODO Implement me!!
}

// Return the last key-value pair in the ordering
//  - Returns NULL if there is no pair
pair_t* hashmap_getLast(hashmap_t* _hashmap) {
    // TODO Implement me!!
}

// Return a value from a key 
//  - Returns NULL if the key does not exist
char* hashmap_getValue(hashmap_t* _hashmap, char* key) {
	// TODO Implement me!!
}

// Remove a key from a hashmap
void hashmap_removeKey(hashmap_t* _hashmap, char* key) {
	// TODO: Implement me!!
}

// Update a key with a new Value
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue) {
	// TODO: Implement me!!
}

// Prints all of the keys in a hashmap in order
void hashmap_printKeys(hashmap_t* _hashmap){
	// TODO: Implement me!!
}

#endif
