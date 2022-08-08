/*
    724. Find Pivot Index :-

    LINK:	https://leetcode.com/problems/find-pivot-index/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int size = nums.size();

        int leftSum = 0, sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum = sum + nums[i];
        }

        int ans = -1;

        for (int i = 0; i < size; i++)
        {
            if (leftSum == sum - leftSum - nums[i])
            {
                ans = i;
                break;
            }

            leftSum = leftSum + nums[i];
        }

        return ans;
    }
};