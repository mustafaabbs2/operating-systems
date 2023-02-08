
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    fork();
    fork(); //each fork divides the process into two processes
    fork(); // 3 forks = 8 processes

//       L1       // There will be 1 child process 
//     /     \     // created by line 1.
//   L2      L2    // There will be 2 child processes
//  /  \    /  \   //  created by line 2
// L3  L3  L3  L3  // There will be 4 child processes 
//                 // created by line 3


// Here, global variable change in one process does not affect the other two processes 
// because data/state of two processes are different. 

//Note: return code for fork is 0 for child process and pid of child process for parent process.
    
    pid = getpid();
    printf("%d\n", pid);

    printf("Hello world!\n");
    return 0;
}