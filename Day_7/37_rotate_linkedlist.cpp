#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL)
        {
            len++;
            tail = tail->next;
        }

        k = k % len;
        if (k == 0)
            return head;

        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < k; i++)
            fast = fast->next;

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *new_head = slow->next;
        slow->next = NULL;
        tail->next = head;
        return new_head;
    }
};