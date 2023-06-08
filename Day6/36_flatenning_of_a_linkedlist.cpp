#include <bits/stdc++.h>
using namespace std;

// Node structure  used in the program
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    Node *top = root;
    Node *curr = root;
    vector<int> v;
    while (top != NULL)
    {
        Node *curr_top = top;
        while (curr_top != NULL)
        {
            v.push_back(curr_top->data);
            curr_top = curr_top->bottom;
        }
        top = top->next;
    }
    sort(v.begin(), v.end());
    Node *new_list = new Node(0);
    Node *dummy = new_list;
    for (int i = 0; i < v.size(); i++)
    {
        Node *node = new Node(v[i]);
        new_list->bottom = node;
        new_list = new_list->bottom;
    }
    return dummy->bottom;
}
