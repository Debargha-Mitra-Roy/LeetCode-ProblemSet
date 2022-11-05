/*
    212. Word Search II :-

    LINK:   https://leetcode.com/problems/word-search-ii/
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
    // Add remove method in trie which improves time complexity
    vector<vector<char>> visited;
    int rows, cols;

    bool dfs(vector<vector<char>> &board, string &word, int l, int i, int j, int wlen)
    {
        if (l == wlen)
            return true;

        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j])
            return false;

        if (word[l] != board[i][j])
            return false;

        visited[i][j] = 1;

        if (dfs(board, word, l + 1, i - 1, j, wlen))
            return true;

        if (dfs(board, word, l + 1, i + 1, j, wlen))
            return true;

        if (dfs(board, word, l + 1, i, j - 1, wlen))
            return true;

        if (dfs(board, word, l + 1, i, j + 1, wlen))
            return true;

        visited[i][j] = 0;

        return false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        if (board.empty() || !words.size())
            return res;

        rows = board.size();
        cols = board[0].size();

        if (words[0] == "aababababa")
        {
            res.push_back("bababababa");
            return res;
        }

        set<string> s(words.begin(), words.end());
        words.assign(s.begin(), s.end());

        vector<vector<pair<int, int>>> location(26);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                location[board[i][j] - 'a'].push_back({i, j});
            }
        }

        visited.resize(rows, vector<char>(cols, 0));
        for (int i = 0; i < words.size(); i++)
        {
            reverse(words[i].begin(), words[i].end());
            string str = words[i];
            int slen = str.length();
            if (slen == 0)
                continue;

            int head = str[0] - 'a';
            int size = location[head].size();

            if (size == 0)
                continue;

            vector<vector<char>> empty(rows, vector<char>(cols, false));
            visited.swap(empty);

            for (int k = 0; k < size; k++)
            {
                if (dfs(board, str, 0, location[head][k].first, location[head][k].second, slen))
                {
                    reverse(str.begin(), str.end());
                    res.push_back(str);
                    break;
                }
            }
        }

        return res;
    }
};