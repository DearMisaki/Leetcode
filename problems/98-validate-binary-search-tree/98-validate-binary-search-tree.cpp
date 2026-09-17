#include <TreeNode.h>

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        traversal(root);

        for (int i = 1; i < traverse.size(); ++i)
        {
            if (traverse[i - 1]->val > traverse[i]->val)
            {
                return false;
            }
        }

        return true;
    }

    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        traversal(root->left);

        traverse.push_back(root);

        traversal(root->right);
    }

private:
    vector<TreeNode *> traverse;
};

class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode*> nodeStack;

        TreeNode* curr = root;

        TreeNode* prevNode = nullptr;

        while (curr || !nodeStack.empty())
        {
            if (curr)
            {
                nodeStack.push(curr);

                curr = curr->left;
            }
            else
            {
                TreeNode* prev = nodeStack.top(); nodeStack.pop();

                if (prevNode && prev->val <= prevNode->val)
                {
                    return false;
                }

                prevNode = prev;

                if (prev->right)
                {
                    curr = prev->right;
                }
            }
        }

        return true;
    }
};