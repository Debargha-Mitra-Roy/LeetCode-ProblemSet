/*
    812. Largest Triangle Area :-

    LINK:   https://leetcode.com/problems/largest-triangle-area
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double res = 0;
        for (auto &i : points)
        {
            for (auto &j : points)
            {
                for (auto &k : points)
                    res = max(res, (0.5 * abs((i[0] * j[1] + j[0] * k[1] + k[0] * i[1]) - (j[0] * i[1] + k[0] * j[1] + i[0] * k[1]))));
            }
        }

        return res;
    }
};