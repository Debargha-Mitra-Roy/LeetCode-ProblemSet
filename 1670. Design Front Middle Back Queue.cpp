/*
    1670. Design Front Middle Back Queue :-

    LINK:   https://leetcode.com/problems/design-front-middle-back-queue/
*/

#include <iostream>
#include <vector>
using namespace std;

class FrontMiddleBackQueue
{
private:
    vector<int> q;

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        q.insert(q.begin(), val);
    }

    void pushMiddle(int val)
    {
        q.insert((q.begin() + q.size() / 2), val);
    }

    void pushBack(int val)
    {
        q.push_back(val);
    }

    int popFront()
    {
        if (q.size() == 0)
            return -1;

        int val = q[0];
        q.erase(q.begin());

        return val;
    }

    int popMiddle()
    {

        if (q.size() == 0)
            return -1;

        int val = q[(q.size() - 1) / 2];
        q.erase(q.begin() + (q.size() - 1) / 2);

        return val;
    }

    int popBack()
    {
        if (q.size() == 0)
            return -1;

        int val = q[q.size() - 1];
        q.pop_back();

        return val;
    }
};