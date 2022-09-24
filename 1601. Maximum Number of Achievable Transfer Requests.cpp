/*
    1601. Maximum Number of Achievable Transfer Requests :-

    LINK:   https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int ans = 0;

    bool isValid(vector<int> &building)
    {
        for (int i = 0; i < building.size(); i++)
        {
            if (building[i] != 0)
                return false;
        }

        return true;
    }

    void helper(vector<int> &building, vector<vector<int>> &requests, int ri, int cnt)
    {
        // Capture served requests if we are satisfying the building criteria
        if (isValid(building))
            ans = max(ans, cnt);

        // No point of recurring further if we already have served more number of requests
        if (ans >= cnt + requests.size() - ri)
            return;
        // Base Case
        if (ri == requests.size())
            return;

        // Include
        building[requests[ri][0]]--;
        building[requests[ri][1]]++;
        helper(building, requests, ri + 1, cnt + 1);

        // Exclude
        building[requests[ri][0]]++;
        building[requests[ri][1]]--;
        helper(building, requests, ri + 1, cnt);
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<int> building(n, 0);
        helper(building, requests, 0, 0);
        return ans;
    }
};