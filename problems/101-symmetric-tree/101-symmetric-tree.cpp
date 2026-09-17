#include "TreeNode.h"
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr || !root->left && !root->right)
        {
            return true;
        }

        return check(root->left, root->right);
    }

    bool check(TreeNode* p, TreeNode* q)
    {
        if (!q && !p) return true;
        if (!q || !p) return false;

        if (p->val == q->val && check(p->left, q->right) && check(p->right, q->left))
        {
            return true;
        }
        return false;
    }
};

class Solution2
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr || !root->left && !root->right)
        {
            return true;
        }

        queue<TreeNode*> que;

        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            TreeNode* p = que.front(); que.pop();
            TreeNode* q = que.front(); que.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;

            if (p->val == q->val)
            {
                que.push(p->left);
                que.push(q->right);

                que.push(p->right);
                que.push(q->left);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};