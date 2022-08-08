/*
    9. Palindrome Number :-

    LINK:   https://leetcode.com/problems/palindrome-number/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        long long int temp = x;
        long long int reverse = 0;

        while (temp != 0)
        {
            long long int rem = temp % 10;
            reverse = (reverse * 10) + rem;
            temp = temp / 10;
        }

        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        else
        {
            if (x == reverse)
                return true;

            else
                return false;
        }
    }
};