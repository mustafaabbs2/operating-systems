#include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #define NUM_THREADS     4
//  gcc 01_pthread.c -lpthread -o 01_pthread
 void *PrintHello(void *threadid)
 {
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for(t=0; t<NUM_THREADS; t++){
       printf("In main: creating thread %ld\n", t);

    //    int pthread_create(pthread_t * __restrict__thread, 
    //                const pthread_attr_t *attr, 
    //                void *(*start_routine) (void *arg), 
    //                void * __restrict__arg);


// Creates a new thread within a process, with attributes defined by the thread attribute object, attr, that is created by pthread_attr_init().



       rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
 }