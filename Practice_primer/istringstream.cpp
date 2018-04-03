#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class PersonInfo 
{
private:
    string name;
    vector<string> phones;
public:
    void Init();
};
void PersonInfo::Init() 
{
    string line, word;
    vector<PersonInfo> people;

    while (getline(cin, line)) 
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) 
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
}