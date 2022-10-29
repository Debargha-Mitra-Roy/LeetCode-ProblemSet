/*
    2136. Earliest Possible Day of Full Bloom :-

    LINK:   https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<int> indices(plantTime.size());

        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int i, int j)
             { return growTime[i] > growTime[j]; });

        int result = 0, currPlantTime = 0;

        for (int i : indices)
        {
            currPlantTime += plantTime[i];
            result = max(result, currPlantTime + growTime[i]);
        }

        return result;
    }
};