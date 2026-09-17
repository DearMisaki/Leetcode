#include "TreeNode.h"

#include <stack>

using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (p && !q || q && !p)
        {
            return false;
        }

        stack<TreeNode *> node_stack;
        node_stack.push(p);
        node_stack.push(q);

        while (!node_stack.empty())
        {
            TreeNode *node_p = node_stack.top();
            node_stack.pop();
            TreeNode *node_q = node_stack.top();
            node_stack.pop();

            if (node_p->val == node_q->val)
            {
                if (node_p->right && node_q->right)
                {
                    node_stack.push(node_p->right);
                    node_stack.push(node_q->right);
                }
                else if (node_p->right || node_q->right)
                {
                    return false;
                }

                if (node_p->left && node_q->left)
                {
                    node_stack.push(node_p->left);
                    node_stack.push(node_q->left);
                }
                else if (node_p->left || node_q->left)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};