/*
    2259. Remove Digit From Number to Maximize Result :-

    LINK:   https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        for (int i = 0; i < number.size() - 1; i++)
        {
            if (number[i] == digit && number[i] < number[i + 1])
                return number.erase(i, 1);
        }

        return (number.erase(number.find_last_of(digit), 1));
    }
};