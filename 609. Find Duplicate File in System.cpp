/*
    609. Find Duplicate File in System :-

    LINK:   https://leetcode.com/problems/find-duplicate-file-in-system/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> hashmap;

        for (auto index : paths)
        {
            stringstream ss(index);
            string dir, file;

            getline(ss, dir, ' ');

            while (getline(ss, file, ' '))
            {
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(') - 1);
                string name = dir + '/' + file.substr(0, file.find('('));

                hashmap[content].push_back(name);
            }
        }
        
        vector<vector<string>> ans;

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            if (it->second.size() > 1)
                ans.push_back(it->second);
        }

        return ans;
    }
};