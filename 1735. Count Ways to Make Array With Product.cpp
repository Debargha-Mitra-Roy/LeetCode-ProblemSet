/*
    1735. Count Ways to Make Array With Product :-

    LINK:   https://leetcode.com/problems/count-ways-to-make-array-with-product/
*/

#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

class Solution
{
private:
    // calculating combinatorics
    long long int comb(int n, int m)
    {
        static long long int c[20001][10001] = {0};
        if (c[n][m] != 0)
            return c[n][m];

        long long int res;

        if (m == 0 || m == n)
            res = 1;

        else
            res = (comb(n - 1, m) + comb(n - 1, m - 1)) % MOD;

        c[n][m] = res;
        return res;
    }

public:
    vector<int> waysToFillArray(vector<vector<int>> &queries)
    {
        vector<int> factors;
        vector<int> res;

        for (int i = 0; i < queries.size(); i++)
        {
            factors.clear();

            for (int j = 2; j <= 97; j++)
            {
                if (queries[i][1] % j == 0)
                {
                    int count = 0;

                    while (queries[i][1] % j == 0)
                    {
                        count++;
                        queries[i][1] /= j;
                    }

                    factors.push_back(count);
                }
            }

            if (queries[i][1] != 1)
                factors.push_back(1);

            // Calculate ways
            int tmp = 1;

            for (int f : factors)
            {
                tmp = (tmp * comb(f + queries[i][0] - 1, queries[i][0] - 1)) % MOD;
            }

            res.push_back(tmp);
        }

        return res;
    }
};