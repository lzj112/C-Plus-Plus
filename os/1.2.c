#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int i;
    pid_t pid;
 /*   for (i = 0; i < 2; i++) 
    {
        pid = fork();
        if (pid == 0)
        printf("1");
        if (pid > 0)
        printf("2");
        // printf("\n");
    }
    wait(NULL);
    wait(NULL);
    // printf("\n");
    */
    pid = fork();
    if (pid > 0) 
    {
        printf("1\n");
    }
    if ( pid == 0)
    {
        printf("2\n");
    }
    return 0;
}