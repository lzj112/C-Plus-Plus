//在这里给出函数被调用进行测试的例子。例如：
#include <iostream>
#include <string>
using namespace std;
// 你提交的代码将嵌入到这里


const int SIZE=100;
/*整数队列类
class Queue {    
  int q[SIZE];
  int front;  //队列头
  int rear;   //队列尾
public:
  Queue( ) 
  { front = rear = 0; }
  void put(int i); // 在队尾放置一个数据
  int get( );  // 从队列头部取一个数据
};*/

template<class T>
class Queue 
{
    T* q;
    int front, rear;
public:
    Queue();
    Queue(T);
    ~Queue();
    void put(T i);
    T get();
    void show();
};
template<class T>
void Queue<T>::show() 
{
    int i1 = front;
    int i2 = rear;
    for (; i1 < i2; i1++) 
    {
        cout << q[i1] << "----";
    }
    cout << endl;
}
template<class T>
Queue<T>::Queue() 
{
    q = new T[SIZE];
    front = 0;
    rear = 0;
}
template<class T>
Queue<T>::~Queue() 
{
    delete[] q;
    q = nullptr;
}
template<class T>
void Queue<T>::put(T i) 
{
    if (rear == SIZE) 
    {
        return;
    }
    q[rear] = i;
    rear++;
}
template<class T>
T Queue<T>::get() 
{
    T tmp = q[front];
    front++;
    return tmp;
}

int main()
{
  Queue<int> a; // 创建一个整数队列
  int m,n;
  cin>>m>>n; 
  a.put(m);
  a.put(n);
  a.show();
  cout << a.get() << " ";
  cout << a.get() << endl;

  Queue<double> d; // 创建一个双精度浮点数队列
  double x,y;
  cin>>x>>y;
  d.put(x);
  d.put(y);
  cout << d.get() << " ";
  cout << d.get() << endl;

  Queue<string> qs;// 创建一个字符串队列
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  qs.put(s1);
  qs.put(s2);
  qs.put(s3);
  cout <<	qs.get() << " ";
  cout <<	qs.get() << " ";
  cout << qs.get() << endl;

  return 0;
}