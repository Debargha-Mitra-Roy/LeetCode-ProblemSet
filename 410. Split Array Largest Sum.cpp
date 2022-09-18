/*
    410. Split Array Largest Sum :-

    LINK:   https://leetcode.com/problems/split-array-largest-sum/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int left = 0, right = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            left = max(left, nums[i]);
            right = right + nums[i];
        }

        int mid = 0, ans = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            int count = 0, tempSum = 0;

            for (int i = 0; i < n; i++)
            {
                if (tempSum + nums[i] <= mid)
                    tempSum = tempSum + nums[i];

                else
                {
                    count++;
                    tempSum = nums[i];
                }
            }

            count++;

            if (count <= m)
            {
                right = mid - 1;
                ans = mid;
            }

            else
                left = mid + 1;
        }

        return ans;
    }
};