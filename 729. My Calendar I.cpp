/*
    732. My Calendar I :-

    LINK:   https://leetcode.com/problems/my-calendar-i/
*/

#include <iostream>
#include <map>
using namespace std;

class MyCalendar
{
public:
    map<int, int> events;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto next = events.upper_bound(start);

        if (next != events.end() && (*next).second < end)
            return false;

        events.insert({end, start});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */