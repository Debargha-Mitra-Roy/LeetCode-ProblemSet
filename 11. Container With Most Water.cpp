/*
    11. Container With Most Water :-

    LINK:   https://leetcode.com/problems/container-with-most-water/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maximumArea = 0, minimumArea = 0, width = 0;

        while (left < right)
        {
            width = right - left;
            minimumArea = min(height[left], height[right]);
            maximumArea = max(maximumArea, (minimumArea * width));

            if (height[left] < height[right])
                left++;

            else
                right--;
        }

        return maximumArea;
    }
};