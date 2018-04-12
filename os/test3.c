/*************************************************************************
	> File Name: test3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月12日 星期四 16时45分39秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREAD 3 //线程个数
unsigned long long main_counter, counter[MAX_THREAD];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* thread_worker(void* arg);

int main() 
{
    //int ret = pthread_mutex_init(&mutex);
    int i, rtn, ch;
    int tmp[MAX_THREAD];
    pthread_t pthread_id[MAX_THREAD] = {0};
    for (i = 0; i < MAX_THREAD; i++) 
    {
        tmp[i] = i;
        pthread_create(&pthread_id[i], NULL, thread_worker, (void*)&tmp[i]);
    }
    do 
    {
        unsigned long long sum = 0;
        pthread_mutex_lock(&mutex);
        for (i = 0; i < MAX_THREAD; i++) 
        {
            sum += counter[i];
            printf("%llu ", counter[i]);
        }
        printf("%llu/%llu", main_counter, sum);
        pthread_mutex_unlock(&mutex);
    } while((ch = getchar()) != 'q');

    return 0;
}

void* thread_worker(void* arg) 
{
    int thread_num;
    thread_num = *(int*)arg;
    for (; ;) 
    {
        pthread_mutex_lock(&mutex);
        counter[thread_num]++;
        main_counter++;
        pthread_mutex_unlock(&mutex);
    }
}

