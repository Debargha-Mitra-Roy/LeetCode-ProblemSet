/*
    88. Merge Sorted Array :-

    LINK:   https://leetcode.com/problems/merge-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int &m, vector<int> &nums2, int &n)
    {
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }

        int k = m + n;

        while (k-- && m && n)
        {
            if (nums1[m - 1] < nums2[n - 1])
            {
                n--;
                nums1[k] = nums2[n];
            }

            else
            {
                m--;
                nums1[k] = nums1[m];
            }
        }

        while (n--)
        {
            nums1[k--] = nums2[n];
        }
    }
};
