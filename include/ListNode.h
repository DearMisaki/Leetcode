#ifndef LISTNODE_HPP
#define LISTNODE_HPP

struct ListNode {
      int val;
      struct ListNode * next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

#endif // LISTNODE_HPP