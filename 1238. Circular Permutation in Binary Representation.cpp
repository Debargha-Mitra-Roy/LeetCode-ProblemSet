/*
    1238. Circular Permutation in Binary Representation :-

    LINK:   https://leetcode.com/problems/circular-permutation-in-binary-representation/
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
    vector<int> res;
    vector<bool> used;

private:
    int change_ith(int num, int pos)
    {
        int mask = (1 << pos);
        return (num ^ mask);
    }

    bool backtrack(int n, int num)
    {
        if (res.size() == n)
            return true;

        for (int i = 0; i < 31; i++)
        {
            int temp = change_ith(num, i);

            if (temp < n && !used[temp])
            {
                used[temp] = true;
                res.push_back(temp);

                if (backtrack(n, temp))
                    return true;

                used[temp] = false;
                res.pop_back();
            }
        }

        return false;
    }

public:
    vector<int> circularPermutation(int n, int start)
    {
        n = pow(2, n);

        used.assign(n, 0);
        used[start] = 1;

        res.push_back(start);
        backtrack(n, start);
        
        return res;
    }
};