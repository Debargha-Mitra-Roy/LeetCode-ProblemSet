/*
    506. Relative Ranks :-

    LINK:   https://leetcode.com/problems/relative-ranks/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();

        unordered_map<int, int> mpp;
        vector<string> ans(score.size());

        for (int i = 0; i < score.size(); i++)
        {
            mpp[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>());

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans[mpp[score[i]]] = "Gold Medal";

            else if (i == 1)
                ans[mpp[score[i]]] = "Silver Medal";

            else if (i == 2)
                ans[mpp[score[i]]] = "Bronze Medal";

            else
                ans[mpp[score[i]]] = to_string(i + 1);
        }

        return ans;
    }
};