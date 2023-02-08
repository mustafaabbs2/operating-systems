#include <stdio.h>
#include <stdlib.h>


int main()
{
    // int a = 5;
    // int *p;
    // p = &a;
    // The right way to do this 


    int *p;
    p = NULL;
    printf("%d", *p);  
    
    // gcc null.c -o null -g
// valgrind --leak-check=yes ./null

}