/*
    119. Pascal's Triangle II :-

    LINK:   https://leetcode.com/problems/pascals-triangle-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1);

        ans[0] = ans[rowIndex] = 1;
        long long int temp = 1;
        int up = rowIndex, down = 1;

        for (int i = 1; i < rowIndex; i++)
        {
            temp = temp * up / down;
            ans[i] = temp;
            up--;
            down++;
        }
        
        return ans;
    }
};