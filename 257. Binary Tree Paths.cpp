/*
    112. Path Sum :-

    LINK:   https://leetcode.com/problems/path-sum/
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
    vector<string> ans;

private:
    void dfs(TreeNode *root, string str)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            str += to_string(root->val);
            ans.push_back(str);
        }
        
        str += to_string(root->val) + "->";

        dfs(root->left, str);
        dfs(root->right, str);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string str = "";

        dfs(root, str);

        return ans;
    }
};