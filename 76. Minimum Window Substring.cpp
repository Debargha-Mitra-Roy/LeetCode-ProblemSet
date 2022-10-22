/*
    76. Minimum Window Substring :-

    LINK:   https://leetcode.com/problems/minimum-window-subsing/
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int len1 = s.length();
        int len2 = t.length();

        const int no_of_chars = 256;

        if (len1 < len2)
            return "";

        int hashMap_t[no_of_chars] = {0};
        int hashMap_s[no_of_chars] = {0};

        for (int i = 0; i < len2; i++)
        {
            hashMap_t[t[i]]++;
        }

        int start = 0, start_index = -1, min_len = INT_MAX, count = 0;

        for (int j = 0; j < len1; j++)
        {
            hashMap_s[s[j]]++;

            if (hashMap_s[s[j]] <= hashMap_t[s[j]])
                count++;

            if (count == len2)
            {
                while (hashMap_s[s[start]] > hashMap_t[s[start]] || hashMap_t[s[start]] == 0)
                {
                    if (hashMap_s[s[start]] > hashMap_t[s[start]])
                        hashMap_s[s[start]]--;

                    start++;
                }

                int len_window = j - start + 1;

                if (min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        if (start_index == -1)
            return "";

        return s.substr(start_index, min_len);
    }
};