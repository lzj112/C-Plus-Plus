#include <stdio.h>
#include <unistd.h>
// #include <sys/wait.h>
// #include <sys/types.h>
int main() 
{
    // pid_t pid;
    int pid;
    // int* status;
    if (pid = fork()) 
    { 
        // waitpid(pid, status, 0);
        printf("a\n");
    }
    else 
    {
        if (pid = fork()) 
        {
            // waitpid(pid, status, 0);
            printf("b\n");
        }
        else 
        {
            printf("c\n");
        }
    }
    return 0;
}