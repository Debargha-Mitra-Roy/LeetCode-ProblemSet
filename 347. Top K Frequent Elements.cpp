/*
    347. Top K Frequent Elements :-

    LINK:   https://leetcode.com/problems/top-k-frequent-elements/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    static bool comparator(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first != b.first)
            return (a.first > b.first);

        else
            return (a.second < b.second);
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;

        for (auto it : nums)
        {
            mpp[it]++;
        }

        vector<pair<int, int>> vec;

        for (auto idx : mpp)
        {
            vec.push_back({idx.second, idx.first});
        }

        sort(vec.begin(), vec.end(), comparator);

        vector<int> ans;

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