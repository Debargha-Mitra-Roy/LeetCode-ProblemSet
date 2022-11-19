/*
    587. Erect the Fence :-

    LINK:   https://leetcode.com/problems/erect-the-fence/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static int orientation(const vector<int> &a, const vector<int> &b, const vector<int> &c)
    {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        // Andrew's monotone chain method.
        sort(trees.begin(), trees.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });

        // left to right
        const int n = trees.size();
        vector<vector<int>> ans;
        ans.reserve(n);

        for (int i = 0; i < n; ++i)
        {
            while (ans.size() > 1 && orientation(ans[ans.size() - 2], ans.back(), trees[i]) < 0)
            {
                ans.pop_back();
            }

            ans.push_back(trees[i]);
        }

        // If all trees are along a line, size(ans) is n after left to right procedure.
        if (size(ans) == n)
            return ans;

        // right to left
        for (int i = n - 2; i >= 0; --i)
        {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), trees[i]) < 0)
            {
                ans.pop_back();
            }

            ans.push_back(trees[i]);
        }

        ans.pop_back();
        return ans;
    }
};