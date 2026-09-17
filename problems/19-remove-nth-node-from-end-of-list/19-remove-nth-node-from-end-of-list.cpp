#include <TreeNode.h>

#include <stack>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::stack<ListNode *> s;
        
        ListNode dummyhead(0, head);
        ListNode *p1 = &dummyhead;
        
        while (p1 != nullptr)
        {
            s.push(p1);
            p1 = p1->next;
        }
        
        ListNode * prev = nullptr, *todelete = nullptr;
        for (; n > 0; --n)
        {
            s.pop();
        }

        prev = s.top();
        todelete = prev->next;

        prev->next = prev->next->next;

        delete todelete;

        return dummyhead.next;
    }
};