/*
    692. Top K Frequent Words :-

    LINK:   https://leetcode.com/problems/top-k-frequent-words/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    static bool comparator(pair<int, string> &a, pair<int, string> &b)
    {
        if (a.first != b.first)
            return (a.first > b.first);

        else
            return (a.second < b.second);
    }

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mpp;

        for (auto it : words)
        {
            mpp[it]++;
        }

        vector<pair<int, string>> vec;

        for (auto idx : mpp)
        {
            vec.push_back({idx.second, idx.first});
        }

        sort(vec.begin(), vec.end(), comparator);

        vector<string> ans;

        for (int i = 0; i < vec.size(); i++)
        {
            if (k)
            {
                ans.push_back(vec[i].second);
                k--;
            }
        }

        return ans;
    }
};