#include <stdio.h>
int main() 
{
    int a = 1, b = 2;
    a +=b; b = a-b; a -=b;
    printf("%d %d\n",a,b);
}