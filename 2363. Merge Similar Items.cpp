/*
    2363. Merge Similar Items :-

    LINK:   https://leetcode.com/problems/merge-similar-items/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> items;

        for (auto it : items1)
        {
            items[it[0]] = items[it[0]] + it[1];
        }

        for (auto it : items2)
        {
            items[it[0]] = items[it[0]] + it[1];
        }

        vector<vector<int>> ret;

        for (auto it : items)
        {
            ret.push_back({it.first, it.second});
        }

        return ret;
    }
};