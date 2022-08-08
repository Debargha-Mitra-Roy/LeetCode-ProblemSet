/*
    231. Power of Two :-

    LINK:	https://leetcode.com/problems/power-of-two/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        if (n > 0)
        {
            n = n & (n - 1);

            if (n == 0)
                return true;
        }

        return false;
    }
};