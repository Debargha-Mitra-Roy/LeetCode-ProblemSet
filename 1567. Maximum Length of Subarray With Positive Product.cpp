/*
    1567. Maximum Length of Subarray With Positive Product :-

    LINK:   https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();

        // pos_len will keep track of maximum length of subarray with positive product
        int pos_len = 0;

        // neg_len will track keep of maximum length of subarray with negative product
        int neg_len = 0;

        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                // Now positive product and negative product both will be 0, so, pos_len and neg_len will be 0
                pos_len = 0;
                neg_len = 0;
            }

            else if (nums[i] > 0)
            {
                pos_len++;

                // If neg_len is zero it means negative product is 0, so starting with curr element will not lead to negative product, that's why it will remain 0, otherwise increment neg_len, b/c multiplying to neg_product with positive element will increment the length of neg_len
                if (neg_len != 0)
                    neg_len++;
            }

            else if (nums[i] < 0)
            {
                // Here we will swap these (pos_len and neg_len)  store the neg_len
                int prev_neg_len = neg_len;

                // Increment the neg_len
                neg_len = pos_len + 1;

                // If prev_neg_len is zero it means negative product is 0, so starting with curr element will not lead to positive product, that's why it will remain 0, otherwise update pos_len, b/c multiplying to neg_product with negative element will make it positive
                if (prev_neg_len == 0)
                    pos_len = 0;

                else
                    pos_len = prev_neg_len + 1;
            }

            // Update maxi
            maxi = max(maxi, pos_len);
        }

        return maxi;
    }
};