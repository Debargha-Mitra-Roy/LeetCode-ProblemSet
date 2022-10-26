/*
    1381. Design a Stack With Increment Operation :-

    LINK:   https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/

#include <iostream>
#include <vector>
using namespace std;

class CustomStack
{
    vector<int> arr;
    int n;

public:
    CustomStack(int maxSize)
    {
        n = maxSize;
    }

    void push(int x)
    {
        if (arr.size() < n)
            arr.push_back(x);
    }

    int pop()
    {
        if (arr.size() == 0)
            return -1;

        int temp = arr.back();
        arr.pop_back();

        return temp;
    }

    void increment(int k, int val)
    {
        int i = 0;

        while (k-- && i < arr.size())
        {

            arr[i] += val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */