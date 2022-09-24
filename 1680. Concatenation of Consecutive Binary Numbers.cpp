/*
    1680. Concatenation of Consecutive Binary Numbers :-

    LINK:   https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        int l = 0;
        const int mod = 1e9 + 7;

        long long int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
                l += 1;

            ans = ((ans << l) | i) % mod;
        }

        return ans;
    }
};