/*
    191. Number of 1 Bits :-

    LINK:   https://leetcode.com/problems/number-of-1-bits/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        uint32_t temp = n;
        int count = 0;

        while (temp != 0)
        {
            /* Checking last bit */
            if (temp & 1)
                count++;

            temp = temp >> 1;
        }

        return count;
    }
};