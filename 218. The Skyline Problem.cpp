/*
    218. The Skyline Problem :-

    LINK:   https://leetcode.com/problems/the-skyline-problem/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> vec;

        for (auto b : buildings)
        {
            vec.push_back(b[0]);
            vec.push_back(b[1]);
        }

        sort(vec.begin(), vec.end());

        int n = unique(vec.begin(), vec.end()) - vec.begin();
        int j = 0;
        int past = 0;

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            while (j < buildings.size() && buildings[j][0] <= vec[i])
            {
                pq.push(make_pair(buildings[j][2], buildings[j][1]));
                j++;
            }

            while (!pq.empty() && pq.top().second <= vec[i])
            {
                pq.pop();
            }
            
            int present = pq.empty() ? 0 : pq.top().first;

            if (present != past)
            {
                res.push_back({vec[i], present});
                past = present;
            }
        }

        return res;
    }
};