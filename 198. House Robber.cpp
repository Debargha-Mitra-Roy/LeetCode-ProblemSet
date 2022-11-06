/*
    198. House Robber :-

    LINK:   https://leetcode.com/problems/house-robber/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 0; i < n; i++)
        {
            int pick = nums[i];

            if (i > 1)
                pick += prev2;

            int nonPick = prev1;
            int curr = max(pick, nonPick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};