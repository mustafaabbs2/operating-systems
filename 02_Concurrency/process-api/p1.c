#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  printf("hello world (pid:%d)\n", (int)getpid());
  fflush(stdout); //moves the output to the screen
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    // child (new process)
    //the child is a copy of the parent, but not an exact copy -- it has its own memory space
    //the child recieves a return code (rc) 0
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  }
  else{
    // parent goes down this path (main)
    //the parent recieves the return code of the child (rc)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid()); //
  }
  return 0;
  
}