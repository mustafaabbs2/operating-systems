#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
    // printf("%s\n", argv[1]);

    // int mb = atoi(argv[1]);
    // int secs = atoi(argv[2]);

    int mb = 100;
    int secs = 2000;

    // int secs = strtoi(argv[2], NULL, 10);

    // 1 Mb = 1024 kb = 1024 * 1024 bytes
    int *array; 
    array = (int *) malloc(mb*1024*1024); //allocates n Mb of memory

    if (array == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    int n = mb*1024*1024/sizeof(int);

    time_t startTime = time(NULL);

    while (time(NULL) - startTime < secs) {

        for (int i = 0; i < n; i++) {
                array[i] = i;
            }
        //   int x = time(NULL) - startTime;  
    }

}