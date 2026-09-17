#include "TreeNode.h"

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;

        traversal(root, result);

        return result;
    }

    void traversal(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        traversal(root->left, result);

        result.push_back(root->val);

        traversal(root->right, result);
    }
};

class Solution2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> node_stack;

        TreeNode *curr = root;

        while (curr || !node_stack.empty())
        {
            if (curr)
            {
                node_stack.push(curr);

                curr = curr->left;
            }
            else
            {
                // 当 curr == nullptr，回溯到上一个节点
                TreeNode *prev = node_stack.top();

                // 按照 左中右 的顺序，左节点为空，输出中节点
                result.push_back(prev->val);

                // 如果存在右节点，从右节点开始往左下走
                if (prev->right)
                    curr = prev->right;

                node_stack.pop();
            }
        }
        return result;
    }
};


/**
 * morrist 解法 时间 O(n) 空间 O(1)
 * 
 * 规则：
 * 1. curr 左孩子为空，则向右移动
 * 2. curr 左孩子不为空，找到左子树的 right most 节点
 *      1. 如果 这个 right most 的 right 指针指向 null，则让其指向 curr，curr 向左移动
 *      2. 如果 这个 right most 的 right 指针指向 curr，则让其指向 null，curr 向右移动
 */

class Solution3
{
public:
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        TreeNode* curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode* rightmost = curr->left;

                while (rightmost->right && rightmost->right != curr)
                {
                    rightmost = rightmost->right;
                }

                if (rightmost->right == nullptr)
                {
                    // 按中序规则，指向 rightmost 节点的后继，也就是 curr
                    rightmost->right = curr;

                    curr = curr->left;
                    
                    continue;
                }
                else
                {
                    rightmost->right = nullptr;
                }
            }

            // curr->left == nullptr
            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }
};