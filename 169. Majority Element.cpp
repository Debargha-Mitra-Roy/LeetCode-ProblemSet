/*
    169. Majority Element :-

    LINK:   https://leetcode.com/problems/majority-element/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        int ans = 0;

        for (auto it = mpp.begin(); it != mpp.end(); ++it)
        {
            int key = it->first;
            int value = it->second;

            if (value > nums.size() / 2)
            {
                ans = key;
                break;
            }
        }

        return ans;
    }
};