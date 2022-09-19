/*
    652. Find Duplicate Subtrees :-

    LINK:   https://leetcode.com/problems/find-duplicate-subtrees/
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
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
    vector<TreeNode *> v;
    unordered_map<string, int> mp;

private:
    string helper(TreeNode *root)
    {
        if (!root)
            return "$";

        string left = helper(root->left);
        string right = helper(root->right);
        string s = to_string(root->val) + "$" + left + "$" + right;

        if (mp[s] == 1)
            v.push_back(root);

        mp[s]++;

        return s;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        if (!root)
            return v;

        helper(root);

        return v;
    }
};