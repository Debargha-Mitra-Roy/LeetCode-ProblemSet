/*
    2290. Minimum Obstacle Removal to Reach Corner :-

    LINK:   https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        deque<pair<int, int>> dq;

        dq.push_front({0, 0});
        dp[0][0] = 0;

        while (dq.size())
        {
            pair<int, int> p = dq.front();
            dq.pop_front();

            int cx = p.first;
            int cy = p.second;

            for (int i = 0; i < 4; i++)
            {
                int tx = cx + dx[i];
                int ty = cy + dy[i];

                if (tx >= 0 && tx < m && ty >= 0 && ty < n)
                {
                    if (!vis[tx][ty])
                    {
                        dp[tx][ty] = dp[cx][cy] + (grid[tx][ty] == 1);

                        if (grid[tx][ty] == 1)
                            dq.push_back({tx, ty});

                        else
                            dq.push_front({tx, ty});

                        vis[tx][ty] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
