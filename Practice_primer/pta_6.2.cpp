#include <iostream>
using namespace std;
// 你提交的代码将嵌入到这里
template<class T>
T Min(T* p, int len) 
{
    T min = p[i];
    for (int i = 0; i < len; i++) 
    {
        if (p[i] < min) 
        {
            min = p[i];
        }
        cout << p[i] << ' ' << min << endl;
    }
    return min;
}

int main( )
{
    int n,m,*pn,i=0;
    cin>>n;
    pn=new int[n];
    do{
        cin>>pn[i];
        i++;
    }while(i<n);

    double *pd;
    i=0;
    cin>>m;
    pd=new double[m];
    do{
        cin>>pd[i];
        i++;
    }while(i<m);

    cout<<Min(pn,n)<<endl;
    cout<<Min(pd,m)<<endl;
    delete [ ] pn;
    delete [ ] pd;
    return 0;
}
