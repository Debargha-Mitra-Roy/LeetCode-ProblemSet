/*
    213. House Robber II :-

    LINK:   https://leetcode.com/problems/house-robber-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums)
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

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);

            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        return (max(solve(temp1), solve(temp2)));
    }
};