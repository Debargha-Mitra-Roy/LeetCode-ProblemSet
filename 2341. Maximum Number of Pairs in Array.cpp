/*
    2341. Maximum Number of Pairs in Array :-

    LINK:   https://leetcode.com/problems/maximum-number-of-pairs-in-array/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        map<int, int> mpp;

        for (auto it : nums)
        {
            mpp[it]++;
        }

        int pair = 0, left = 0;

        for (auto it : mpp)
        {
            pair += it.second / 2;
        }

        for (auto it : mpp)
        {
            left += it.second % 2;
        }

        return {pair, left};
    }
};