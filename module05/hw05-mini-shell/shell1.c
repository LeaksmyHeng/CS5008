// Modify this file for your assignment
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 80

// Typedef is used to simplify the usage of a function pointer. Tis creates a type named command for a pointer to a function that takes a pointer args as an agrument
typedef void (*command)(char* args[]);
char commands[128][BUFFER_SIZE];
int size = 0;

// Help function so that users know what command they could us
void help(char* args[]){
    printf("Supported commands including:\n - regular commands found in bin bash like pwd,ls,echo... \n - history: which list what the historical command that the users has typed in \n - exit command or ctrl+c\n");
}

// In case of command not found
void commandnotfound(char* args[]){
    if (fork()==0){
        execvp(args[0], args);
        printf("Command not found. Did you mean something else?\n");
        exit(1);
    }
    else{
        wait(NULL);
    }
    return;
}

// SIGNAL HANDLER to handle exit the mini shell
void sigint_handler(int sig){
    char terminating_message[] = "Terminating through signal handler\n";
    int terminating_message_len = sizeof(terminating_message);
    wait(NULL);
    write(1, terminating_message, terminating_message_len);
    exit(0);
}


void exitshell(char* args[]){
    exit(1);
}

// chdir is a system function which is used to change the current working directory. Some systems, it is used as an alias for cd
void cd(char* args[]){
    if(args[1]==NULL){
        printf("Please provide an argument to your cd command\n");
    }
    if(chdir(args[1])!=0) printf("Please provide a valid directory\n");
}

// print historical command
void historical_command(char* args[]){
    printf("Historical command:\n");
    int command_loop = 0;
    for(command_loop; command_loop<size; command_loop++){
        printf("%d). %s", command_loop, commands[command_loop]);
    }
    command_loop = 0;
    return;
}

void string_tokens(char input[], char* args[]){
    // char* strtok(char* string, const char* limiter);
    // strtok will divide the string into tokens based on the dilimited character
    // we can expect a list of string from strtok() but the function returns a single string after calling strtok -> return 1st token
    char* split = strtok(input, " \t\n");
    int index = 0;
    while(split!=NULL){
        args[index++] = split;
        split = strtok(NULL, " \t\n");
    }
    args[index] = NULL;
    return;
}

void user_input_one(char* args[], char* commands_checker[], command functions[]){
    int index = 0;
    int match = 0;
    while(commands_checker[index]!=NULL){
        // check if the users input is the same as the build in function or not. If the same (which is when it's equal to 0)
        if(strcmp(args[0], commands_checker[index]) == 0){
            functions[index](args);
            match = 1;
            break;
        }
        index++;
        if(index>=4){
            break;
        }
    }
    if(match==0){
        commandnotfound(args);
    }
    index = 0;
    return;
}

int checkmatch(char* args[], char* commands_checker[], command functions[]){
    int index = 0;
    int match = 0;
    while(commands_checker[index]!=NULL){
        if(strcmp(args[0], commands_checker[index]) == 0){
            functions[index](args);
            match = 1;
            break;
        }
        index++;
        if(index>=4){
            break;
        }
    }
    index = 0;
    return match;
}

void user_input_two(char* args1[], char* args2[], char* commands_checker[], command functions[]){
    // pipe is used for passing information from one process to another.
    // pipe is unidirectional so for 2 way communication between proceses, two pipes can be set up
    // fd[0] for using read end
    // fd[1] for using write end
    int fd[2];  // used to store 2 ends of the pipe
    pid_t p1, p2;

    if (pipe(fd)<0){
        printf("Error pipe\n");
        return;
    }
    //fork the first command
    p1 = fork();
    if(p1<0){
        printf("Error fork\n");
        return;
    }
    // child process
    if(p1 == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        int first_command = checkmatch(args1, commands_checker, functions);
        if (first_command==0){
            if(execvp(args1[0], args1)<0){
                printf("Command not found. Did you mean something else?\n");
                exit(0);
            }
        }
        exit(0);
    }
    else{
        p2 = fork();
        if(p2<0){
            printf("Error fork\n");
            return;
        }
        close(fd[1]);
        if(p2==0){
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            int second_command = checkmatch(args2, commands_checker, functions);
            if(second_command == 0){
                if(execvp(args2[0], args2)<0){
                    printf("Command not found. Did you mean something else?\n");
                    exit(0);
                }
            }
            exit(0);
        }
        else{
            wait(NULL);
            wait(NULL);
        }
    }
    return;
}

int main(int argc, char** argv){
    // Please leave in this line as the first statement in your program. This will temrinate your shell after 120 seconds
    // and is usefull in the case that you accidently create a 'fork bomb'
    alarm(120);
    signal(SIGINT, sigint_handler);
    char inputs[BUFFER_SIZE];
    char* commands_checker[] = {"exit", "help", "cd", "history"};

    command function[4];
    function[0] = &exitshell;
    function[1] = &help;
    function[2] = &cd;
    function[3] = &historical_command;

    while(1){
        // Have a prompt "mini-shell>" in front of each command that is typed out
        printf("mini-shell> ");
        // fgets() reads text from standard input not from keyboard direclty. The value returned is the input str
        // read users input text  with buffersize of 80 so if there in put is more than 80 character, split it
        fgets(inputs, BUFFER_SIZE, stdin);
        char* string_split= strtok(inputs, "|");
        char first_comm[BUFFER_SIZE];
        char* args1[BUFFER_SIZE];
        char second_comm[BUFFER_SIZE];
        char* args2[BUFFER_SIZE];
        strcpy(first_comm, string_split);
        string_split = strtok(NULL, "|");
        int pipe = 0;
        if(string_split!=NULL){
            pipe = 1;
            strcpy(second_comm, string_split);
        }
        string_tokens(first_comm, args1);
        string_tokens(second_comm, args2);
        // copy user input so that it could print out when they use history command
        strcpy(commands[size++], inputs);
        size = size % 128;
        ///////process arguments
        if(pipe==0){
            user_input_one(args1, commands_checker, function);
        }
        else{
            size= size % 128;
            user_input_two(args1, args2, commands_checker, function);
        }
    }
    return 0;
}
