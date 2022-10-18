/*
    1656. Design an Ordered Stream :-

    LINK:   https://leetcode.com/problems/design-an-ordered-stream/
*/

#include <iostream>
#include <vector>
using namespace std;

class OrderedStream
{
public:
    vector<string> stream;

    int i = 0;

    OrderedStream(int n)
    {
        stream.resize(n);
    }

    vector<string> insert(int idKey, string value)
    {
        vector<string> res;
        stream[idKey - 1] = value;

        while (i < stream.size() && stream[i] != "")
        {
            res.push_back(stream[i]);
            i++;
        }

        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */