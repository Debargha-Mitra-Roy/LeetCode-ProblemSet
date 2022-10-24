/*
    1980. Find Unique Binary String :-

    LINK:   https://leetcode.com/problems/find-unique-binary-string/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    string ans;

private:
    void solve(unordered_set<string> &st, string str, int len)
    {
        if (len == 0)
        {
            if (st.find(str) == st.end())
                ans = str;

            return;
        }

        if (ans.length() == 0)
            solve(st, str + '0', len - 1);

        if (ans.length() == 0)
            solve(st, str + '1', len - 1);
    }

public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<string> st;

        ans = "";
        int len = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        len = nums[0].length();

        string str = "";
        solve(st, str, len);

        return ans;
    }
};