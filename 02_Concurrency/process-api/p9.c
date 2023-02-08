#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

// Now write a program that uses wait() to wait for the child process to finish in the parent. 
// What does wait() return? What happens if you use wait() in the child?

// Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?
int main(int argc, char* argv[])
{
    int status;
    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        // wait(NULL); //This doesnt do anything in the child
        printf("child pid: %d \n", getpid());

    }

    else{
        waitpid(rc, &status, 0); //rc is the pid in the parent process
        printf("child pid (from parent): %d \n", rc);
        // pid_t waitpid(pid_t pid, int *statusPtr, int options);

        if (WIFSIGNALED(status)){
            printf("Error\n");
        }
        else if (WEXITSTATUS(status)){
            printf("Exited Normally\n");
        }

        printf("parent pid: %d \n", getpid());

    }
    
    return 0;

}