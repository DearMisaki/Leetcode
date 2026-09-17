#include <TreeNode.h>

#include <algorithm>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *p1 = head;
        ListNode *p2 = head->next;

        while (1)
        {
            std::swap(p1->val, p2->val);

            if (p2->next && p2->next->next)
            {   
                p2 = p2->next->next;
                p1 = p1->next->next;
                continue;
            }
            break;
        }
        return head;
    }
};