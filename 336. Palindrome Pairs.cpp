/*
    287. Find the Duplicate Number :-

    LINK:   https://leetcode.com/problems/find-the-duplicate-number/
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    inline bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r && s[l] == s[r])
        {
            l++;
            r--;
        }

        return (l >= r);
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        // Groups of words sorted by size
        map<int, unordered_map<string, int>> mpp;
        
        for (int i = 0; i < words.size(); i++)
        {
            mpp[words[i].size()][string(words[i].rbegin(), words[i].rend())] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++)
        {
            auto w = words[i];

            for (auto &[k, m] : mpp)
            {
                if (k > w.size())
                    break;

                // Same length word, add only once, for other word will add again as well
                if (k == w.size())
                {
                    if (m.count(w) && m[w] != i)
                        ans.push_back({i, m[w]});

                    break;
                }

                // Check back
                if (isPalindrome(w, k, w.size() - 1))
                {
                    auto target = w.substr(0, k);

                    if (m.count(target))
                        ans.push_back({i, m[target]});
                }

                // Check front
                if (isPalindrome(w, 0, w.size() - k - 1))
                {
                    auto target = w.substr(w.size() - k);

                    if (m.count(target))
                        ans.push_back({m[target], i});
                }
            }
        }

        return ans;
    }
};