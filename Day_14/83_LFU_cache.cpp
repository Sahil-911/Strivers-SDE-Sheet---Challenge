#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    int val;
    int cnt;
    node *prev;
    node *next;
    node(int _key, int _val)
    {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct listt
{
    int size;
    node *head;
    node *tail;
    listt()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        size++;
    }

    void removeNode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
public:
    map<int, listt *> freqlist;
    map<int, node *> keynode;
    int cap;
    int min_freq;
    int curr_size;

    LFUCache(int capacity)
    {
        cap = capacity;
        min_freq = 0;
        curr_size = 0;
    }

    void updateFreqList(node *Node)
    {
        keynode.erase(Node->key);
        freqlist[Node->cnt]->removeNode(Node);
        if (Node->cnt == min_freq && freqlist[Node->cnt]->size == 0)
            min_freq++;
        listt *nextHigherFreq = new listt();
        if (freqlist.find(Node->cnt + 1) != freqlist.end())
            nextHigherFreq = freqlist[Node->cnt + 1];
        Node->cnt++;
        nextHigherFreq->addFront(Node);
        freqlist[Node->cnt] = nextHigherFreq;
        keynode[Node->key] = Node;
    }

    int get(int key)
    {
        if (keynode.find(key) != keynode.end())
        {
            node *Node = keynode[key];
            int val = Node->val;
            updateFreqList(Node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;
        if (keynode.find(key) != keynode.end())
        {
            node *Node = keynode[key];
            Node->val = value;
            updateFreqList(Node);
        }
        else
        {
            if (curr_size == cap)
            {
                listt *List = freqlist[min_freq];
                keynode.erase(List->tail->prev->key);
                freqlist[min_freq]->removeNode(List->tail->prev);
                curr_size--;
            }
            curr_size++;
            min_freq = 1;
            listt *newlist = new listt();
            if (freqlist.find(min_freq) != freqlist.end())
                newlist = freqlist[min_freq];
            node *Node = new node(key, value);
            newlist->addFront(Node);
            keynode[key] = Node;
            freqlist[min_freq] = newlist;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */