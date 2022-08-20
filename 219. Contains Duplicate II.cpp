/*
    219. Contains Duplicate II :-

    LINK:	https://leetcode.com/problems/contains-duplicate-ii/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; ++i)
        {
            if (mpp.count(nums[i]) && abs(i - mpp[nums[i]]) <= k)
                return true;

            mpp[nums[i]] = i;
        }

        return false;
    }
};