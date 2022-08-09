/*
    151. Reverse Words in a String :-

    LINK:   https://leetcode.com/problems/reverse-words-in-a-string/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        for (int i = 0; i < s.length();)
        {
            int j = i, c = 0;
            
            // c variable finds the spaces before the current word
            while (j < s.length() && s[j] == ' ')
            {
                j++;
                c++;
            }

            // Find the end of the current word
            while (j < s.length() && s[j] != ' ')
            {
                j++;
            }

            // Reverse this current word
            reverse(s.begin() + i, s.begin() + j);

            // Finding the correct positions for the next word as there are extra space which we have to move to the end
            i = j - c + 1;
        }

        // Now removing the extra spaces, these extra spaces will accumulate to the end
        while (!s.empty() && s.back() == ' ')
        {
            s.pop_back();
        }

        // Now just reverse whole string to get the answer
        reverse(s.begin(), s.end());

        return s;
    }
};