/*
	78. Subsets :-

	LINK:   https://leetcode.com/problems/subsets/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
	void subsetGenerator(vector<int> nums, int n, vector<vector<int>> &ans, int i, vector<int> subset)
	{
		// Base Case
		if (i >= n)
		{
			ans.push_back(subset); // The subset obatined is pushed into ans
			return;
		}

		// Including the element at index i and then calling the recursive function
		subset.push_back(nums[i]);
		subsetGenerator(nums, n, ans, i + 1, subset); // Backtracking

		// Excluding the element at index i and then calling the recursive function
		subset.pop_back();
		subsetGenerator(nums, n, ans, i + 1, subset); // Backtracking
	}

public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		int i = 0;				 // Index is initialized to 0 as we start from the first element
		int n = nums.size();	 // Size of the vector nums
		vector<int> subset;		 // This vector will store each subset which is generated
		vector<vector<int>> ans; // Will store all the subsets generated

		subsetGenerator(nums, n, ans, i, subset); // Backtracking

		return ans;
	}
};