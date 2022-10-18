/*
    1832. Check if the Sentence Is Pangram :-

    LINK:   https://leetcode.com/problems/check-if-the-sentence-is-pangram/
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        return unordered_set<char>(sentence.begin(), sentence.end()).size() == 26;
    }
};