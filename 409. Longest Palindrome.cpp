/*
    409. Longest Palindrome :-

    LINK:   https://leetcode.com/problems/longest-palindrome/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> hashMap;

        for (char ch : s)
        {
            hashMap[ch]++;
        }

        int ans = 0;

        for (auto it : hashMap)
        {
            ans += it.second / 2 * 2;

            if (ans % 2 == 0 && it.second % 2 == 1)
                ans++;
        }

        return ans;
    }
};