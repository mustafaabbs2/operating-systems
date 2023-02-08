#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  

//gcc 03_mutex.c -lpthread -o 03_mutex
pthread_t tid[2]; //array of type pthread_t (like size_t)
int counter;
pthread_mutex_t lock;
  
void* trythis(void* arg)
{
    pthread_mutex_lock(&lock); //the thread that reaches here first locks and owns the mutex
  
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
  
    printf("\n Job %d has finished\n", counter);
  
    pthread_mutex_unlock(&lock); //that thread releases the mutex
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    } //initialize the mutex variable
  
    while (i < 2) {
        error = pthread_create(&(tid[i]),
                               NULL,
                               &trythis, NULL);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock); //destroy the mutex variable
  
    return 0;
}

// Job 1 started
// Job 1 finished
// Job 2 started
// Job 2 finished