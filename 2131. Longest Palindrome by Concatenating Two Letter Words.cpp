/*
    2131. Longest Palindrome by Concatenating Two Letter Words :-

    LINK:   https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> count;

        for (const string &word : words)
        {
            count[word]++;
        }

        int answer = 0;
        bool central = false;

        for (const auto &[word, countOfTheWord] : count)
        {
            // If the word is a palindrome
            if (word[0] == word[1])
            {
                if (countOfTheWord % 2 == 0)
                    answer += countOfTheWord;

                else
                {
                    answer += countOfTheWord - 1;
                    central = true;
                }
            }

            // Consider a pair of non-palindrome words such that one is the reverse of another ({word[1], word[0]} is the reversed word)
            else if (word[0] < word[1] && count.count({word[1], word[0]}))
                answer += 2 * min(countOfTheWord, count[{word[1], word[0]}]);
        }

        if (central)
            answer++;

        return (2 * answer);
    }
};