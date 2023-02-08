//fork a process on unix system

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//two different  processes here run copies of the same program
int main()
{
    pid_t pid;

    pid = fork(); //returns different things depending which process it is (child or)

    if (pid<0)
    {
        printf("Fork failed\n");
    }
    else if (pid==0) //child
    {
        printf("Hello from child process\n");
        execlp("ls", "ls", "-l", NULL); //this new program is overlayed onto the PCB of the child process
    }
    else //parent
    {
        printf("Hello from parent process\n");
        wait(NULL); //will block here until all child processes are terminated

        //wait takes in a condition variable  

        //if process terminates and wait is not called by uits parent, it is a zombie process

        //if parent process terminates, the child process becomes an orphan process

        //you can also do wait(&status) to get the exit status of the child process
        printf("Child process has finished\n");
    }

return 0;
}