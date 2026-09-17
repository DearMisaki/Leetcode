#include "ListNode.hpp"

#include <unordered_set>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * p = head;

        std::unordered_set<ListNode *> s;

        while (p != nullptr)
        {
            if (s.count(p))
            {
                return p;
            }

            s.insert(p);
            p = p->next;
        }
        
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {

        // 链表 空 或 只有一个元素，必定无环
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode * slow = head, * fast = head;

        while (fast != nullptr)
        // 快慢指针，先找到环内相遇点
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;

            if (fast == slow)
            {
                ListNode *p = slow->next;
                int perimeter = 1;

                while (p != slow)
                // 找到相遇点后，再计算圆的周长
                {
                    p = p->next;
                    ++perimeter;
                }

                ListNode *p1 = head, *p2 = head;
                while (perimeter--)
                // 知道周长后，从 head 设置两个指针 p1 p2
                // p1 先走 周长 的长度，p2 再一起走
                // ⭐当 p1 走到链表末尾时（环的入口），刚好遇见 p2，因为 p1 p2 始终相差 周长 的距离
                {
                    p1 = p1->next;
                }

                while (p1 != p2)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};