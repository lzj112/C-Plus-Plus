#include <iostream>  
#include <pthread.h>  
  
using namespace std;  
  
#define NUM_THREADS 10  
  
void* say_hello(void* args)  
{  
    int i = *((int*)args);//对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取；  
    cout << "hello in " << i << endl;  
}  
  
int main()  
{  
    pthread_t tids[NUM_THREADS];  
    cout << "hello in main..." << endl;  
    for(int i = 0; i < NUM_THREADS; ++i)  
    {  
        int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&i);//传入的时候必须强制转换为void* 类型，即无类型指针  
        cout << "Current pthread id =" << tids[i] << endl;//这里学会使用tids数组打印创建的进程id信息；  
        if (ret != 0)  
        {  
           cout << "pthread_create error: error_code=" << ret << endl;  
        }  
    }  
  
    pthread_exit(NULL);  
}  
