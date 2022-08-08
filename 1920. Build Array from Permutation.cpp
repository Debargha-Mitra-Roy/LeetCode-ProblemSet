/*
    1920. Build Array from Permutation :-

    LINK:   https://leetcode.com/problems/build-array-from-permutation/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back(nums[nums[i]]);
        }

        return temp;
    }
};