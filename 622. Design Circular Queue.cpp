/*
    622. Design Circular Queue :-

    LINK:   https://leetcode.com/problems/design-circular-queue/
*/

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
    vector<int> q;
    int size, count, headIndex;

public:
    MyCircularQueue(int k)
    {
        q.resize(k);   // The queue holding the elements in a circular queue
        count = 0;     // The number of elements in a circular queue
        headIndex = 0; // Head index of the head element
        size = k;      // Size of the queue
    }

    bool enQueue(int value)
    {
        // If the queue is full
        if (isFull())
            return false;

        int index = (headIndex + count) % size;
        q[index] = value;
        count++;

        return true;
    }

    bool deQueue()
    {
        // If the queue is empty
        if (isEmpty())
            return false;

        headIndex = (headIndex + 1) % size;
        count--;

        return true;
    }

    int Front()
    {
        // If the queue is empty
        if (isEmpty())
            return -1;

        return q[headIndex];
    }

    int Rear()
    {
        // If the queue is empty
        if (isEmpty())
            return -1;

        int tailIndex = (headIndex + count - 1) % size;
        return q[tailIndex];
    }

    bool isEmpty()
    {
        return (count == 0); // No element in the queue
    }

    bool isFull()
    {
        return (count == size); // If the queue is full
    }
};