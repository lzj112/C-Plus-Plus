#include <map>
#include <set>
#include <iostream>
using namespace std;
int main() 
{
    map<string, int> word_count;
    string word;
    set<string> tmp{"qwe"};
    while (cin >> word) 
    {
        if (tmp.find(word) == tmp.end())
        ++word_count[word];
    }
    for (const auto &w : word_count) 
    {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }
}