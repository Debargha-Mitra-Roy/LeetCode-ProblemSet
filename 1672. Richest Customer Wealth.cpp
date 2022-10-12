/*
    1672. Richest Customer Wealth :-

    LINK:   https://leetcode.com/problems/richest-customer-wealth/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = 0;
        int customerWealth = 0;

        for (int i = 0; i < accounts.size(); i++)
        {
            customerWealth = 0;

            for (int j = 0; j < accounts[i].size(); j++)
            {
                customerWealth += accounts[i][j];
            }

            if (customerWealth > maxWealth)
                maxWealth = customerWealth;
        }

        return maxWealth;
    }
};