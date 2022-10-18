/*
    412. Fizz Buzz :-

    LINK:   https://leetcode.com/problems/fizz-buzz/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;

        for (int i = 1; i <= n; i++)
        {
            bool divisibleBy3 = i % 3;
            bool divisibleBy5 = i % 5;

            // If divisible by both 3 & 5
            if (!divisibleBy3 && !divisibleBy5)
                ans.push_back("FizzBuzz");

            // If divisible by 3
            else if (!divisibleBy3)
                ans.push_back("Fizz");

            // If divisible by 5
            else if (!divisibleBy5)
                ans.push_back("Buzz");

            else
                ans.push_back(to_string(i));
        }

        return ans;
    }
};