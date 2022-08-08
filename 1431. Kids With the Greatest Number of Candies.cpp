/*
    1431. Kids With the Greatest Number of Candies :-

    LINK:   https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size(), maxCandies = 0;

        for (int i = 0; i < n; i++)
        {
            if (candies[i] > maxCandies)
                maxCandies = candies[i];
        }

        vector<bool> result(n);

        for (int i = 0; i < n; i++)
            result[i] = (candies[i] + extraCandies >= maxCandies);

        return result;
    }
};