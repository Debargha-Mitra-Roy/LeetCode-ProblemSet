/*
    1293. Shortest Path in a Grid with Obstacles Elimination :-

    LINK:   https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
*/

#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
    const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size(), steps = 0;
        vector<vector<int>> remains(m, vector<int>(n, INT_MIN));

        queue<array<int, 3>> q;

        q.push({0, 0, k});

        remains[0][0] = k;

        while (!q.empty())
        {
            for (int it = q.size(); it > 0; it--)
            {
                auto cur = q.front();
                q.pop();

                if (cur[0] == m - 1 && cur[1] == n - 1)
                    return steps;

                for (int i = 0; i < 4; i++)
                {
                    int next_x = cur[0] + dx[i], next_y = cur[1] + dy[i];

                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
                        continue;

                    int remain = cur[2] - grid[next_x][next_y];

                    if (remain >= 0 && remains[next_x][next_y] < remain)
                    {
                        q.push({next_x, next_y, remain});
                        remains[next_x][next_y] = remain;
                    }
                }
            }

            steps += 1;
        }

        return -1;
    }
};
