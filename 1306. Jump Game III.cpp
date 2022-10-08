/*
    1306. Jump Game III :-

    LINK:   https://leetcode.com/problems/jump-game-iii/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    unordered_set<int> vis;

public:
    bool canReach(vector<int> &arr, int start)
    {
        if (start >= 0 && start < arr.size() && vis.insert(start).second)
            return (arr[start] == 0 || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]));

        return false;
    }
};