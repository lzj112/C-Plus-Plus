#include <iostream>
using namespace std;
static void *pthread1(void *arg);
static void *pthread2(void *arg);
int main()
{
    pthread_t *pid = new pthread_t[2];
    pthread_create(&pid[0], nullptr, pthread1, nullptr);
    pthread_create(&pid[1], nullptr, pthread2, nullptr);
    pthread_join(pid[0], nullptr);
    pthread_join(pid[1], nullptr);
    return 0;
}
void *pthread1(void *arg)
{
    for (int i = 0; i < 5; i++)
    cout << "here is pthread1" << endl;
}
void *pthread2(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "here is pthread2" << endl;
    }
}