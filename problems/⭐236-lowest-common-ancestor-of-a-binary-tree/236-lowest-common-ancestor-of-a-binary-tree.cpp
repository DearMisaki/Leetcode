#include <TreeNode.h>

#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 找到 p q 最近祖先则返回，没找到则返回 null 从下至上
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // 当前 路径找到了 p 或 q 或 路径到达尽头
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 当前节点是最近公共祖先， left 与 right 不为空时 必定找到 p q 两个节点
        if (left != nullptr && right != nullptr)
            return root;

        // 当前路径找到了 最近公共祖先 或 p 或 q 或 null
        return left != nullptr ? left : right;
    }
};

class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<TreeNode *, TreeNode *> parent;

        parent[root] = nullptr;

        TreeNode *curr = root;
        stack<TreeNode *> nodeStack;

        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            auto node = nodeStack.top();
            nodeStack.pop();

            if (node->right)
            {
                nodeStack.push(node->right);
                parent[node->right] = node;
            }

            if (node->left)
            {
                nodeStack.push(node->left);
                parent[node->left] = node;
            }
        }

        unordered_set<TreeNode *> set;

        TreeNode *current = p;
        while (current)
        {
            set.emplace(current);

            current = parent[current];
        }

        current = q;
        while (current && set.find(current) == set.end())
        {
            current = parent[current];
        }

        return current;
    }
};