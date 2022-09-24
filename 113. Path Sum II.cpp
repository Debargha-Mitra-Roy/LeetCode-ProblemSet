/*
    113. Path Sum II :-

    LINK:   https://leetcode.com/problems/path-sum-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    vector<vector<int>> ans;

private:
    void dfs(TreeNode *root, vector<int> &path, int remainingSum)
    {
        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right && remainingSum == root->val)
            ans.push_back(path);

        dfs(root->left, path, (remainingSum - root->val));
        dfs(root->right, path, (remainingSum - root->   val));

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;

        dfs(root, path, targetSum);

        return ans;
    }
};