/*
    623. Add One Row to Tree :-

    LINK:   https://leetcode.com/problems/add-one-row-to-tree/
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
    void trav(TreeNode *root, int val, int depth)
    {
        if (root == nullptr || depth < 2)
            return;

        if (depth == 2)
        {
            TreeNode *l = new TreeNode(val);
            TreeNode *r = new TreeNode(val);

            // Insert new nodes inbetween current node and next nodes
            l->left = root->left;
            r->right = root->right;

            root->left = l;
            root->right = r;
        }
        trav(root->left, val, depth - 1); // Go to next depth
        trav(root->right, val, depth - 1);
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            // Edge case dealt with as specified in problem description
            TreeNode *t = new TreeNode(val, root, nullptr);
            return t;
        }

        trav(root, val, depth);

        return root;
    }
};