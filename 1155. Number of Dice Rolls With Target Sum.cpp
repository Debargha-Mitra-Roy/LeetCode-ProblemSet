/*
    1155. Number of Dice Rolls With Target Sum :-

    LINK:   https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7;
    int dp[31][1001];

private:
    int rec(int n, int k, int target)
    {
        if (n == 0 && target == 0)
            return 1;

        if (n <= 0)
            return 0;

        if (target <= 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int count = 0;

        for (int i = 1; i <= k; i++)
        {
            if (i <= target)
                count = (count + rec(n - 1, k, target - i)) % mod;
        }

        return (dp[n][target] = count % mod);
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        return rec(n, k, target);
    }
};