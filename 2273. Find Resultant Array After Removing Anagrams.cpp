/*
    2273. Find Resultant Array After Removing Anagrams :-

    LINK:   https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool isAnagram(string p, string q)
    {
        vector<int> count(26);
        int res = 0;

        for (auto i : p)
        {
            count[i - 'a']++;
        }

        for (auto i : q)
        {
            count[i - 'a']--;
        }

        for (auto i : count)
        {
            if (i != 0)
                return false;
        }

        return true;
    }

public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;

        int n = words.size();

        for (int i = 0; i < n;)
        {
            int j = i + 1;

            while (j < n && isAnagram(words[i], words[j]))
            {
                j++;
            }

            ans.push_back(words[i]);
            i = j;
        }

        return ans;
    }
};