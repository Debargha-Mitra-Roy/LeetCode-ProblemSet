/*
    2470. Number of Subarrays With LCM Equal to K :-

    LINK:   https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int subarrayLCM(vector<int> &nums, int k)
    {
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i, lcm = 1; j < nums.size() && k % nums[j] == 0; ++j)
            {
                lcm = lcm * nums[j] / __gcd(lcm, nums[j]);
                res += lcm == k;
            }
        }

        return res;
    }
};