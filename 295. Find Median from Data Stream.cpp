/*
    295. Find Median from Data Stream :-

    LINK:   https://leetcode.com/problems/find-median-from-data-stream/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> firstPQ;                             // max_heap for the first half
    priority_queue<int, vector<int>, greater<int>> secondPQ; // min_heap for the second half

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (firstPQ.empty() || (firstPQ.top() > num))
            firstPQ.push(num); // if it belongs to the smaller half
        else
            secondPQ.push(num);

        // Rebalance the two halfs to make sure the length difference is no larger than 1
        if (firstPQ.size() > (secondPQ.size() + 1))
        {
            secondPQ.push(firstPQ.top());
            firstPQ.pop();
        }

        else if (firstPQ.size() + 1 < secondPQ.size())
        {
            firstPQ.push(secondPQ.top());
            secondPQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if (firstPQ.size() == secondPQ.size())
            return firstPQ.empty() ? 0 : ((firstPQ.top() + secondPQ.top()) / 2.0);

        else
            return (firstPQ.size() > secondPQ.size()) ? firstPQ.top() : secondPQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */