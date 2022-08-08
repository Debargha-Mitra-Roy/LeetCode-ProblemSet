/*
    1281. Subtract the Product and Sum of Digits of an Integer :-

    LINK:   https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int product = 1, sum = 0;
        int temp = n, raw = n;

        while (raw != 0)
        {
            product = product * (raw % 10);
            raw = raw / 10;
        }

        while (temp != 0)
        {
            sum = sum + (temp % 10);
            temp = temp / 10;
        }

        int difference = product - sum;

        return difference;
    }
};