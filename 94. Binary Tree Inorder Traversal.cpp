/*
    94. Binary Tree Inorder Traversal :-

    LINK:   https://leetcode.com/problems/binary-tree-inorder-traversal/
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
public:
    void inorderhelp(TreeNode *root, vector<int> &x)
    {
        if (root == NULL)
            return;

        /* Left subtree */
        inorderhelp(root->left, x);

        /* Pushing value of root to ans */
        x.push_back(root->val);

        /* Right subtree */
        inorderhelp(root->right, x);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorderhelp(root, ans);

        return ans;
    }
};