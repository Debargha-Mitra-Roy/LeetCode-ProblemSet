/*
    1342. Number of Steps to Reduce a Number to Zero

    LINK:   https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        int temp = num;

        if (temp <= 1)
            count = temp;

        else
        {
            while (temp > 0)
            {
                if (temp % 2 != 0)
                {
                    temp = temp - 1;
                    count++;
                }

                else
                {
                    temp = temp / 2;
                    count++;
                }
            }
        }

        return count;
    }
};