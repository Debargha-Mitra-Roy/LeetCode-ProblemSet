/*
    70. Climbing Stairs :-

    LINK:   https://leetcode.com/problems/climbing-stairs/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev1 = 1, prev2 = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};