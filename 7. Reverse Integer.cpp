/*
	7. Reverse Integer :-

	LINK:	https://leetcode.com/problems/reverse-integer/
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0, digit;

        while (x != 0)
        {
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;

            digit = x % 10;
            ans = (ans * 10) + digit;
            x = x / 10;
        }

        return ans;
    }
};