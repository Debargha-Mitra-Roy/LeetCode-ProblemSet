/*
    1450. Number of Students Doing Homework at a Given Time :-

    LINK:   https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        // Declare answer variable
        int ans = 0;

        // Constantly check every interval if it contains queryTime
        for (int i = 0; i < startTime.size(); i++)
        {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ans++;
        }

        return ans;
    }
};