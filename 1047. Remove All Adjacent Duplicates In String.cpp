/*
    1047. Remove All Adjacent Duplicates In String :-

    LINK:   https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]); // Initially if the stack is empty (to avoid segmentation fault)
                continue;
            }

            else
            {
                if (st.top() == s[i])
                    st.pop();

                else
                    st.push(s[i]);
            }
        }

        // Popping out remaining elements and storing them to the string
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // Reversing the string because stack reversed the string while popping.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};