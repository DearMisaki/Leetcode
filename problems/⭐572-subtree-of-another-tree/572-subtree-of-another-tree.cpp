#include "TreeNode.h"

#include <queue>
#include <stack>
#include <limits>

using namespace std;

class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
        {
            return true;
        }

        if (root != nullptr && subRoot == nullptr)
        {
            return true;
        }

        if (root == nullptr && subRoot != nullptr)
        {
            return false;
        }

        stack<TreeNode *> node_stack;
        node_stack.push(root);

        stack<TreeNode *> stack_temp;

        while (!node_stack.empty())
        {
            TreeNode *node = node_stack.top();
            node_stack.pop();

            if (node->val == subRoot->val && is_same_tree(node, subRoot))
            {
                return true;
            }

            if (node->right)
            {
                node_stack.push(node->right);
            }

            if (node->left)
            {
                node_stack.push(node->left);
            }
        }

        return false;
    }

    bool is_same_tree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (!p || !q)
        {
            return false;
        }

        return p->val == q->val &&
               is_same_tree(p->left, q->left) && is_same_tree(p->right, q->right);
    }
};

// 结合 kmp、先序遍历
class Solution2
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot) return true;
        if (!root) return false;

        vector<int> root_sequence;
        vector<int> subroot_sequence;

        preorder_traversal(root, root_sequence);
        preorder_traversal(subRoot, subroot_sequence);

        return kmp(root_sequence, subroot_sequence) != -1;
    }

    void preorder_traversal(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        result.push_back(root->val);

        if (root->left)
        {
            preorder_traversal(root->left, result);
        }
        else
        {
            result.push_back(lnull);
        }

        if (root->right)
        {
            preorder_traversal(root->right, result);
        }
        else
        {
            result.push_back(rnull);
        }
    }

    vector<int> get_next(const vector<int> &pattern)
    {
        vector<int> next(pattern.size(), 0);

        int j = 0;

        for (int i = 1; i < pattern.size(); ++i)
        {
            while (pattern[j] != pattern[i] && j > 0)
            {
                j = next[j - 1];
            }

            if (pattern[i] == pattern[j])
            {
                ++j;
            }

            next[i] = j;
        }

        return next;
    }

    int kmp(const vector<int> &haystack, const vector<int> &needle)
    {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;

        auto next = get_next(needle);

        for (int i = 0, j = 0; i < haystack.size(); ++i)
        {
            while (haystack[i] != needle[j] && j > 0)   
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j])
            {
                ++j;
            }

            if (j == needle.size())
            {
                return i - needle.size() + 1;
            }
        }

        return -1;
    }

private:
    int lnull = numeric_limits<int>::max();
    int rnull = numeric_limits<int>::max() - 1;
};