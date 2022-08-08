/*
    20. Valid Parentheses :-

    LINK:   https://leetcode.com/problems/valid-parentheses/
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            else
            {
                if (!st.empty())
                {
                    char top = st.top();

                    if ((s[i] == ')' && top == '(') || (s[i] == '}' && top == '{') || (s[i] == ']' && top == '['))
                        st.pop();

                    else
                        return false;
                }

                else
                    return false;
            }
        }

        if (st.empty())
            return true;

        else
            return false;
    }
};