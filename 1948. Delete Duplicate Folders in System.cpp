/*
    1948. Delete Duplicate Folders in System :-

    LINK:   https://leetcode.com/problems/delete-duplicate-folders-in-system/
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct Node
{
    map<string, Node *> child;
    bool toDelete = false;
};

class Solution
{
    unordered_map<string, vector<Node *>> duplicates;
    vector<vector<string>> ans;

private:
    string dfs(Node *root)
    {
        string currValue = "";
        if (root->child.size() > 0)
            currValue += "(";

        else
            return "";

        for (auto &child : root->child)
        {
            currValue += child.first + dfs(child.second);
        }

        currValue += ")";

        if (currValue != "")
            duplicates[currValue].push_back(root);

        return currValue;
    }

    void insert(Node *root, vector<string> &path, int i)
    {
        if (i >= path.size())
            return;

        if (root->child.find(path[i]) == root->child.end())
            root->child[path[i]] = new Node();

        insert(root->child[path[i]], path, i + 1);
    }

    void removeUnwantedNodes(Node *root, vector<string> &temp)
    {
        if (root->toDelete)
            return;

        for (auto &child : root->child)
        {
            temp.push_back(child.first);
            removeUnwantedNodes(child.second, temp);
            temp.pop_back();
        }

        if (temp.size() > 0)
            ans.push_back(temp);
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Node *root = new Node();

        for (auto &path : paths)
        {
            insert(root, path, 0);
        }

        dfs(root);

        for (auto &dup : duplicates)
        {
            if (dup.second.size() > 1)
            {
                for (auto &node : dup.second)
                {
                    node->toDelete = true;
                }
            }
        }

        vector<string> temp;
        removeUnwantedNodes(root, temp);

        return ans;
    }
};