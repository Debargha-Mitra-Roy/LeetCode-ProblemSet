/*
    287. Find the Duplicate Number :-

    LINK:   https://leetcode.com/problems/find-the-duplicate-number/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                ans = nums[i];
                break;
            }

            else
                continue;
        }

        return ans;
    }
};