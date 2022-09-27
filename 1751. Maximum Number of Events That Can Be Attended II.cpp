/*
    1751. Maximum Number of Events That Can Be Attended II :-

    LINK:   https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int N = events.size();
        vector<vector<int>> dp(N + 1, vector<int>(k + 1));

        auto cmp = [&](vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        };

        sort(events.begin(), events.end(), cmp);

        vector<int> ends;
        for (auto e : events)
        {
            ends.push_back(e[1]);
        }

        // pre compute: if i is selected, what's the maximum possible end of previous meeting
        vector<int> pre(N);
        for (int i = 0; i < N; i++)
        {
            auto e = events[i];
            pre[i] = lower_bound(ends.begin(), ends.begin() + i, e[0]) - ends.begin();
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int p = pre[i - 1];
                dp[i][j] = max(dp[i - 1][j], events[i - 1][2] + dp[p][j - 1]);
            }
        }

        return dp[N][k];
    }
};