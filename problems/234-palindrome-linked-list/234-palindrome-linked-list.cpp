#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

class Solution
{
    ListNode *left = nullptr;

public:
    bool isPalindrome(ListNode *head)
    {
        left = head;
        return check(head);
    }

    bool check(ListNode *node)
    {
        if (node == nullptr)
            return true;

        bool checked = check(node->next);

        if (!checked)
            return false;

        if (left->val != node->val)
            return false;

        left = left->next;
        return true;
    }
};