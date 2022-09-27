/*
    990. Satisfiability of Equality Equations :-

    LINK:   https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int word[26];

private:
    int find(int x)
    {
        if (word[x] == x)
            return x;
        else
            return (word[x] = find(word[x]));
    }

public:
    bool equationsPossible(vector<string> &equations)
    {
        for (int i = 0; i < 26; ++i)
            word[i] = i;

        for (auto it : equations)
        {
            if (it[1] == '=')
                word[find(it[0] - 'a')] = find(it[3] - 'a');
        }
        
        for (auto it : equations)
        {
            if (it[1] == '!' && find(it[0] - 'a') == find(it[3] - 'a'))
                return false;
        }

        return true;
    }
};