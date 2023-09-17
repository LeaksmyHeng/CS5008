#include <stdio.h>
#include <stdlib.h>

/* Create the random_number function */
int guessing_random_number(){
int random_number, user_input;
int lower_threshold = 1, upper_threshold = 50, number_of_guess = 1;
random_number = (rand() % (upper_threshold - lower_threshold + 1)) + lower_threshold;                        
do {
	printf("Make a guess: ");
	scanf("%d", &user_input);
	if (user_input > random_number){
		printf("No guess lower!\n");
		number_of_guess++;
		}
 	else if (user_input < random_number){
 		printf("No guess higher!\n");
		number_of_guess++;
		}
	else if (user_input == random_number){
		printf("You got it!\n");
		break;
		}
} while (random_number != user_input);
return number_of_guess;}

int main()
{int number_of_game, number_of_guesses;
 int max_game = 5;
/* need to declare this function otherwise it will throw the warning: implicit declaration of function*/
int guessing_random_number();
int number_of_guess_array[5];
for(number_of_game = 0; number_of_game < max_game; number_of_game++){
	printf("==========================\nCPU Says: Pick a number 1-50\n==========================\n");
	number_of_guesses = guessing_random_number();
	number_of_guess_array[number_of_game] = number_of_guesses;
	}
printf("=================================================\n");
printf("|Here are the results of your guessing abilities|\n");
printf("=================================================\n");
for (number_of_game = 0; number_of_game < max_game; number_of_game++){
printf("Game %d took you %d\n", number_of_game, number_of_guess_array[number_of_game]);
}
return 0;
}
