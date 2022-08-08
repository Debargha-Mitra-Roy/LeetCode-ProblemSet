/*
    476. Number Complement :-

    LINK:	https://leetcode.com/problems/number-complement/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int temp = num;
        int mask = 0;

        if (num == 0) // Edge Case
            return 1;

        while (temp != 0)
        {
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }

        int ans = (~num) & mask;

        return ans;
    }
};