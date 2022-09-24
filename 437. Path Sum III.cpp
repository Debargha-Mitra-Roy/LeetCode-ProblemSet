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
private:
    void preorderfindSumPath(TreeNode *root, int targetSum, long long sum, int &ans)
    {
        if (root == NULL)
            return;

        if (root->val + sum == targetSum)
            ans++;

        preorderfindSumPath(root->left, targetSum, sum + root->val, ans);
        preorderfindSumPath(root->right, targetSum, sum + root->val, ans);
    }
    
    void preorder(TreeNode *root, int &targetSum, int &ans)
    {
        if (root == NULL)
            return;

        preorderfindSumPath(root, targetSum, 0, ans);

        preorder(root->left, targetSum, ans);
        preorder(root->right, targetSum, ans);
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int ans = 0;
        preorder(root, targetSum, ans);
        return ans;
    }
};