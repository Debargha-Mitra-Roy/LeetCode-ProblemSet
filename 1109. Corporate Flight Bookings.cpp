/*
    1109. Corporate Flight Bookings :-

    LINK:   https://leetcode.com/problems/corporate-flight-bookings/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> res(n);
        for (auto &v : bookings)
        {
            res[v[0] - 1] += v[2];

            if (v[1] < n)
                res[v[1]] -= v[2];
        }

        for (auto i = 1; i < n; ++i)
        {
            res[i] += res[i - 1];
        }

        return res;
    }
};