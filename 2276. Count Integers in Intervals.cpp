/*
    2276. Count Integers in Intervals :-

    LINK:   https://leetcode.com/problems/count-integers-in-intervals/
*/

#include <iostream>
#include <map>
using namespace std;

class CountIntervals
{
public:
    map<int, int> mpp;

    int cnt = 0;

    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        auto it = mpp.upper_bound(left);

        if (it != begin(mpp) && prev(it)->second >= left)
            it = prev(it);

        for (; it != end(mpp) && it->first <= right; mpp.erase(it++))
        {
            left = min(left, it->first);
            right = max(right, it->second);

            cnt -= it->second - it->first + 1;
        }

        cnt += right - left + 1;
        mpp[left] = right;
    }

    int count()
    {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */