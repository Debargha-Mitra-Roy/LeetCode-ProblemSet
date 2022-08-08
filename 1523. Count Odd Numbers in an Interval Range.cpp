/*
    1523. Count Odd Numbers in an Interval Range :-

    LINK:   https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int count = 0;

        if (low % 2 != 0 || high % 2 != 0)
            count = ((high - low) / 2) + 1;

        else
            count = (high - low) / 2;

        return count;
    }
};