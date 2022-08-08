/*
    2160. Minimum Sum of Four Digit Number After Splitting Digits :-

    LINK:   https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumSum(int num)
    {
        vector<int> v;

        while (num > 0)
        {
            int rem = num % 10;

            v.push_back(rem);

            num = num / 10;
        }

        sort(v.begin(), v.end());

        int first = (v[0] * 10) + v[2];
        int second = (v[1] * 10) + v[3];

        int ans = (first + second);

        return ans;
    }
};