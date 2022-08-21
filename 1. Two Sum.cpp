/*
    1. Two Sum :-

    LINK:   https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mpp;
        vector<int> result;

        int complement = 0, index = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            complement = target - nums[i];

            if (mpp.find(complement) != mpp.end())
            {
                result.push_back(i);
                result.push_back(mpp[complement]);

                break;
            }

            mpp.insert(make_pair(nums[i], index));
            index++;
        }

        return result;
    }
};