/*
    1910. Remove All Occurrences of a Substring :-

    LINK:   https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.size() != 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.size());
        }

        return s;
    }
};