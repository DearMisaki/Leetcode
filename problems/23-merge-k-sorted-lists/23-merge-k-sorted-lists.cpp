#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
        {
            return lists[l];
        }

        if (l > r)
        {
            return nullptr;
        }

        int mid = (l + r) >> 1;

        return mergeTwoList(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode *mergeTwoList(ListNode *head1, ListNode *head2)
    {
        ListNode temp, *p1 = head1, *p2 = head2;

        ListNode *p = &temp;

        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }

            p = p->next;
        }

        if (p1)
        {
            p->next = p1;
        }
        else if (p2)
        {
            p->next = p2;
        }

        return temp.next;
    }
};