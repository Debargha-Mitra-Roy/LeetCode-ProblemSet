/*
    1578. Minimum Time to Make Rope Colorful :-

    LINK:   https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int res = neededTime[0], max_cost = neededTime[0];

        for (int i = 1; i < colors.size(); ++i)
        {
            if (colors[i] != colors[i - 1])
            {
                res -= max_cost;
                max_cost = 0;
            }

            res += neededTime[i];
            max_cost = max(max_cost, neededTime[i]);
        }

        int ans = res - max_cost;
        return ans;
    }
};