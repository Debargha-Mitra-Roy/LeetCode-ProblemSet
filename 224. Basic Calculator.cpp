/*
    224. Basic Calculator :-

    LINK:	https://leetcode.com/problems/basic-calculator/
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> nums;
        int answer = 0;
        long long current_val = 0, sign = 1;

        for (char c : s)
        {
            if (isdigit(c))
                current_val = 10 * current_val + c - '0';

            else if (c == '+')
            {
                answer += current_val * sign;
                current_val = 0;
                sign = 1;
            }

            else if (c == '-')
            {
                answer += current_val * sign;
                current_val = 0;
                sign = -1;
            }

            else if (c == '(')
            {
                nums.push(answer);
                nums.push(sign);
                answer = 0;
                sign = 1;
            }

            else if (c == ')')
            {
                answer += current_val * sign;
                current_val = 0;
                answer = answer * nums.top();
                nums.pop();
                answer = answer + nums.top();
                nums.pop();
            }
        }

        answer += current_val * sign;
        return answer;
    }
};