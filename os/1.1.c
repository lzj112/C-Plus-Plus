#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    int status;
    puts("刘浩森");

    //创建子进程
    pid_t pid = fork();
    if (pid == -1) 
    {
        perror("创建子进程失败\n");
        return 1;
    }

    //判断是否是子进程
    if (pid == 0) 
    {
        puts("i'm child\n");

        puts("sleep 5s...\n");
        sleep(5);
        puts("sleep end\n");

        printf("子进程pid是%d\n", getpid());
        printf("父进程pid是%d\n", getppid());
        return 0;
    }
    else 
    {
        puts("i'm parent\n");

        printf("子进程pid是%d\n", getpid());
        printf("父进程pid是%d\n", getppid());
    }

    wait(&status);
    printf("%d\n", status);
    puts("main end\n");;
    return 0;
}