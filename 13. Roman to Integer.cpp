/*
    13. Roman to Integer :-

    LINK:	https://leetcode.com/problems/roman-to-integer/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int values(char ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }

        return 0;
    }

public:
    int romanToInt(string s)
    {
        vector<int> arr;
        
        for (char ch : s)
        {
            arr.push_back(values(ch));
        }

        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
                ans = ans + arr[i]; // Roman numerals are usually written largest to smallest from left to right, thus add to net sum

            else
                ans = ans - arr[i]; // When they aren't we will subtract that number from net sum
        }

        ans = ans + arr[n - 1];
        return ans;
    }
};