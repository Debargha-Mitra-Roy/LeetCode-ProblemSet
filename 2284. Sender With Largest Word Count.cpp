/*
    2284. Sender With Largest Word Count :-

    LINK:   https://leetcode.com/problems/sender-with-largest-word-count/
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        int n = messages.size();

        map<string, int> mpp;

        for (auto i = 0; i < n; i++)
        {
            stringstream ss(messages[i]);
            string word;
            int count = 0;

            while (ss >> word)
            {
                count++;
            }

            mpp[senders[i]] += count;
        }

        int count = 0;
        string res;

        for (auto &it : mpp)
        {
            if (it.second >= count)
            {
                count = it.second;

                if (!res.empty() || res < it.first)
                    res = it.first;
            }
        }

        return res;
    }
};