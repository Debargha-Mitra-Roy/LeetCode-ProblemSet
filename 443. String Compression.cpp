/*
    443. String Compression :-

    LINK:   https://leetcode.com/problems/string-compression/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while (i < n)
        {
            int j = i + 1;

            while (j < n && chars[i] == chars[j])
            {
                j++;
            }

            // Store the old characters
            chars[ansIndex++] = chars[i];

            int count = j - i;

            if (count > 1)
            {
                // Converting counting into single digit & solvinf=g in answer
                string temp = to_string(count);

                for (char ch : temp)
                {
                    chars[ansIndex++] = ch;
                }
            }

            // Moving to new / different character
            i = j;
        }

        return ansIndex;
    }
};