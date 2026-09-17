#include <TreeNode.h>

#include <vector>
#include <stack>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        stack<TreeNode *> nodeStack;

        TreeNode *curr = root;

        while (curr || !nodeStack.empty())
        {
            if (curr)
            {
                nodeStack.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *prev = nodeStack.top();
                nodeStack.pop();

                update(prev->val);

                if (prev->right)
                {
                    curr = prev->right;
                }
            }
        }

        return result;
    }

    void update(int x)
    {
        if (x == prevValue)
        {
            count++;
        }
        else
        {
            prevValue = x;
            count = 1;
        }

        if (count == maxCount)
        {
            result.push_back(x);
        }

        if (count > maxCount)
        {
            result = vector<int> {x};

            maxCount = count;
        }
    }

private:
    vector<TreeNode *> inorder;
    vector<int> result;
    int count = 0;
    int maxCount = 1;
    int prevValue = numeric_limits<int>::max();
};