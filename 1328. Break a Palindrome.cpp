/*
    1328. Break a Palindrome :-

    LINK:   https://leetcode.com/problems/break-a-palindrome/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();

        // If there is only one character we will return empty string
        if (n == 1)
            return "";

        for (int i = 0; i < n; i++)
        {
            // If its a odd string we have to change middle element by 'a'
            if (n % 2 != 0 && i == n / 2)
                continue;

            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                break;
            }

            // If it would be type of string with all letter as 'a' or same repetitive letter we will turn it b
            else if (i == n - 1)
                palindrome[i] = 'b';
        }

        return palindrome;
    }
};