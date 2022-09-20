/*
    209. Minimum Size Subarray Sum :-

    LINK:   https://leetcode.com/problems/minimum-size-subarray-sum/
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = 0, minLen = INT_MAX;
        int sum = 0;

        while (right < n)
        {
            sum = sum + nums[right];

            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum = sum - nums[left];
                    left++;
                }

                minLen = min(minLen, (right - left + 2));
            }

            right++;
        }

        if(minLen == INT_MAX)
            return 0;

        else
            return minLen;
    }
};