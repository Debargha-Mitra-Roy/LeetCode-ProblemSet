/*
    2465. Number of Distinct Averages :-

    LINK:   https://leetcode.com/problems/number-of-distinct-averages/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        unordered_set<int> s;

        for (int i = 0; i < n / 2; i++)
        {
            s.insert(nums[i] + nums[n - i - 1]);
        }

        return s.size();
    }
};