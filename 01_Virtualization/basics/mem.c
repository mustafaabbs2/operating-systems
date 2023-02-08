#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

//gcc -Wall -O2 -o mem mem.c -lm

// Indeed, that is exactly what is happening here as the OS is virtualizing memory.
// Each process accesses its own private virtual address space (sometimes just called its address space),
// which the OS somehow maps onto the physical memory of the machine.
// A memory reference within one running program does not affect the address space of other processes (or the OS itself);
//  as far as the running program is concerned, it has physical memory all to itself. 

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "usage: mem <value>\n"); 
        exit(1); 
    } 
    int *p; 
    p = malloc(sizeof(int));                                      //a1
    assert(p != NULL);
    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p); //a2
    *p = atoi(argv[1]); // assign value to addr stored in p.      //a3
    while (1) {
        Spin(1);                                                   //a4 - delays for a second
            *p = *p + 1;
            printf("(%d) value of p: %d\n", getpid(), *p);
        }
    return 0;
}