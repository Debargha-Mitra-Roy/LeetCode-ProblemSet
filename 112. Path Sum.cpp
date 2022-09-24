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
private:
    bool hasSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
        {
            if (targetSum - root->val == 0)
                return true;

            else
                return false;
        }

        return (hasSum(root->left, targetSum - root->val) || hasSum(root->right, targetSum - root->val));
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return hasSum(root, targetSum);
    }
};