/*
    1775. Equal Sum Arrays With Minimum Number of Operations :-

    LINK:   https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() * 6 < nums1.size() || nums1.size() * 6 < nums2.size())
            return -1;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0), sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (sum1 > sum2)
            swap(nums1, nums2);

        int cnt[6] = {}, diff = abs(sum1 - sum2), res = 0;

        for (auto it : nums1)
            ++cnt[6 - it];

        for (auto idx : nums2)
            ++cnt[idx - 1];

        for (int i = 5; i > 0 && diff > 0; --i)
        {
            int take = min(cnt[i], diff / i + (diff % i != 0));
            diff -= take * i;
            res += take;
        }

        return res;
    }
};