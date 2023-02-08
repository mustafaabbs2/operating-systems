#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

// Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?
int main(int argc, char* argv[])
{
    int fdp, fdc;
    // char* buffer = malloc(100*sizeof(char)); //incase we need to write to the file with a buffer
    char *buffer = "hello mustafa";

    close(STDOUT_FILENO); //close standard output
    fdp = open("p6.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); 
    write(fdp, buffer, strlen(buffer)); //write to the file ;

    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        // fdc = open("p6.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); //note - open is a low level system call 
        // write(fdc, "hello world from child \n", 30);
        //if you try to open the same file twice, the file is corrupt... 
        

    }

    // free(buffer);

    return 0;

}