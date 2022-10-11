/*
    142. Linked List Cycle II :-

    LINK:   https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *start = head;

        if (head == NULL || head->next == NULL)
            return NULL;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (slow != fast)
            return nullptr;

        while (slow != start)
        {
            slow = slow->next;
            start = start->next;
        }

        return slow;
    }
};