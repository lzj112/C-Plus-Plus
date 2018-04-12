#include <stdio.h>
struct a
{
    char b;
    int a;
    // char b;
};
int main()
{
    struct a str;
    str.a = 10;
    str.b = 3;
    struct a* ptr = &str;
    printf("%d\n", *(int *)ptr);
}