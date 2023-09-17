// Type in and try example3.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	// Variable to store the process id
	pid_t pid;
	// Variable x allocated on the stack
	int x = 1;

	// fork returns a process id (we can distinguish processes by this value)
	// 0 is returned in the child process
	// >0 is the process id of the child received by the parent
	pid = fork();
	if (pid == 0){
		printf("Running child forever now pid=%d\n", getpid());
		while(1){} // run the child forever
	}
	else{
		// Run the parent
		printf("Terminating parent pid=%d\n", getpid());
		exit(0);
	}
	return 0;
}

