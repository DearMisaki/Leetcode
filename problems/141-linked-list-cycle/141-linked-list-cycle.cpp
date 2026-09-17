#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return false;

        ListNode *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;

            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};