#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

// Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. 
// See if you can try all of the variants of exec(), including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). 
// Why do you think there are so many variants of the same basic call?
int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        char *myargs[2];
        myargs[0] = strdup("ls");   // program: "ls" (list files)
        myargs[1] = NULL;           // marks end of array
        execvp(myargs[0], myargs);  // runs ls

        // https://linux.die.net/man/3/exec -- find differences between the different exec functions
    }

    return 0;

}
