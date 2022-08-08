/*
    2364. Count Number of Bad Pairs :-

    LINK:   https://leetcode.com/problems/count-number-of-bad-pairs/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, long long int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i] - i]++;
        }

        long long int numberOfGoodPair = 0;

        for (auto it : mpp)
        {
            long long int n = it.second;

            if (it.second > 1)
                numberOfGoodPair = numberOfGoodPair + n * (n - 1) / 2;
        }

        long long int n = nums.size();

        long long int totalPair = n * (n - 1) / 2;

        long long int ans = totalPair - numberOfGoodPair;
        return ans;
    }
};