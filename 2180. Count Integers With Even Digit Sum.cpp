/*
    2180. Count Integers With Even Digit Sum :-

    LINK:   https://leetcode.com/problems/count-integers-with-even-digit-sum/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int countEven(int num) {

        int count = 0, n = num, sum = 0;;

        while (n > 0)
        {
            int rem = n % 10;
            sum  = sum + rem;
            n = n / 10;
        }

        if (sum % 2 == 0)
            count = num / 2;

        else
            count = (num - 1) / 2;

        return count;
    }
};