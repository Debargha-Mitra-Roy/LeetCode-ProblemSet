/*
    658. Find K Closest Elements :-

    LINK:   https://leetcode.com/problems/find-k-closest-elements/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : arr)
        {
            pq.push({abs(it - x), it});
        }

        vector<int> ans;
        
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};