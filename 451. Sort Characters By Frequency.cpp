/*
    451. Sort Characters By Frequency :-

    LINK:   https://leetcode.com/problems/sort-characters-by-frequency/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;

        for (auto it : s)
        {
            mpp[it]++;
        }

        vector<string> temp(s.size() + 1, "");
        string ans = "";

        for (auto it : mpp)
        {
            char ch = it.first;
            int n = it.second;
            temp[n].append(n, ch);
        }

        for (int i = s.size(); i > 0; i--)
        {
            if (!temp[i].empty())
                ans.append(temp[i]);
        }

        return ans;
    }
};