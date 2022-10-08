/*
    2028. Find Missing Observations :-

    LINK:   https://leetcode.com/problems/find-missing-observations/
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int m_sum = accumulate(rolls.begin(), rolls.end(), 0);
        int n_sum = mean * (n + m) - m_sum;

        vector<int> res;
        
        if (6 * n < n_sum || n > n_sum)
            return {};

        for (; n > 0; --n)
        {
            res.push_back(min(6, n_sum - n + 1));
            n_sum -= res.back();
        }

        return res;
    }
};