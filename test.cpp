#include <iostream>
#include <array>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;
int main() 
{
    pid_t pid = fork();
    if (pid == 0) 
        printf("son\n");
    else 
        printf("father\n");
}