/*
    1137. N-th Tribonacci Number :-

    LINK:   https://leetcode.com/problems/n-th-tribonacci-number/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solve(int n, vector<int> &dp)
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }

public:
    int tribonacci(int n)
    {
        if (n <= 1)
            return n;

        if (n == 2)
            return 1;

        vector<int> dp(n + 1);
        return solve(n, dp);
    }
};