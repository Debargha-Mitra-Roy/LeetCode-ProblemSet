/*
    2239. Find Closest Number to Zero :-

    LINK:   https://leetcode.com/problems/find-closest-number-to-zero/
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        //  Setting the ans to maximum value of int
        int ans = INT_MAX;

        for (int it : nums)
        {
            // Checking if each value of nums is less than the max value
            if (abs(it) < abs(ans))
                ans = it; // Check for the lesser value

            else if (abs(it) == abs(ans))
                ans = max(ans, it); // Return the maximum in cases there are multiple answers
        }

        return ans;
    }
};