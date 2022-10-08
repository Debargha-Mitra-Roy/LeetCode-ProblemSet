/*
    731. My Calendar II :-

    LINK:   https://leetcode.com/problems/my-calendar-ii/
*/

#include <iostream>
#include <map>
using namespace std;

class MyCalendarTwo
{
private:
    map<int, int> mpp;

    bool canAdd(int n)
    {
        int count = 0;

        for (auto entry : mpp)
        {
            count += entry.second;

            if (count > n)
                return false;
        }

        return true;
    }

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        mpp[start]++;
        mpp[end]--;

        if (canAdd(2))
            return true;

        else
        {
            mpp[start]--;
            mpp[end]++;

            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */