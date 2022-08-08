/*
    54. Spiral Matrix :-

    LINK:   https://leetcode.com/problems/spiral-matrix/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> answer;

        int row = matrix.size();
        int column = matrix[0].size();

        int count = 0;
        int total = row * column;

        /* index initialisation */
        int startingRow = 0;
        int startingColumn = 0;
        int endingRow = row - 1;
        int endingColumn = column - 1;

        while (count < total)
        {
            /* printing startring row */
            for (int index = startingColumn; count < total && index <= endingColumn; index++)
            {
                answer.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            /* printing ending column */
            for (int index = startingRow; count < total && index <= endingRow; index++)
            {
                answer.push_back(matrix[index][endingColumn]);
                count++;
            }
            endingColumn--;

            /* printing ending row */
            for (int index = endingColumn; count < total && index >= startingColumn; index--)
            {
                answer.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            /* printing starting column */
            for (int index = endingRow; count < total && index >= startingRow; index--)
            {
                answer.push_back(matrix[index][startingColumn]);
                count++;
            }
            startingColumn++;
        }

        return answer;
    }
};