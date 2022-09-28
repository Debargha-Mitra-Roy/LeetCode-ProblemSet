/*
    19. Remove Nth Node From End of List :-

    LINK:   https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#include <iostream>
using namespace std;

/*Definition for singly-linked list. */
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
private:
    int findLength(ListNode *head)
    {
        if (head == NULL)
            return 0;

        return (findLength(head->next) + 1);
    }

    ListNode *removeNthFromStart(ListNode *head, int i)
    {
        if (i == 0)
            return head->next;

        head->next = removeNthFromStart(head->next, i - 1);

        return head;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = findLength(head);

        return removeNthFromStart(head, len - n);
    }
};