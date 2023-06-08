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

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode* curr=head;
//         string s;
//         while(curr!=NULL)
//         {
//             s+= (char)curr->val;
//             curr=curr->next;
//         }
//         int l=0,r=s.length()-1;
//         while(l<=r)
//         {
//             if(s[l]!=s[r])
//                 return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
// };

class Solution {
public:

    ListNode* reverse(ListNode* curr)
    {
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //reverse 2nd half
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode* dummy=head;
        
        while(slow!=NULL)
        {
            if(dummy->val != slow->val)
                return false;
            dummy=dummy->next;
            slow=slow->next;
        }
        return true;
    }
};