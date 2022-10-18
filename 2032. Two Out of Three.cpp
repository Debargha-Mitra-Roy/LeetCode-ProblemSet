/*
    2032. Two Out of Three :-

    LINK:   https://leetcode.com/problems/two-out-of-three/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        bool count[3][101] = {};

        vector<int> res;

        for (auto n : nums1)
        {
            count[0][n] = true;
        }

        for (auto n : nums2)
        {
            count[1][n] = true;
        }

        for (auto n : nums3)
        {
            count[2][n] = true;
        }

        for (int i = 1; i <= 100; ++i)
        {
            if (count[0][i] + count[1][i] + count[2][i] > 1)
                res.push_back(i);
        }

        return res;
    }
};