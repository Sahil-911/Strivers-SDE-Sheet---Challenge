#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> hash;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if (hash.find(key) != hash.end())
        {
            node *res = hash[key];
            int ans = res->val;
            hash.erase(key);
            deletenode(res);
            addnode(res);
            hash[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (hash.find(key) != hash.end())
        {
            node *existingnode = hash[key];
            hash.erase(key);
            deletenode(existingnode);
        }
        if (hash.size() == cap)
        {
            hash.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node *newnode = new node(key, value);
        addnode(newnode);
        hash[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */