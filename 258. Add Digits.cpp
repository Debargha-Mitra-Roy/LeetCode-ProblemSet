/*
    258. Add Digits :-

    LINK:   https://leetcode.com/problems/add-digits/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {

        int count = 0;

        while (num != 0)
        {
            int rem = num % 10;

            count = count + rem;

            num = num / 10;
        }

        if (count < 10)
            return count;

        else
            return addDigits(count);
    }
};