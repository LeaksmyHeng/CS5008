// Use this file to write tests. We have started this process for you but
// there is much more than you can and should do. Writing simple tests
// and slowly making them more and more complicated as you develop
// your library is recommended.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_hashmap.h"

int unitTest1(){
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5); 
    // Insert a first key/value pair
    hashmap_insert(myHashmap,"pig", "a farm animal");
    // Does hashmap contain key?
    printf("pig was added should be 1: %d\n", hashmap_hasKey(myHashmap, "pig"));
    // Print out the keys
    hashmap_printKeys(myHashmap);
    // Retrieve pig's value 
    printf("pig's value is %s\n", hashmap_getValue(myHashmap, "pig"));
    hashmap_update(myHashmap,"pig","a really cool farm animal");    
    printf("pig's value is updated to: %s\n", hashmap_getValue(myHashmap, "pig"));
    // Remove a key
    hashmap_removeKey(myHashmap,"pig");
    // Does hashmap contain key?
    printf("pig was removed should be 0: %d\n", hashmap_hasKey(myHashmap, "pig"));
    // Finally terminate our hashmap
    hashmap_delete(myHashmap);
}

int unitTest2(){
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5); 
    // Insert a first key/value pair
    hashmap_insert(myHashmap,"pig", "a farm animal");
    hashmap_insert(myHashmap,"bat", "a farm creature");
    hashmap_insert(myHashmap,"cat", "a funny farm animal");
    hashmap_insert(myHashmap,"dog", "a fun farm animal");
    hashmap_insert(myHashmap,"bear", "a wild farm animal");
    hashmap_insert(myHashmap,"ox", "another farm animal");
    hashmap_insert(myHashmap,"cow", "a favorite farm animal");
    hashmap_insert(myHashmap,"hippo", "a farm animal?");
    hashmap_insert(myHashmap,"elephant", "not a farm animal");
    hashmap_insert(myHashmap,"human", "an animal that farms");
    // Print the keys
    hashmap_printKeys(myHashmap);
    // Finally terminate our hashmap
    hashmap_delete(myHashmap);

}

int unitTest3(){
    hashmap_t* test = hashmap_create(8);
    hashmap_insert(test, "Love", "15");
    hashmap_insert(test, "Hate", "35");
    hashmap_insert(test, "Friend", "45");
    hashmap_insert(test, "Enemies", "10");
    hashmap_insert(test, "White", "5");
    hashmap_insert(test, "Black", "5");
    
    printf("Starting to print original hash\n");
    hashmap_printKeys(test);
    printf("Ending the printing of the original array\n");
    
    char key_check[5] = "Pink";
    if ((hashmap_hasKey(test, key_check)==0)){
        printf("\nCannot find key: %s therefore we will insert it with value of: ValueforPink\n", key_check);
        hashmap_insert(test, key_check, "ValueforPink");
        char* pinkvalue;
        pinkvalue = hashmap_getValue(test, key_check);
        if (strcmp(pinkvalue, "ValueforPink")==0){
            printf("Get value of key: %s, value: %s\n", key_check, pinkvalue);
        }
        
        printf("\nI will start removing some keys\nList of keys available\n");

        hashmap_removeKey(test, "Love");
        hashmap_removeKey(test, "Hate");
        hashmap_removeKey(test, "White");
        hashmap_removeKey(test, "Black");
        hashmap_printKeys(test);
        
	printf("\nUpdate the value of the key\n");
        hashmap_update(test, "Friend", "UpdatedFriendHere");
        hashmap_update(test, "Enemies", "UpdatedEnemiesHere");
        char* friendvalue;
        char* enemiesvalue;
        friendvalue = hashmap_getValue(test, "Friend");
        enemiesvalue = hashmap_getValue(test, "Enemies");
        printf("Friend value is:%s\n", friendvalue);
        printf("Enemies value is:%s\n", enemiesvalue);
    }
    
    hashmap_delete(test);
    return 0;
}

int unitTest4(){
    hashmap_t* test = hashmap_create(2);
    hashmap_insert(test, "Love", "15");
    hashmap_insert(test, "Hate", "35");

    printf("Starting to print original hash\n");
    hashmap_printKeys(test);
    printf("Ending the printing of the original array\n\nDelete hashtable\n");
    hashmap_delete(test);
    return 0;
}


int main(){

    printf("============ unitTest1() ================\n");
    unitTest1();
    printf("============ unitTest2() ================\n");
    unitTest2();
    printf("============ unitTest3() ================\n");
    unitTest3(); 
    printf("============ unitTest4() ================\n");
    unitTest4();
    return 0;
}
