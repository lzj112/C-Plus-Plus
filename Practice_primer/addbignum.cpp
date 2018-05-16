#include <iostream>
#include <string>
using namespace std;
//大数相加
/**
*num1 加数1
*num2 加数2
*res  返回值
*/
//处理函数
void bigAdd(string num1, string num2, string&res){

    if (num1.size() == 0){
        res = num2;
        return;
    }
    if (num2.size() == 0){
        res = num1;
        return;
    }

    res = "";
    int n1 = num1.size()-1, n2 = num2.size()-1;
    int carry = 0;
    while (n1 >= 0 || n2 >= 0){

        int a = n1 >= 0 ? num1[n1--] - '0' : 0;
        int b = n2 >= 0 ? num2[n2--] - '0' : 0;

        int t = carry + a + b;
        carry = t / 10;
        t = t % 10;
        res = to_string(t) + res;
    }
    //判断是否还有进位
    while (carry){
        int t = carry / 10;
        carry %= 10;
        res = to_string(carry) + res;
        carry = t;
    }
    return;
}
//测试函数
int main(){

    string n1, n2, n3;
    while (cin >> n1 >> n2){

        bigAdd(n1,n2,n3);
        cout << n3 << endl;
    }
    return 0;
}