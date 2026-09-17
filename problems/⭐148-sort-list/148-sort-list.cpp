#include <bits/stdc++.h>

using namespace std;

#include "ListNode.h"

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return head;

        int length = 0;

        for (auto p = head; p; p = p->next)
        {
            ++length;
        }

        ListNode dummyhead(0, head);

        for (int sublength = 1; sublength < length; sublength <<= 1)
        {
            ListNode *current = dummyhead.next;

            ListNode *prev = &dummyhead;

            while (current)
            {
                ListNode *head1 = current;

                for (int i = 1; i < sublength && current->next; ++i)
                {
                    current = current->next;
                }

                ListNode *head2 = current->next;

                current->next = nullptr;

                current = head2;

                for (int i = 1; i < sublength && current && current->next; ++i)
                {
                    current = current->next;
                }

                ListNode *next = nullptr;

                if (current)
                {
                    next = current->next;
                    current->next = nullptr;
                }

                ListNode *merged = merge(head1, head2);

                prev->next = merged;

                // 停在最后一个 不为 null 的节点
                while (prev->next)
                {
                    prev = prev->next;
                }

                current = next;
            }
        }

        return dummyhead.next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode dummyhead(0);

        ListNode *temp = &dummyhead, *temp1 = head1, *temp2 = head2;

        while (temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        if (temp1)
        {
            temp->next = temp1;
        }
        else if (temp2)
        {
            temp->next = temp2;
        }

        return dummyhead.next;
    }
};