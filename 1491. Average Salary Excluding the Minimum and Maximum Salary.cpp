/*
    1491. Average Salary Excluding the Minimum and Maximum Salary :-

    LINK:   https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end()); // Sort the salary array

        salary.pop_back(); // Delete the maximum salary

        reverse(salary.begin(), salary.end()); // Reverse the salary array

        salary.pop_back(); // Delete the minimum salary

        double sum = 0; // Initialize sum with zero

        for (int i = 0; i < salary.size(); i++)
        {
            sum = sum + salary[i]; // Sum of the rest salaries
        }

        double avg = (sum / salary.size()); // Avarage value of the rest salaries

        return avg;
    }
};