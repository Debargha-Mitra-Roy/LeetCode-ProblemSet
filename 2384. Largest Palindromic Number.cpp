/*
    2384. Largest Palindromic Number :-

    LINK:   https://leetcode.com/problems/largest-palindromic-number/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string largestPalindromic(string s)
    {
        vector<int> v(10);

        for (char ch : s)
        {
            v[ch - '0']++;
        }

        string ans;

        int single = -1;

        for (int i = 9; i >= 0; i--)
        {
            if (ans.empty() && i == 0)
                continue;

            while (v[i] > 1)
            {
                ans.push_back(i + '0');
                v[i] = v[i] - 2;
            }

            if (v[i] == 1 && single == -1)
                single = i;
        }

        string res = string(ans.rbegin(), ans.rend());

        if (ans.empty() && single == -1)
            return "0";

        if (single != -1)
            ans.push_back(single + '0');

        ans = ans + res;
        
        return ans;
    }
};