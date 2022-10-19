/*
    973. K Closest Points to Origin :-

    LINK:   https://leetcode.com/problems/k-closest-points-to-origin/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Answer vector
        vector<vector<int>> result(k);

        // maxheap storage initialization
        priority_queue<vector<int>> maxHeap;

        // Construction of maxheap
        for (auto &it : points)
        {
            int x = it[0], y = it[1];
            maxHeap.push({((x * x) + (y * y)), x, y});

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        for (int i = 0; i < k; ++i)
        {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]};
        }

        return result;
    }
};