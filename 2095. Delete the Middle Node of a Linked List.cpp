/*
    2095. Delete the Middle Node of a Linked List :-

    LINK:   https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
            return nullptr;

        auto slow = head;
        auto fast = head->next->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        
        return head;
    }
};