/*
    852. Peak Index in a Mountain Array :-

    LINK:	https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int size = arr.size();

        int left = 0, right = size - 1;

        while (left < right)
        {
            int mid = left + ((right - left) / 2);

            if (arr[mid] < arr[mid + 1])
                left = mid + 1;

            else
                right = mid;
        }

        return left;
    }
};