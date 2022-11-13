/*
    2466. Count Ways To Build Good Strings :-

    LINK:   https://leetcode.com/problems/count-ways-to-build-good-strings/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        const long long int mod = 1e9 + 7;
        long long int ans = 0;

        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= high; i++)
        {
            if (i >= zero)
                dp[i] += dp[i - zero] % mod;

            if (i >= one)
                dp[i] += dp[i - one] % mod;

            if (i >= low)
                ans += dp[i] % mod;
        }

        return (ans % mod);
    }
};