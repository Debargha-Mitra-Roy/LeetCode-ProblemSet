/*
    985. Sum of Even Numbers After Queries :-

    LINK:   https://leetcode.com/problems/sum-of-even-numbers-after-queries/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int evenSum = 0;

        for (auto x : nums)
        {
            if (x % 2 == 0)
                evenSum = evenSum + x;
        }

        vector<int> ans;

        for (auto it : queries)
        {
            int val = it[0], idx = it[1];

            if (nums[idx] % 2 == 0)
                evenSum = evenSum - nums[idx];

            nums[idx] = nums[idx] + val;

            if (nums[idx] % 2 == 0)
                evenSum = evenSum + nums[idx];

            ans.push_back(evenSum);
        }

        return ans;
    }
};