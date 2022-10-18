/*
    42. Trapping Rain Water :-

    LINK:   https://leetcode.com/problems/trapping-rain-water/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0, maxBlock = 0, minBlock = 0;

        while (left <= right)
        {
            minBlock = min(height[left], height[right]);
            maxBlock = max(maxBlock, minBlock);

            ans = ans + maxBlock - minBlock;

            if (height[left] < height[right])
                left++;

            else
                right--;
        }

        return ans;
    }
};