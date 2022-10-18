/*
    237. Delete Node in a Linked List :-

    LINK:   https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *next = node->next;
        *node = *next;
        delete next;
    }
};