#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummyhead(0, head);

        ListNode *p1 = &dummyhead, *p2 = &dummyhead;

        // p1 代表下一组的前一个节点，只有 p1.next 不为空时，才能进入下一组
        while (p1->next != nullptr)
        {
            for (int i = 0; i < k && p2 != nullptr; ++i)
            {
                p2 = p2->next;
            }

            // 提前跳出循环，代表末尾不足 k 个
            if (p2 == nullptr)
                break;

            ListNode *start = p1->next;
            ListNode *next_start = p2->next;

            p2->next = nullptr;

            ListNode *new_head = partial_reverse(start);

            p1->next = new_head;

            start->next = next_start;

            // next_start 的前一个节点
            p1 = start;
            p2 = p1;
        }

        return dummyhead.next;
    }

    // 返回反转后的新头节点
    ListNode *partial_reverse(ListNode *start)
    {
        ListNode *pre = nullptr;
        ListNode *curr = start;

        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }
};