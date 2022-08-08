/*
    2177. Find Three Consecutive Integers That Sum to a Given Number :-

    LINK:   https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long int> sumOfThree(long long int num)
    {
        vector<long long int> temp;

        long long int mid = num / 3;
        long long int left = mid - 1;
        long long int right = mid + 1;

        long long int total = left + mid + right;

        if (total == num)
        {
            temp.push_back(left);
            temp.push_back(mid);
            temp.push_back(right);
        }

        return temp;
    }
};
