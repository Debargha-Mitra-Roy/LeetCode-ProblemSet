/*
    374. Guess Number Higher or Lower :-

    LINK:   https://leetcode.com/problems/guess-number-higher-or-lower/
*/

#include <iostream>
using namespace std;

/*
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
                 1 if num is lower than the picked number
                 otherwise return 0
 */

int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int start = 1, end = n;
        int mid = 0;

        while (true)
        {
            mid = start + (end - start) / 2;

            if (guess(mid) == 0)
                return mid;

            else if (guess(mid) == -1)
                end = mid - 1;

            else
                start = mid + 1;
        }

        return 0;
    }
};