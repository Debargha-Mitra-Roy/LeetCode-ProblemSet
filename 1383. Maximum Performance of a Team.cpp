/*
    1383. Maximum Performance of a Team :-

    LINK:   https://leetcode.com/problems/maximum-performance-of-a-team/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
    const int mod = (int)1e9 + 7;

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        // To maintain the heap of size k we will use priority queue
        priority_queue<int, vector<int>, greater<int>> pq;

        // To store the pair of efficiency and speed
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({efficiency[i], speed[i]});
        }

        // Sort in decreasing order of efficiency
        sort(v.rbegin(), v.rend());

        // totalSpeed is the sum of speed of k engineers
        long totalSpeed = 0, ans = 0;

        // Iterate over all engineers
        for (int i = 0; i < n; i++)
        {
            int currEfficiency = v[i].first;
            int currSpeed = v[i].second;

            // If the size of pq is k
            if (pq.size() == k)
            {
                // Remove the minimum speed from the pq
                totalSpeed = totalSpeed - pq.top();
                pq.pop();
            }

            // Push the current speed in the pq
            pq.push(currSpeed);

            // Add the current speed to the totalSpeed
            totalSpeed = totalSpeed + currSpeed;

            // Update the ans
            ans = max(ans, (totalSpeed * currEfficiency));
        }

        return (ans % mod);
    }
};