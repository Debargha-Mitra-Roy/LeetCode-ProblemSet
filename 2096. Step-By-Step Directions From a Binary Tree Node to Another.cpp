/*
    2096. Step-By-Step Directions From a Binary Tree Node to Another :-

    LINK:   https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
*/

#include <iostream>
#include <vector>
#include <string>
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
    bool find(TreeNode *root, string &st, int &tar)
    {
        if (!root)
            return false;

        if (root->val == tar)
            return true;

        st.push_back('L');

        if (find(root->left, st, tar))
            return true;

        st.pop_back();

        st.push_back('R');

        if (find(root->right, st, tar))
            return true;

        st.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode *root, int start, int dest)
    {
        // string for storing the path to start and dest value.
        string st = "", en = "";

        // these functions calculate the path of start and dest value
        bool r = find(root, st, start);
        r = find(root, en, dest);

        int i = 0, j = 0;

        while (i < st.size() && j < en.size() && st[i] == en[j])
        {
            i++;
            j++;
        }
        string ans = "";

        while (i < st.size())
        {
            ans.push_back('U');
            i++;
        }

        ans += en.substr(j, en.size() - j);
        return ans;
    }
};