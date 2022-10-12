/*
    876. Middle of the Linked List :-

    LINK:   https://leetcode.com/problems/middle-of-the-linked-list/
*/

#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // Edge case
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;

            if (fast != NULL)
                fast = fast->next;

            slow = slow->next;
        }

        return slow;
    }
};