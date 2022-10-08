/*
    91. Decode Ways :-

    LINK:   https://leetcode.com/problems/decode-ways/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int first = s[0] > '0', second = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            int current = 0;

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                current += second;

            if (s[i] > '0')
                current += first;

            second = first;
            first = current;
        }

        return first;
    }
};