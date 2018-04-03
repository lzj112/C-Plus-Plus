#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class str 
{
private:
    string ctr;
public:
    void Change();
};
void str::Change() 
{    
    string a, b, c, tmp;
    while (getline(cin, tmp)) 
    {
        if (tmp != "end")
        {
            ctr += tmp;
            ctr += " ";
            ctr += "换行";
            ctr += " ";
        }
        else 
        {
            break;
        }

    }
    cin >> b >> c;
    istringstream out(ctr);
    int address;
    int length = c.size();
    while (out >> a) 
    {   
        if (a == "换行") 
        {
            cout << '\n';
            continue;
        }
        address = a.find(b, 0);
        if (address == -1) 
        {
            cout << a << ' ';
        }
        else 
        {
            
            while(address != -1) 
            {
                a.replace(address, length, c);
                cout << a << ' ';
                address = a.find(b, address+length);
            }
        }
    }
}
int main()
{
    str a;
    a.Change();
    return 0;
}
