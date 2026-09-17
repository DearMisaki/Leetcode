#include "ListNode.hpp"

#include <stack>

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        if (headA == headB)
            return headA;

        std::stack<ListNode *> s1, s2;

        ListNode *p = headA;
        while (p != nullptr)
        {
            s1.push(p);
            p = p->next;
        }

        p = headB;
        while (p != nullptr)
        {
            s2.push(p);
            p = p->next;
        }

        if (s1.top() != s2.top())
            return nullptr;

        ListNode *intersection = nullptr;
        while (!s1.empty() && !s2.empty())
        {
            if (s1.top() == s2.top())
            {
                intersection = s1.top();
                s1.pop();
                s2.pop();
            }
            else
            {
                break;
            }
        }
        return intersection;
    }
};


class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode * pA = headA, *pB = headB;

        // A: a + s   B: b + s
        // 满足 a + s + b == b + s + a
        // 所以交叉遍历两个链表，最终会在 nullptr 或 pA == pB 处停下
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA = pA->next;
            pB = pB == nullptr ? headA: pB = pB->next;
        }

        return pA;
    }
};