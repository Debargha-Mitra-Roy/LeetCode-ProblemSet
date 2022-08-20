/*
    217. Contains Duplicate :-

    LINK:	https://leetcode.com/problems/contains-duplicate/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> count;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            count[nums[i]]++;

            if (count[nums[i]] == 2)
                return true;
        }

        return false;
    }
};