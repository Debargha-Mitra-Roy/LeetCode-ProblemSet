/*
    15. 3Sum :-

    LINK:   https://leetcode.com/problems/3sum/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        if (nums.size() < 3 || nums[0] > 0)
            return {};

        unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); ++i)
        {
            hashMap[nums[i]] = i;
        }

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
                break;

            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                int required = -1 * (nums[i] + nums[j]);

                if (hashMap.count(required) && hashMap.find(required)->second > j)
                    ans.push_back({nums[i], nums[j], required});

                j = hashMap.find(nums[j])->second;
            }

            i = hashMap.find(nums[i])->second;
        }

        return ans;
    }
};