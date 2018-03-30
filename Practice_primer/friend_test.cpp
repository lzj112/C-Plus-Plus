#include <vector>
#include <iostream>
using namespace std;
class student
{
private:
    int number, score;
    friend double average(student *p, int count);
public:
    student()
    {
        number = 0;
        score = 0;
    }
    void asd(int a, int b)
    {
        number += a;
        score += b;
    }
    double getscore()
    {
        return score;
    }
};

double average(student *p, int count)
{
    return (p->getscore() / count);
}

int main()
{
    int number, score,i = 0;
    student stu;
    while (cin >> number)
    {
        if (number == 0) 
        {
            break;
        }
        cin >> score;
        stu.asd(number, score);
        i++;
    }
    cout << average(&stu, i) << endl;
}