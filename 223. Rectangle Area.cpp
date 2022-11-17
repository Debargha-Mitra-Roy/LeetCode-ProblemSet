/*
    223. Rectangle Area :-

    LINK:	https://leetcode.com/problems/rectangle-area/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int areaOfA = (ay2 - ay1) * (ax2 - ax1);
        int areaOfB = (by2 - by1) * (bx2 - bx1);

        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int xOverlap = right - left;

        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int yOverlap = top - bottom;

        int areaOfOverlap = 0;

        if (xOverlap > 0 && yOverlap > 0)
            areaOfOverlap = xOverlap * yOverlap;

        int totalArea = areaOfA + areaOfB - areaOfOverlap;

        return totalArea;
    }
};