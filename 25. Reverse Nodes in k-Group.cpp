/*
    25. Reverse Nodes in k-Group :-

    LINK:   https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        int count = 1;

        ListNode *prevPtr = head;
        ListNode *currPtr = head->next;
        ListNode *nextPtr;

        head->next = NULL;

        while (currPtr != NULL)
        {
            if (count == k)
            {
                head->next = reverseKGroup(currPtr, k);
                break;
            }

            else
            {
                nextPtr = currPtr->next;
                currPtr->next = prevPtr;

                prevPtr = currPtr;
                currPtr = nextPtr;

                count++;
            }
        }

        if (count < k)
            prevPtr = reverseKGroup(prevPtr, count);

        return prevPtr;
    }
};