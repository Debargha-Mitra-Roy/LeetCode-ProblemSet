/*
    1977. Number of Ways to Separate Numbers :-

    LINK:   https://leetcode.com/problems/shifting-letters-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

const long long int mod = 1e9 + 7;

long long int add(long long int a, long long int b)
{
    return (a + b + mod) % mod;
}

class Solution
{
public:
    int compare(int i, int j, int len, vector<vector<int>> &same, string &s)
    {
        // returns true if s [i:i + len - 1] <= s[i + len, i + 2 * len - 1]

        int common = same[i][j];

        if (common >= len)
            return 1; // equal substrings

        if (s[i + common] < s[j + common])
            return 1; // first substring is smaller

        else
            return 0;
    }

    int numberOfCombinations(string num)
    {
        int n = num.length();

        if (num[0] == '0')
            return 0;

        vector<vector<int>> same(n + 1, vector<int>(n + 1));

        // same[i][j] = largest common prefix of num.substr(i) and num.substr(j)
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (num[i] == num[j])
                    same[i][j] = same[i + 1][j + 1] + 1;
            }
        }

        vector<vector<int>> prefix(n, vector<int>(n));

        // Base case
        for (int j = 0; j < n; j++)
            prefix[0][j] = 1;

        for (int i = 1; i < n; i++)
        {
            if (num[i] == '0')
            {
                prefix[i] = prefix[i - 1];
                continue;
            }

            for (int j = i; j < n; j++)
            {
                int len = j - i + 1, prevStart = i - 1 - (len - 1), count = 0;

                // second last number cant have length = len
                if (prevStart < 0)
                    count = prefix[i - 1][i - 1]; // count = dp[0][i - 1] + dp[1][i - 1]... dp[i - 1][i - 1]

                else
                {
                    // when length of second last number < len
                    count = add(prefix[i - 1][i - 1], -prefix[prevStart][i - 1]); // count = dp[prevStart + 1][i - 1]... dp[i - 1][i - 1]

                    // length of second last number == len
                    if (compare(prevStart, i, len, same, num))
                    {
                        int cnt = (prevStart == 0 ? prefix[prevStart][i - 1] : add(prefix[prevStart][i - 1], -prefix[prevStart - 1][i - 1]));
                        count = add(count, cnt);
                    }
                }

                prefix[i][j] = add(prefix[i - 1][j], count); // updating prefixix sum
            }
        }

        return prefix[n - 1][n - 1];
    }
};