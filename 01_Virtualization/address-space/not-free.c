#include <stdio.h>
#include <stdlib.h>


int main()
{

int *data = (int*)malloc(100*sizeof(int));

for (size_t i = 0; i < 100; i++)
{
    data[i] = 0;
}

for (size_t i = 0; i < 100; i++)
{
    printf("%d ", data[i]);
}

free(data);

for (size_t i = 0; i < 100; i++)
{
    printf("%d ", data[i]);
}


}
