#include <iostream>
#include <fstream>

#include "cJSON.h"

using namespace std;

int main()
{
    Json::Reader reader;
    Json::Value root;

    //从文件中读取
    ifstream is;
    is.open("PersonalInfo.json", ios::binary);

    if(reader.parse(is,root))
    {
        //读取根节点信息
        string name = root["name"].asString();
        int age = root["age"].asInt();
        bool sex_is_male = root["sex_is_male"].asBool();

        cout << "My name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "I'm a " << (sex_is_male ? "man" : "woman") << endl;

        //读取子节点信息
        string partner_name = root["partner"]["partner_name"].asString();
        int partner_age = root["partner"]["partner_age"].asInt();
        bool partner_sex_is_male = root["partner"]["partner_sex_is_male"].asBool();

        cout << "My partner's name is " << partner_name << endl;
        cout << (partner_sex_is_male ? "he" : "she") << " is "
            << partner_age << " years old" << endl;

        //读取数组信息
        cout << "Here's my achievements:" << endl;
        for(int i = 0; i < root["achievement"].size(); i++)
        {
            string ach = root["achievement"][i].asString();
            cout << ach << '\t';
        }
        cout << endl;

        cout << "Reading Complete!" << endl;
    }

    is.close();

    return 0;
}