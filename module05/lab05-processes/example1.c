// Type in and try example1.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	// Variable to store the process id
	pid_t pid;
	// Variable 'x' allocated on the stack
	int x = 1;
	// fork returns a process id (we can distinguish processes by this value)
	//  0 is returned in the child process
	//  >0 is the process id of the child received by the parent
	pid = fork();
	if (pid == 0){
		printf("child: x=%d\n", ++x);
		return 0;
	}

	// Parent process executing
	printf("parent: x=%d\n", --x); 
	return 0;
}
