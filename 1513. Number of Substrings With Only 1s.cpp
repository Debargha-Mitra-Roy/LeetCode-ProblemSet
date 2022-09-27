/*
    1513. Number of Substrings With Only 1s :-

    LINK:   https://leetcode.com/problems/number-of-substrings-with-only-1s/
*/

#include <iostream>
using namespace std;

#define mod 1000000007;

class Solution
{
public:
    int numSub(string s)
    {
        int ans = 0, count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            long long int count = 0;

            while (s[i] == '1')
            {
                count++;
                i++;
            }

            ans = (ans + (count * (count + 1) / 2)) % mod;
        }

        return ans;
    }
};