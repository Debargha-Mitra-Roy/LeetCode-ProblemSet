/*
    709. To Lower Case :-

    LINK:   https://leetcode.com/problems/to-lower-case/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};