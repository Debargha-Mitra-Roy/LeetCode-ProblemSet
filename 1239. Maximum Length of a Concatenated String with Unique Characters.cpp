/*
    1239. Maximum Length of a Concatenated String with Unique Characters :-

    LINK:   https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
    int len{0};

private:
    void checkLen(string str, vector<string> &arr, int itr)
    {
        if (!isUnique(str))
            return;

        if (str.size() > len)
            len = str.size();

        for (int i = itr; i < arr.size(); i++)
        {
            checkLen(str + arr[i], arr, i + 1);
        }
    }

    bool isUnique(string word)
    {
        set<char> st;

        for (auto element : word)
        {
            if (st.find(element) != st.end())
                return false;

            st.insert(element);
        }

        return true;
    }

public:
    int maxLength(vector<string> &arr)
    {
        checkLen("", arr, 0);
        return len;
    }
};