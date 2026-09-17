#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> index_map;

        for (auto p = head; p; p = p->next)
        {
            index_map[p] = new Node(p->val);
        }

        for (auto p = head; p; p = p->next)
        {
            index_map[p]->next = index_map[p->next];
            index_map[p]->random = index_map[p->random];
        }

        return index_map[head];
    }
};