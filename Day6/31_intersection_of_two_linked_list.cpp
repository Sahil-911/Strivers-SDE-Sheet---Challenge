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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        while (curr1 != curr2)
        {
            if (curr2 == NULL)
                curr2 = headA;
            else
                curr2 = curr2->next;
            if (curr1 == NULL)
                curr1 = headB;
            else
                curr1 = curr1->next;
        }
        return curr1;
    }
};