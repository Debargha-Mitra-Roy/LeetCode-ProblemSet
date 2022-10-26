/*
    2009. Minimum Number of Operations to Make Array Continuous :-

    LINK:   https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 0;

        sort(nums.begin(), nums.end());

        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int k = nums.size(); j < k; ++j)
        {
            if (nums[i] + n <= nums[j])
                ++i;
        }

        return (n - j + i);
    }
};