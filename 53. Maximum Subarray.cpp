/*
    53. Maximum Subarray :-

    LINK:	https://leetcode.com/problems/maximum-subarray/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxSum = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            sum = max(sum, 0) + nums[i];
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};