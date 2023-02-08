#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    fflush(stdout);
    int rc = fork();
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    else { // parent goes down this path (main)
        int rc_wait = wait(NULL); //return code of child
        //this means that the parent will wait for the child to finish before continuing
        //..this makes the code deterministic  
        //if the parent happens to run first, it will wait for the child 
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
    }
    return 0;
}