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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *curr = new ListNode();
        ListNode *merged = curr;
        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->val < curr2->val)
            {
                curr->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        if (curr1 != NULL)
            curr->next = curr1;
        else if (curr2 != NULL)
            curr->next = curr2;
        return merged->next;
    }
};