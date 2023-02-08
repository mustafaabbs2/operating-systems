#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>


//The separation of fork() and exec() allows the shell to do a whole bunch of useful things rather easily
//after the fork() and before the exec() call, the shell can do things

// wc p3.c > newfile.txt
// when the child is created, before calling exec(), the shell closes standard output and opens the file newfile.txt.


//this is the program that would do this...
int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
	// child: redirect standard output to a file

    // #define	STDIN_FILENO	0	/* Standard input.  */
    // #define	STDOUT_FILENO	1	/* Standard output.  */
    // #define	STDERR_FILENO	2	/* Standard error output.  */
	close(STDOUT_FILENO); //close standard output
	open("p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); //write it into p4.output

	// now exec "wc"...
        char *myargs[3];
        myargs[0] = strdup("wc");   // program: "wc" (word count)
        myargs[1] = strdup("p4.c"); // argument: file to count
        myargs[2] = NULL;           // marks end of array
        execvp(myargs[0], myargs);  // runs word count
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
	assert(wc >= 0);
    }
    return 0;
}


// UNIX pipes are implemented in a similar way but with the pipe() system call. In this case, the output of one process is connected to an in-kernel pipe (i.e., queue), and the input of another process is connected to that same pipe; thus, the output of one process seamlessly is used as input to the next, and long and useful chains of commands can be strung together.


// Pipe is used to pass output to another program or utility.

// Redirect is used to pass output to either a file or stream.