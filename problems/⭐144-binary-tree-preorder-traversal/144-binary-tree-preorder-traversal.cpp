#include "TreeNode.h"

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    // 中左右
    vector<int> preorderTraversal(TreeNode *root)
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

        result.push_back(root->val);

        traversal(root->left, result);
        traversal(root->right, result);
    }
};

class Solution2
{
public:
    // 中左右
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>();

        vector<int> result;
        stack<TreeNode *> node_stack;

        node_stack.push(root);

        while (!node_stack.empty())
        {
            TreeNode *top = node_stack.top();
            node_stack.pop();

            result.push_back(top->val);

            if (top->right)
                node_stack.push(top->right);
            if (top->left)
                node_stack.push(top->left);
        }

        return result;
    }
};

class Solution3
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *rightmost = curr->left;

                while (rightmost->right && rightmost->right != curr)
                {
                    rightmost = rightmost->right;
                }

                if (rightmost->right == nullptr)
                {
                    rightmost->right = curr;

                    result.push_back(curr->val);

                    curr = curr->left;

                    continue;
                }
                else
                {
                    rightmost->right = nullptr;
                }
            }
            else
            {
                result.push_back(curr->val);
            }

            // curr->left == nullptr
            curr = curr->right;
        }

        return result;
    }
};