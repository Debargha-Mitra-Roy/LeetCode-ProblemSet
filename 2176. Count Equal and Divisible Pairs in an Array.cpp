/*
    2176. Count Equal and Divisible Pairs in an Array :-

    LINK:   https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i * j % k == 0 && nums[i] == nums[j])
                    count++;
            }
        }

        return count;
    }
};