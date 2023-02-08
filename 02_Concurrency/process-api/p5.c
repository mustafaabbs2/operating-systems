#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// Write a program that calls fork(). 
// Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100).
//  What value is the variable in the child process? 
// What happens to the variable when both the child and parent change the value of x?
int main(int argc, char* argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());

    int x = 100;
    printf("x: %d\n", x);
    fflush(stdout);
    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        x = 200;
        printf("x: %d\n", x); //print from child = this will change the value only in the child - since memory spaces are different
    }
    else { // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
        printf("x: %d\n", x);
    }

    return 0;

}