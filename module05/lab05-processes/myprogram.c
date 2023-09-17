// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int child_status;
    int firstchild = fork();
    int secondchild = fork();
    
    char* myargv[16];
    myargv[0] = "/bin/date";
    myargv[1] = "-I";
    myargv[2] = NULL;

    char* myargv1[16];
    myargv1[0] = "/bin/pwd";
    myargv1[1] = NULL;
    myargv1[2] = NULL;

    char* myargv2[16];
    myargv2[0] = "/bin/df";
    myargv2[1] = "example1.c";
    myargv2[2] = NULL;

    if(firstchild == 0 && secondchild>0){
        printf("Second Child is running and will execute df example1.c command!\n");
	execve(myargv2[0], myargv2, NULL);
        exit(0);
    }
    else if (firstchild >0 && secondchild==0){
        printf("First child is running and will execute pwd command\n");
	execve(myargv1[0], myargv1, NULL);
        exit(0);
    }
    else if (firstchild >0 && secondchild>0){
        printf("Parent is running and will execute date command\n");
	execve(myargv[0], myargv, NULL);
        if ((waitpid(firstchild, &child_status, 0) > 0) || (waitpid(secondchild, &child_status,0)>0)) {
            if (WIFEXITED(child_status) && !WEXITSTATUS(child_status)) 
              printf("program execution successful\n");
            else if (WIFEXITED(child_status) && WEXITSTATUS(child_status)) {
                if (WEXITSTATUS(child_status) == 127) {
                    printf("Execve execution failed\n");
                }
                else 
                    printf("Program terminated!\n");                
            }
            else 
               printf("Program is forced to terminate!\n");            
        } 
        else {
           printf("Fail to execute waitpid\n");
        }
      exit(0);
   }
   return 0;
}
