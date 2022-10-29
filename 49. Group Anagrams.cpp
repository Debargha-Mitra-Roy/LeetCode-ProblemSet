/*
    49. Group Anagrams :-

    LINK:   https://leetcode.com/problems/group-anagrams/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Base Case
        if (strs.size() == 1)
            return {{strs[0]}};

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> temp;

        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end());

            temp[strs[i]].push_back(str);
        }

        for (auto i = temp.begin(); i != temp.end(); i++)
        {
            ans.push_back(i->second);
        }

        return ans;
    }
};