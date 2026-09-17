#include <TreeNode.h>

#include <stack>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode*> nodeStack;

        TreeNode* curr = root;

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

                inorder.push_back(prev->val);

                if (prev->right)
                {
                    curr = prev->right;
                }
            }
        }

        int result = numeric_limits<int>::max();

        for (int i = 1; i < inorder.size(); ++i)
        { 
            result = min(result, inorder[i] - inorder[i - 1]);
        }

        return result;
    }
    private:
    vector<int> inorder;
};