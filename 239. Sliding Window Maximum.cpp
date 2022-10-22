/*
    239. Sliding Window Maximum :-

    LINK:   https://leetcode.com/problems/sliding-window-maximum/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> v;
        map<int, int> m;

        int i;

        if (k == 1)
            return nums;

        // First k elements(first window).
        for (i = 0; i < k; i++)
        {
            m[nums[i]]++;
        }

        auto it = m.end();
        it--;
        v.push_back(it->first);

        for (i = 1; i < nums.size() - k + 1; i++)
        {
            // Decreasing count of element exiting the window.
            m[nums[i - 1]]--;

            // Make sure to remove the element form the map whose count == 0
            if (m[nums[i - 1]] == 0)
                m.erase(nums[i - 1]);

            // Increasing count of element entering the window.
            m[nums[i + k - 1]]++;

            // Retrieving the last element in the map(it would be the largest for that window).
            auto it = m.end();
            it--;
            v.push_back(it->first);
        }

        return v;
    }
};