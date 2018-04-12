#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
using namespace std;

const int MAX_CHILD_NUMBBER = 2;
const int SLEEP_INTERVAL = 2;
int proc_number = 0;
void do_something();
int main(int argc, char *argv[])
{
    //子进程个数
    int child_proc_number = MAX_CHILD_NUMBBER;
    int i, ch;
    pid_t pid[10] = {0};
    if (argc > 1) 
    {
        child_proc_number = atoi(argv[1]);
        child_proc_number = (child_proc_number > 10) ? 10 : child_proc_number;
    }
    for (i = 0; i < child_proc_number; i++) 
    {
        pid[i] = fork();
        if (pid[i] == 0) 
        {
            proc_number = i;
            do_something();
        }
        else if (pid[i] > 0) 
        {
            continue;
        }
    }
    while ((ch = getchar()) != 'q') 
    {
        if (isdigit(ch)) 
        {
            int tmp = ch - '0';
            kill(pid[tmp], SIGTERM);
        }
    }
	kill(0,SIGTERM);
	return 0;
}
void do_something()
{
    for (; ;)
    {
        cout << "this is process NO." << proc_number << "and it's pid is " << getpid() << endl;
        sleep(SLEEP_INTERVAL);
    }
}
