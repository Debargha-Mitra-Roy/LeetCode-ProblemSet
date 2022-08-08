/*
    90. Subsets II :-

    LINK:   https://leetcode.com/problems/subsets-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{

private:
    void subsetGenerator(vector<int> &nums, vector<vector<int>> &ans, int index, vector<int> &subset)
    {
        ans.push_back(subset);

        for (int i = index; i < nums.size(); i++)
        {
            // Avoiding duplicates
            if (i != index && nums[i] == nums[i - 1])
                continue;

            // Including the element at index i and then calling the recursive function
            subset.push_back(nums[i]);
            subsetGenerator(nums, ans, i + 1, subset); // Backtracking

            // Excluding the element at index i and then calling the recursive function
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> subset;      // This vector will store each subset which is generated
        vector<vector<int>> ans; // Will store all the subsets generated

        sort(nums.begin(), nums.end()); // Sort to avoid duplicates

        subsetGenerator(nums, ans, 0, subset); // Backtracking

        return ans;
    }
};