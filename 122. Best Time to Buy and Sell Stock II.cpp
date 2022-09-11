/*
    122. Best Time to Buy and Sell Stock II :-

    LINK:   https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int profit = 0;
        int min = prices[0];

        for (int i = 0; i < n; i++)
        {
            if (min > prices[i])
                min = prices[i];

            if (prices[i] - min > profit)
                profit = prices[i] - min;
        }

        return profit;
    }
};