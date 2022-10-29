/*
    2129. Capitalize the Title :-

    LINK:   https://leetcode.com/problems/capitalize-the-title/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        int n = title.length();

        transform(title.begin(), title.end(), title.begin(), ::tolower); // O(N)

        if (n <= 2)
            return title; // base case

        if ((title[2] == ' ' || title[1] == ' ') && n > 1) // if gap after 1 or 2 letter
            title[0] = tolower(title[0]);

        else
            title[0] = toupper(title[0]);

        for (int i = 0; i < n - 3; i++) // O(N)
        {
            if (title[i] == ' ' && (title[i + 2] == ' ' || title[i + 3] == ' '))
                title[i + 1] = tolower(title[i + 1]);

            else if (title[i] == ' ')
                title[i + 1] = toupper(title[i + 1]);
        }

        return title;
    }
};