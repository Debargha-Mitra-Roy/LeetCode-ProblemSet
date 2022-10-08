/*
    129. Sum Root to Leaf Numbers :-

    LINK:   https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

#include <iostream>
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
    // Preorder DFS Traversal
    int dfs(TreeNode *root, int cur)
    {
        if (!root)
            return 0;

        cur = cur * 10 + root->val; // Append current node's digit

        if (!root->left && !root->right) // leaf node - return current number to be added to total sum
            return cur;

        return (dfs(root->left, cur) + dfs(root->right, cur)); // Recurse for child if current node is not leaf
    }

public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};