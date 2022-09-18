/*
    238. Product of Array Except Self :-

    LINK:   https://leetcode.com/problems/product-of-array-except-self/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        int count = 0, allProduct = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                count++;
                continue;
            }

            allProduct = allProduct * nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
                nums[i] = allProduct / nums[i];

            else if (count == 1)
            {
                if (nums[i] != 0)
                    nums[i] = 0;
                else
                    nums[i] = allProduct;
            }

            else
                nums[i] = 0;
        }

        return nums;
    }
};