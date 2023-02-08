#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

// Write a program that creates two children, 
// and connects the standard output of one to the standard input of the other, using the pipe() system call.

int main(int argc, char* argv[])
{

    int fd[2];
    // int pipe(int pipefd[2]); --> syntax: success --> 0, fail --> -1
    //the first element of the array is the read end of the pipe
    //the second element of the array is the write end of the pipe

    if(pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
  printf("Read File Descriptor Value: %d\n", fd[0]);
  printf("Write File Descriptor Value: %d\n", fd[1]);
 
  return EXIT_SUCCESS;
}
