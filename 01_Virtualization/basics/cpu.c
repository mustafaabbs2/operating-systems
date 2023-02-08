#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

//Turning a single CPU (or a small set of them) into a seemingly infinite number of CPUs
//  and thus allowing many programs to seemingly run at once is what we call virtualizing the CPU


int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];

    while (1) {
        printf("%s\n", str);
        Spin(1);
    }
    return 0;
}