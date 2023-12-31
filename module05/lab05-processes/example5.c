// Type in and try example5.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	char* myargv[16];
	// among the contents of /bin are the shells (eg bash or csh), ls, grep, tar, kill, echo, ps, cp, mv, rm, cat, gzip, ping, vim text editor and the like => from linfo.org/bin.html
	//myargv[0] = "/bin/ls";
	myargv[0] = "/bin/cat ";
	myargv[1] = "example2.c";

	myargv[2] = NULL;

	if (fork() ==  0){
		execve(myargv[0], myargv, NULL);
		printf("Child: Should never get here\n");
		exit(1);
	}
	else{
		wait(NULL);
		printf("This always prints last\n");
	}
	return 0;
}
