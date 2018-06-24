#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() 
{
    int pid = fork();
    if (pid == 0) 
    {
        printf("here is child\n");
    }
    else 
    {
        printf("here is father\n");
    }
    return 0;
}