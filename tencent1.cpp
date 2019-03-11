#include <iostream>
#include <vector>
using namespace std;

int minCount(long n, long m) 
{
    if (m <= n) return 1;

    int tmp = m - (m / n) * n;
    int count = m % n;

    return count + 1;
}

int main()
{
    long n, m;
    while (cin >> n >> m) 
    {
        int ret = minCount(n, m);
        cout << ret << endl;
    }
}
