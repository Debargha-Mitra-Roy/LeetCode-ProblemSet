/*
    2381. Shifting Letters II :-

    LINK:   https://leetcode.com/problems/shifting-letters-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int line[50001] = {};

        for (auto &shift : shifts)
        {
            line[shift[0]] += shift[2] ? 1 : -1;
            line[shift[1] + 1] += shift[2] ? -1 : 1;
        }

        for (int i = 0, val = 0; i < s.size(); i++)
        {
            val = (val + line[i]) % 26;
            s[i] = 'a' + (26 + (s[i] - 'a') + val) % 26;
        }

        return s;
    }
};