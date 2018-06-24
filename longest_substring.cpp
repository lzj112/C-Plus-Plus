/*
给定一个字符串，查找最长子字符串的长度，而不需要重复字符。
例子
给定“abcabcbb”，答案是“abc”，长度为3。
给定“bbbbb”，答案是“b”，长度为1。
给定“pwwkew”，答案是“wke”，长度为3。注意，答案必须是子字符串，“pwke”是子序列，而不是子字符串*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s);
};
int Solution::lengthOfLongestSubstring(string s) 
{
    int len = s.size();
    int i = 0, counter = 0;
    while (i < len) 
    {
        
    }

}