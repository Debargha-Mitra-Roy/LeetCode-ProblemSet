/*
    167. Two Sum II - Input Array Is Sorted :-

    LINK:   https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0, high = numbers.size() - 1;

        while (numbers[low] + numbers[high] != target)
        {
            if (numbers[low] + numbers[high] < target)
                low++;

            else
                high--;
        }
        
        return vector<int>({low + 1, high + 1});
    }
};