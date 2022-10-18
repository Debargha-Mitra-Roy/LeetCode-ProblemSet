/*
    875. Koko Eating Bananas :-

    LINK:   https://leetcode.com/problems/koko-eating-bananas/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int left = 1, right = 1000000000;

        while (left < right)
        {
            int m = (left + right) / 2, total = 0;

            for (int p : piles)
            {
                total += (p + m - 1) / m;
            }

            if (total > H)
                left = m + 1;

            else
                right = m;
        }

        return left;
    }
};