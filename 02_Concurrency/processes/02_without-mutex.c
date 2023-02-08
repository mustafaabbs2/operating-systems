// Suppose there is a main thread A, whose job is to calculate the sum of the variables w and y where w=x+1, and y=z+2. 
// The values of the variables x and z are to be fetched by the user. 
// In this scenario, we can create two threads, B and C. 
// The job of thread B will be to take the value of the variable x from the user, increment it by 1, and save it in the variable w.
//  The job of thread C will be to take the value of the variable z from the user, increment it by 2, and then save it in variable y. 
//  Finally, both of these threads will handover these results to the main thread A, which will then calculate their sum and display the final result.




// Mutex stands for mutual exclusion, 
// and it basically provides us with a locking mechanism that prevents the access and modification of the critical data
//  by more than one user at a time.


// gcc 01_mutex.c -lpthread -o 01_mutex
// use lpthread to compile multithreaded programs 


//The following program demonstrates what happens when you do not use mutexes
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t tid[2];
int counter;
  
void* trythis(void* arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("\n Job %d has finished\n", counter); //using counter is wrong without a mutex, both threads will use updated counter value
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
  
    return 0;

}

// Result
// Job 1 has started

//  Job 2 has started

//  Job 2 has finished

//  Job 2 has finished