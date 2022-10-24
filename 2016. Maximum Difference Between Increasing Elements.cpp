/*
    2016. Maximum Difference Between Increasing Elements :-

    LINK:   https://leetcode.com/problems/maximum-difference-between-increasing-elements/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int diff = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;

            while (j < nums.size() && nums[i] < nums[j])
            {
                if (nums[j] - nums[i] > diff)
                    diff = nums[j] - nums[i];

                j++;
            }
        }

        return diff;
    }
};