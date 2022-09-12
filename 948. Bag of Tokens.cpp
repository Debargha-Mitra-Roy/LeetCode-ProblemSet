/*
    948. Bag of Tokens :-

    LINK:   https://leetcode.com/problems/bag-of-tokens/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        int i = 0, j = n;

        sort(tokens.begin(), tokens.end());

        while (i < j)
        {
            if (power >= tokens[i])
            {
                power = power - tokens[i];
                i++;
            }

            else if ((i - (n - j)) != 0 && j > (i + 1))
            {
                j--;
                power = power + tokens[j];
            }

            else
                break;
        }

        int ans = i - (n - j);
        return ans;
    }
};