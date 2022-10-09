/*
    653. Two Sum IV - Input is a BST :-

    LINK:   https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/

#include <iostream>
#include <unordered_set>
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
    unordered_set<int> st;

public:
    bool findTarget(TreeNode *root, int k)
    {

        if (!root)
            return false;

        int target = k - root->val;

        if (st.count(target))
            return true;

        st.insert(root->val);

        return (findTarget(root->left, k) || findTarget(root->right, k));
    }
};