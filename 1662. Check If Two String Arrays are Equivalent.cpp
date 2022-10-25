/*
    1662. Check If Two String Arrays are Equivalent :-

    LINK:   https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string str1 = "", str2 = "";

        for (auto it : word1)
        {
            str1 = str1 + it;
        }

        for (auto it : word2)
        {
            str2 = str2 + it;
        }

        if (str1 == str2)
            return true;

        else
            return false;
    }
};