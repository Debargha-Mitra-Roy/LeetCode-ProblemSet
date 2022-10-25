/*
    2060. Check if an Original String Exists Given Two Encoded Strings :-

    LINK:   https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    bool memo[50][50][2000];

    bool comp_seqs(string &s1, string &s2, int i1, int i2, int diff)
    {
        // Check true condition
        if (i1 == s1.size() && i2 == s2.size())
            return diff == 0;

        // Add 1000 to 'diff' be in range [0, 2000)
        bool &ret = memo[i1][i2][diff + 1000];

        if (ret)
            return false; // Immediately return

        ret = true; // Check visited

        // (diff > 0) or (diff < 0) checking to ensure the diff always be in range (-1000, 1000) in the case that s1[i1] is a digit
        if (diff >= 0 && i1 < s1.size() && s1[i1] <= '9')
        {
            int num1 = 0;

            // Loop maximum 3 consecutive digits
            for (int i = 0; i < min(3, (int)s1.size() - i1); i++)
            {
                if (s1[i1 + i] > '9')
                    break;

                num1 = num1 * 10 + s1[i1 + i] - '0';

                if (comp_seqs(s1, s2, i1 + i + 1, i2, diff - num1))
                    return true;
            }
        }

        // In the case that s2[i2] is a digit
        else if (diff <= 0 && i2 < s2.size() && s2[i2] <= '9')
        {
            int num2 = 0;

            for (int i = 0; i < min(3, (int)s2.size() - i2); i++)
            {
                if (s2[i2 + i] > '9')
                    break;

                num2 = num2 * 10 + s2[i2 + i] - '0';

                if (comp_seqs(s1, s2, i1, i2 + i + 1, diff + num2))
                    return true;
            }
        }

        else if (diff == 0)
        {
            if (i1 >= s1.size() || i2 >= s2.size() || s1[i1] != s2[i2]) // Reject infeasible cases
                return false;

            return comp_seqs(s1, s2, i1 + 1, i2 + 1, 0);
        }

        else if (diff > 0)
        {
            if (i1 >= s1.size()) // Reject infeasible cases
                return false;

            return comp_seqs(s1, s2, i1 + 1, i2, diff - 1);
        }

        else
        {
            if (i2 >= s2.size()) // Reject infeasible cases
                return false;

            return comp_seqs(s1, s2, i1, i2 + 1, diff + 1);
        }

        return false;
    }

public:
    bool possiblyEquals(string s1, string s2)
    {
        return comp_seqs(s1, s2, 0, 0, 0);
    }
};