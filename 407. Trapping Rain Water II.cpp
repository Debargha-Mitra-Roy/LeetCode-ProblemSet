/*
    407. Trapping Rain Water II :-

    LINK:   https://leetcode.com/problems/trapping-rain-water-ii/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int m = heightMap.size();

        if (m == 0)
            return 0;

        int n = heightMap[0].size();

        vector<int> visited((m * n), false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    if (!visited[(i * n) + j])
                        pq.push(pair<int, int>(heightMap[i][j], (i * n) + j));

                    visited[(i * n) + j] = true;
                }
            }
        }

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int ans = 0;

        while (!pq.empty())
        {
            pair<int, int> it = pq.top();

            pq.pop();

            int i = (it.second / n);
            int j = (it.second % n);

            for (int k = 0; k < 4; k++)
            {
                int idxi = i + dir[k][0];
                int idxj = j + dir[k][1];

                if (idxi < 0 || idxi >= m || idxj < 0 || idxj >= n || visited[(idxi * n) + idxj])
                    continue;

                ans = ans + max(0, (it.first - heightMap[idxi][idxj]));

                pq.push(pair<int, int>(max(it.first, heightMap[idxi][idxj]), (idxi * n) + idxj));

                visited[(idxi * n) + idxj] = true;
            }
        }

        return ans;
    }
};