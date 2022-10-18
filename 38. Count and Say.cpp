/*
    38. Count and Say :-

    LINK:   https://leetcode.com/problems/count-and-say/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        // Base Case
        if (n == 1)
            return "1";

        if (n == 2)
            return "11";

        // Take a string equals 11
        string str = "11";

        // Now we need the value of nth term so we loop from 3 -> n
        for (int i = 3; i <= n; i++)
        {
            // Temp will have the ans of the next iteration i.e value of the next ith data
            string temp = "";
            str = str + "&"; // Add a delimeter at the end
            int count = 1;   // Counter

            // Now loop from 1st value to last value
            for (int j = 1; j < str.length(); j++)
            {
                // This condition should be satisfied, if not that means new number has started occurring
                if (str[j] != str[j - 1])
                {
                    temp = temp + to_string(count); // Add the counter to temp
                    temp = temp + str[j - 1];       // Add the data of the counter
                    count = 1;                      // Reset the counter to 1
                }

                else
                    count++; // Just count the freq of that number
            }

            // After one complete traversal, make str equal to temp;
            str = temp;
        }

        return str;
    }
};