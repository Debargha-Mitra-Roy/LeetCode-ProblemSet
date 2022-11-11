/*
    26. Remove Duplicates from Sorted Array :-

    LINK:   https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] != nums[i])
            {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};