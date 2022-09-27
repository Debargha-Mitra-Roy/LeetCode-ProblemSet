/*
    639. Decode Ways II :-

    LINK:   https://leetcode.com/problems/decode-ways-ii/
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
    long long int dp[100006];
    int mod = 1000000007;

private:
    long long int solve(int pos, string &s)
    {
        int n = s.size();

        if (pos >= n)
            return 1;

        if (s[pos] == '0')
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        long long int cnt = 0;

        if (s[pos] == '*')
        {
            for (int i = 1; i <= 9; i++)
            {
                cnt = (cnt + solve(pos + 1, s)) % mod;

                if (pos + 1 < n && s[pos + 1] == '*')
                {
                    for (int j = 1; j <= 9; j++)
                    {
                        if (i * 10 + j < 27)
                            cnt = (cnt + solve(pos + 2, s)) % mod;
                    }
                }

                else if (pos + 1 < n && i * 10 + (s[pos + 1] - '0') < 27)
                    cnt = (cnt + solve(pos + 2, s)) % mod;
            }
        }

        else
        {
            cnt = (cnt + solve(pos + 1, s)) % mod;

            if (pos + 1 < n && s[pos + 1] == '*')
            {
                for (int j = 1; j <= 9; j++)
                {
                    if ((s[pos] - '0') * 10 + j < 27)
                        cnt = (cnt + solve(pos + 2, s)) % mod;
                }
            }

            else if (pos + 1 < n)
            {
                if ((s[pos] - '0') * 10 + (s[pos + 1] - '0') < 27)
                    cnt = (cnt + solve(pos + 2, s)) % mod;
            }
        }

        return dp[pos] = (cnt % mod);
    }

public:
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof(dp));

        return solve(0, s);
    }
};