/*
    567. Permutation in String :-

    LINK:   https://leetcode.com/problems/permutation-in-string/
*/

#include <iostream>
using namespace std;

class Solution
{
private:
    bool checkEqual(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int count1[26] = {0};

        // Count the character array
        for (int i = 0; i < s1.size(); i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // Traverse s2 string in window of size s1 length and compare
        int i = 0;
        int windowSize = s1.size();
        int count2[26] = {0};

        // Running for first window
        while (i < windowSize && i < s2.size())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if (checkEqual(count1, count2))
            return true;

        // Move ahead the window process
        while (i < s2.size())
        {
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;
            i++;

            if (checkEqual(count1, count2))
                return true;
        }

        return false;
    }
};