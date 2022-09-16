/*
    1770. Maximum Score from Performing Multiplication Operations :-

    LINK:   https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dp;

    int solve(int i, int n, int j, vector<int> &nums, vector<int> &M)
    {
        if (j == M.size())
            return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        // Left Side
        int left = solve(i + 1, n, j + 1, nums, M) + (nums[i] * M[j]);

        // Right Side
        int right = solve(i, n, j + 1, nums, M) + (nums[(n - 1) - (j - i)] * M[j]);

        return (dp[i][j] = max(left, right));
    }

public:
    int maximumScore(vector<int> &nums, vector<int> &M)
    {
        int n = nums.size();
        int m = M.size();

        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));

        return solve(0, n, 0, nums, M);
    }
};