/*
    1323. Maximum 69 Number :-

    LINK:   https://leetcode.com/problems/maximum-69-number/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        string str = to_string(num);
        int n = str.size();

        for (int i = 0; i < n;)
        {
            if (str[i] == '6')
            {
                str[i] = '9';
                break;
            }

            else
                i++;
        }

        int ans = stoi(str);
        return ans;
    }
};