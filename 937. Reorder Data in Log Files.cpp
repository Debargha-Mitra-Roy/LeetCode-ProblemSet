/*
    937. Reorder Data in Log Files :-

    LINK:   https://leetcode.com/problems/reorder-data-in-log-files/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool isdigitlog(string &s)
    {
        return (s.back() >= '0' && s.back() <= '9');
    }

    static bool comp(string s1, string s2)
    {
        string t1, t2;

        t1 = s1.substr(s1.find(' '));
        t2 = s2.substr(s2.find(' '));

        if (t1 == t2)
            return s1 < s2;

        return (t1 < t2);
    }

public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> digit, ans;

        int n = logs.size();

        for (int i = 0; i < n; i++)
        {
            if (isdigitlog(logs[i]))
                digit.push_back(logs[i]);

            else
                ans.push_back(logs[i]);
        }

        sort(ans.begin(), ans.end(), comp);

        for (string s : digit)
        {
            ans.push_back(s);
        }

        return ans;
    }
};