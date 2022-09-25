/*
    641. Design Circular Deque :-

    LINK:   https://leetcode.com/problems/design-circular-deque/
*/

#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque
{
public:
    vector<int> dq;
    int size;

    MyCircularDeque(int k)
    {
        size = k;
    }

    bool insertFront(int value)
    {
        if (dq.size() == size)
            return false;

        dq.insert(dq.begin(), value);
        return true;
    }

    bool insertLast(int value)
    {
        if (dq.size() == size)
            return false;

        dq.push_back(value);
        return true;
    }

    bool deleteFront()
    {
        if (dq.size() == 0)
            return false;
        dq.erase(dq.begin());
        return true;
    }

    bool deleteLast()
    {
        if (dq.size() == 0)
            return false;

        dq.pop_back();
        return true;
    }

    int getFront()
    {
        return dq.size() == 0 ? -1 : dq[0];
    }

    int getRear()
    {
        if (dq.size() == 0)
            return -1;

        return dq[dq.size() - 1];
    }

    bool isEmpty()
    {
        return (dq.size() == 0);
    }

    bool isFull()
    {
        return (dq.size() == size);
    }
};
