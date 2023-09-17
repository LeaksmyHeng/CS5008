// Impliment your cycle count tool here.
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define buf_size 1024

int countword(FILE* filePointer, char search_word[4]){
	int numberofword = 0;
	char number_of_char[buf_size];
	char* found_word;

	// alow us to read the line one by one
	// stre whatever they read in number_of_char, and the max size, and the filepointer
	while((fgets(number_of_char, buf_size, filePointer))!=NULL){
	       //printf("%d\n", numberofword);
	       //strstr is a string function allow use to search for word in a string
	       found_word = strstr(number_of_char, search_word);
	       if (found_word){
		       	numberofword++;
	       }
	}	
	return numberofword;
}

int sum_array(int array[], int n){
	int i, sum = 0;
	for (i=0; i<n; i++){
		sum = sum + array[i];
	}
	return sum;
}

int main(int argc, char* argv[]){
	char convert_tochar[4];
	int instruction_arr[9];
	int cycle_arr[9];
	int i, sum_cycle, sum_instruction, cycle, add, sub, mul, div, mov, lea, push, pop, ret;
	char array[9][4] = {"add", "sub", "mul", "div", "mov", "lea", "push", "pop", "ret"};
	int cycle_array[9] = {1, 1, 3, 24, 1, 3, 1, 1, 1};
	for (i = 0; i <9; i++){
		FILE* filePointer;
		filePointer = fopen(argv[1], "r");
       		if (filePointer == NULL){
                	printf("FilePointer couldn't");
		}
		strcpy(convert_tochar, array[i]);
		// calculate and append add and cycle to its array
		add = countword(filePointer, convert_tochar);
		instruction_arr[i] = add;
		cycle = add*cycle_array[i];
		cycle_arr[i] = cycle;
		
		if (add>0){
			printf("%s %d\n", convert_tochar, add);
		}
		//printf("%d\n", add);
		fclose(filePointer);
	}

	sum_instruction = sum_array(instruction_arr, 9);
	sum_cycle = sum_array(cycle_arr, 9);
	printf("Total instruction %d\n", sum_instruction);	
	printf("Total cycle %d\n", sum_cycle);
	return 1;
}
