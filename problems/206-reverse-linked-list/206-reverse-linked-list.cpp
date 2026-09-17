#include "ListNode.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode dummyhead(0, nullptr);
        ListNode *p1 = head, *p2 = nullptr;

        while (p1 != nullptr)
        {
            auto temp = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = temp;
        }

        return p2;
    }
};