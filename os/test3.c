
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
    int i, rtn, ch;
    int tmp[MAX_THREAD];
    pthread_t pthread_id[MAX_THREAD] = {0}; //存放线程id
    for (i = 0; i < MAX_THREAD; i++) 
    {
        /*在这里填写代码, 用pthread_create创建一个普通的线程, 线程id存入
        pthread_id[i], 线程执行函数为thread_worker(), 并将i作为参数传给线程*/
        // tmp[i] = i;
        // pthread_create(&pthread_id[i], NULL, thread_worker, (void*)&tmp[i]);
    }
    do  //用户按一次回车执行下面的循环体一次,按q退出 
    {
        unsigned long long sum = 0;
        // pthread_mutex_lock(&mutex);
        //求所有线程的 counter 的和
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
    //在这里填写代码, 把 main 中的i值传递给thread_num
    // thread_num = *(int*)arg;
    for (; ;) 
    {   //无限循环
        // pthread_mutex_lock(&mutex);
        counter[thread_num]++;  //本线程的 counter + 1
        main_counter++;         //主 counter +１
        // pthread_mutex_unlock(&mutex);
    }
}

/*
1. 你认为前三列数会相等么? 最后一列斜杠两边的数字是相等, 还是大于, 还是小雨
2. 最后的结果如你所料么, 有什么特点?对原因进行分析
3. thread_worker内为死循环, 他是怎么退出的, 这样推出好么?

*/