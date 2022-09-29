/*
    719. Find K-th Smallest Pair Distance :-

    LINK:   https://leetcode.com/problems/find-k-th-smallest-pair-distance/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];

        for (int count = 0; left < right; count = 0)
        {
            int m = left + (right - left) / 2;

            for (int i = 0, j = 0; i < n; i++)
            {
                while (j < n && nums[j] <= nums[i] + m)
                    j++;

                count += j - i - 1;
            }

            if (count < k)
                left = m + 1;

            else
                right = m;
        }

        return left;
    }
};