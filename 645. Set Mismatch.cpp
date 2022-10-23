/*
    645. Set Mismatch :-

    LINK:   https://leetcode.com/problems/set-mismatch/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n + 1, 0);

        for (auto it : nums)
        {
            arr[it]++;
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] > 1)
                ans.push_back(i);
        }

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};