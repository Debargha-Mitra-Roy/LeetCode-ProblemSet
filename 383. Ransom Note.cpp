/*
    383. Ransom Note :-

    LINK:   https://leetcode.com/problems/ransom-note/
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ransomNoteMap, magazineMap;

        for (auto it : ransomNote)
        {
            ransomNoteMap[it]++;
        }

        for (auto it : magazine)
        {
            magazineMap[it]++;
        }

        for (auto it : ransomNoteMap)
        {
            if (magazineMap[it.first] < it.second)
                return false;
        }

        return true;
    }
};