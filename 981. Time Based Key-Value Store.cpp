/*
    981. Time Based Key-Value Store :-

    LINK:   https://leetcode.com/problems/time-based-key-value-store/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        string ans = "";

        pair<int, string> p = make_pair(timestamp, "");

        auto it = lower_bound(mpp[key].begin(), mpp[key].end(), p);

        if (it - mpp[key].begin() < mpp[key].size())
        {
            if (it == mpp[key].begin() and (*it).first == timestamp)
                ans = (*it).second;

            else if (it - mpp[key].begin() > 0)
            {
                if ((*it).first == timestamp)
                    ans = (*it).second;

                else
                {
                    it--;
                    ans = (*it).second;
                }
            }
        }

        else
        {
            if (mpp[key].size())
            {
                it--;
                ans = (*it).second;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */