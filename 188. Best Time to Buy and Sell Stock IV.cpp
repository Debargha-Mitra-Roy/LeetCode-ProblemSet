/*
    188. Best Time to Buy and Sell Stock IV :-
    
    LINK:   https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        int length = 2 * k + 1;

        vector<int> dp(length, INT_MIN);

        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 2 * k - 2; j = j + 2)
            {
                dp[j + 1] = max(dp[j + 1], (dp[j] - prices[i]));
                dp[j + 2] = max(dp[j + 2], (dp[j + 1] + prices[i]));
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};