/*
    899. Orderly Queue :-

    LINK:   https://leetcode.com/problems/orderly-queue/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }

        else
        {
            string ans = s;

            for (int i = 1; i < s.size(); i++)
            {
                ans = min(ans, s.substr(i, s.size() - 1) + s.substr(0, i));
            }

            return ans;
        }
    }
};