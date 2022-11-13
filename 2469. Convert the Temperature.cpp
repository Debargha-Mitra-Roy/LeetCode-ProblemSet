/*
    2469. Convert the Temperature :-

    LINK:   https://leetcode.com/problems/convert-the-temperature/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        double kelvin = celsius + 273.15;
        double fahrenheit = (celsius * 1.80) + 32.00;

        vector<double> ans;
        ans.push_back(kelvin);
        ans.push_back(fahrenheit);

        return ans;
    }
};