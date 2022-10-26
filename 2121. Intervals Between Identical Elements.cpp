/*
    2121. Intervals Between Identical Elements :-

    LINK:   https://leetcode.com/problems/intervals-between-identical-elements/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        int size = arr.size();
        vector<long long> prefix(size, 0), suffix(size, 0), ans(size, 0);
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < size; i++)
        {
            mpp[arr[i]].push_back(i);
        }

        for (auto &p : mpp)
        {
            auto it = p.second;

            for (int i = 1; i < it.size(); i++)
            {
                prefix[it[i]] = prefix[it[i - 1]] + i * (long)(it[i] - it[i - 1]);
            }
        }

        for (auto &p : mpp)
        {
            auto it = p.second;
            for (int i = it.size() - 2; i >= 0; i--)
            {
                suffix[it[i]] = suffix[it[i + 1]] + long(it.size() - 1 - i) * (long)(it[i + 1] - it[i]);
            }
        }

        for (int i = 0; i < size; i++)
        {
            ans[i] += (prefix[i] + suffix[i]);
        }

        return ans;
    }
};