/*
    1721. Swapping Nodes in a Linked List :-

    LINK:   https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        
        while (--k)
        {
            ptr1 = ptr1->next;
        }

        kth = ptr1;
        ptr1 = ptr1->next;

        while (ptr1)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        swap(&ptr2->val, &kth->val);

        return head;
    }
};