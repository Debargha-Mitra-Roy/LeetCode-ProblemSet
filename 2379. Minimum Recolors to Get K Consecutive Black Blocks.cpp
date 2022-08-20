/*
    2379. Minimum Recolors to Get K Consecutive Black Blocks :-

    LINK:   https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int count = 0, flag = 0;

        for (int i = 0; i < blocks.size(); ++i)
        {
            if (blocks[i] == 'B')
                count++;

            if (i >= k)
            {
                if (blocks[i - k] == 'B')
                    count--;
            }

            flag = max(count, flag);
        }

        int ans = (k - flag);

        return ans;
    }
};