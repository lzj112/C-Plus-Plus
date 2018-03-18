#include<iostream>
#include<vector>
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    std :: vector < int > tmp(&a[0], &a[10]);
    // std::cout << tmp.size() << std::endl;
    for (int x : tmp)
    {
        // std::cout << x << std::endl;
         (x % 2) == 0 ? std::cout << x << std::endl : std::cout << x*2 << std::endl;
    }
    return 0;

}