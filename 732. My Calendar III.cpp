/*
    732. My Calendar III :-

    LINK:   https://leetcode.com/problems/my-calendar-iii/
*/

#include <iostream>
#include <map>
using namespace std;

class MyCalendarThree
{
public:
    map<int, int> mapping;

    int maximum = 0;
    
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        int count = 0;

        mapping[start]++;
        mapping[end]--;

        for (auto it = mapping.begin(); it != mapping.end(); it++)
        {
            count += it->second;
            maximum = max(maximum, count);
        }

        return maximum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */