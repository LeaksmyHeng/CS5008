# Lab 3 -- Counting Assembly

This is the starting readme for this assignment.  Please edit the following information by removing the "*edit me*" and replace it with appropriate information your assignment. If it is asking you a question, please provide a response.

- Name: Leaksmy Heng

- Title: Student

- How many hours did it take you to complete this assignment? 15 Hours 

- Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.
  - No because the team member in lab does not say anything and it is also my fault not initializing the talk
  
- Did you use any external resources? (Cite them below)
  - Command line arguments, reading a file in stack overflow
  - https://overiq.com/c-programming-101/array-of-strings-in-c/
  
- Use your tool to measure the  number of instructions that are require to execute your implementation of the guessing game program that you implemented in homework 1 using two different levels of optimization:

  - When your program is compiled using the -O0 flag:

    ```
    Nothing show up when I compile it with -O0. 
    -bash-4.2$ gcc -O0 estimator.c -o estimator
    -bash-4.2$ ./estimator hw01-guessing-game.s
    ```

  - When your program is compiled using the -O3 flag:

    ```
    Nothing show up when I compile it using -O3
    -bash-4.2$ gcc -O3 estimator.c -o estimator
    -bash-4.2$ ./estimator hw01-guessing-game.s
    ```

- (Optional) What was your favorite part of the assignment? 
  - It was challenging but I enjoy how I was able to create an array and work with file
  
- (Optional) How would you improve the assignment? 
  - Explain in class about the fgets function or anything like that would be really helpful

## Logistics

For this assignment (and every assignment/lab), you must login into the servers through `your_khoury_name@login.khoury.neu.edu` to complete and test your work. The reason is the examples I will provide below are compiled strictly for our machines architecture, and this is a consistent architecture where your submission will be graded.

### Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

