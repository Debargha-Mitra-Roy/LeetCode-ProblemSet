/*
    393. UTF-8 Validation :-

    LINK:   https://leetcode.com/problems/utf-8-validation/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int remaining = 0; // Used to track the remaining number of segments

        // Iterate each data and perform the following logic
        for (auto &x : data)
        {
            // Case 1: there is no remaining segement left,
            if (remaining == 0)
            {
                // Case 1.1 - shift `x` 5 bits to the right
                if ((x >> 5) == 0b110)
                    remaining = 1;

                // Case 1.2 -  shift `x` 4 bits to the right
                else if ((x >> 4) == 0b1110)
                    remaining = 2;

                // Case 1.3 -  shift `x` 3 bits to the right
                else if ((x >> 3) == 0b11110)
                    remaining = 3;

                // Case 1.4 -  shift `x` 7 bits to the right
                else if ((x >> 7) != 0)
                    return false;
            }

            // Case 2: check 10xxxxxx
            else
            {
                // If the first 2 bits are not 10 (in binary format), then it is not valid
                if ((x >> 6) != 0b10)
                    return false;

                // Otherwise, this segement is ok so we decrease `remaining` by 1
                else
                    remaining--;
            }
        }

        // At the end, remaining will be 0 if data can represent the octet sequence
        return (remaining == 0);
    }
};