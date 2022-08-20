/*
    2357. Make Array Zero by Subtracting Equal Amounts :-

    LINK:	https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> st;

        for (auto it : nums)
        {
            if (it != 0)
                st.insert(it);
        }

        return st.size();
    }
};