// program to find the cost of a system call

#include <stdio.h>
#include <sys/time.h> //needed for gettimeofday()
#include <fcntl.h>


int main(){
struct timeval start, end;

gettimeofday(&start, NULL);

int fd = open("test.txt", O_CREAT);

gettimeofday(&end, NULL);

int time =  (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); //usec = microseconds, so this shows the time in microseconds
printf("Time: %d microseconds\n", time); 

}