#include <TreeNode.h>
#include <stack>

using namespace std;

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return nullptr;
        }

        int leftvalue = root1 ? root1->val : 0;
        int rightvalue = root2 ? root2->val : 0;

        TreeNode *newNode = new TreeNode(leftvalue + rightvalue);

        newNode->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        newNode->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);

        return newNode;
    }
};