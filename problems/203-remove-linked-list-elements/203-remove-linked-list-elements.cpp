#include "ListNode.hpp"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyhead(0, head);

        ListNode *prev = &dummyhead;
        for (ListNode * node = head; node != nullptr; )
        {
            if (node->val == val)
            {
                ListNode *temp = node;
                node = node->next;
                
                prev->next = node;

                delete temp;
                temp = nullptr;

                continue;
            }
            prev = node;
            node = node->next;
        }

        return dummyhead.next;
    }
};

int main(int argc, char const *argv[])
{
    int val[] = {1,2,6,3,4,5,6};
    
    ListNode dummyhead(0, nullptr);
    ListNode * prev = &dummyhead;

    for (auto const & v: val)
    {
        ListNode *node = new ListNode(v, nullptr);
        prev->next = node;
        prev = node;
    }

    Solution slo;
    slo.removeElements(dummyhead.next, 6);
    return 0;
}
