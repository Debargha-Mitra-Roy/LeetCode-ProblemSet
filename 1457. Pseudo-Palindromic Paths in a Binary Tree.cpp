/*
    1457. Pseudo-Palindromic Paths in a Binary Tree :-

    LINK:   https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/

#include <iostream>
using namespace std;

/* Definition for a binary tree node */
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
    int pseudoPalindromicPaths(TreeNode *root, int count = 0)
    {
        // DFS way to find the number of pseudo palindromic paths
        if (!root)
            return 0;

        count = count ^ (1 << root->val);

        int ans = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        
        if (!root->left && !root->right && (count & (count - 1)) == 0)
            ans++;

        return ans;
    }
};