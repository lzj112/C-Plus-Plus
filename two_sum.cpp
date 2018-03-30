#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution :: twoSum(vector<int>& nums, int target)
{
    vector<int> tmp;
    auto begin1 = nums.begin(), begin2 = nums.begin(), end = nums.end();
    for (; begin1 != end; begin1++)
    {
        for (begin2 = begin1 + 1; begin2 != end; begin2++)
        {
            if (*begin1 + *begin2 == target) 
            {
                tmp.push_back(distance(nums.begin(), begin1));
                tmp.push_back(distance(nums.begin(), begin2));
                break;
            }
        }
    }
    return tmp;
}
