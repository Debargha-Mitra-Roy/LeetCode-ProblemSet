/*
    242. Valid Anagram :-

    LINK:   https://leetcode.com/problems/valid-anagram/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> hashMap;

        for (auto it : s)
        {
            hashMap[it]++;
        }

        for (auto it : t)
        {
            hashMap[it]--;
        }

        for (auto it : hashMap)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};