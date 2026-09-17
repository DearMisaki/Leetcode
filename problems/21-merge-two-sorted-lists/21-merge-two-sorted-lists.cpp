#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p1 = list1, *p2 = list2;

        ListNode *p3 = new ListNode(0, nullptr);
        ListNode *dummpyhead = p3;

        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                p3->next = p1;
                p3 = p3->next;

                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;

                p2 = p2->next;
            }
        }

        ListNode *p4 = p1 == nullptr ? p2 : p1;

        p3->next = p4;

        p3 = dummpyhead->next;

        delete dummpyhead;

        return p3;
    }
};