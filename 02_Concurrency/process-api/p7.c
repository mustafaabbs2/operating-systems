#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

// Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
int main(int argc, char* argv[])
{

    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)

        printf("hello from child \n");

    }
    else{
        wait(NULL);

        //JK - I can't do this without calling wait() in the parent
        printf("goodbye from parent \n");

    }
    return 0;

}