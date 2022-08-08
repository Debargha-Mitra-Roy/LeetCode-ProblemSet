/*
    1009. Complement of Base 10 Integer :-

    LINK:	https://leetcode.com/problems/complement-of-base-10-integer/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int temp = n;
        int mask = 0;

        if (n == 0) // Edge Case
            return 1;

        while (temp != 0)
        {
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }

        int ans = (~n) & mask;

        return ans;
    }
};