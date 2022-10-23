/*
    1749. Maximum Absolute Sum of Any Subarray :-

    LINK:   https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int res = 0, max_sum = 0, min_sum = 0;
        
        for (auto n : nums)
        {
            max_sum = max(0, n + max_sum);
            min_sum = min(0, n + min_sum);
            res = max({res, max_sum, -min_sum});
        }

        return res;
    }
};