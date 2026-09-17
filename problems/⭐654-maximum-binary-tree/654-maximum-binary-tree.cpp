#include <TreeNode.h>

#include <vector>

using namespace std;

// 单调栈
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int size = nums.size();

        vector<int> left(size, -1), right(size, -1);

        vector<int> stk;

        vector<TreeNode *> nodes(size);

        for (int i = 0; i < size; ++i)
        {
            nodes[i] = new TreeNode(nums[i]);
            // 当前元素 > 栈顶索引指向的元素；出栈 并将 栈顶索引指向元素 的 右侧更大元素赋为 当前元素
            while (!stk.empty() && nums[i] > nums[stk.back()])
            {
                right[stk.back()] = i;
                stk.pop_back();
            }

            // 跳出上面的循环，说明栈顶索引指向元素 > 当前元素；那么将当前元素的 左侧更大值 赋为 栈顶索引指向元素
            if (!stk.empty())
            {
                left[i] = stk.back();
            }

            // 对于每个元素，无论其大小，都应该将其入栈
            stk.push_back(i);
        }

        TreeNode *root = nullptr;

        for (int i = 0; i < size; ++i)
        {
            // 当前元素在数组中最大，则其为根节点
            if (left[i] == -1 && right[i] == -1)
            {
                root = nodes[i];
            }
            // 左侧无更大 或者 左侧更大值 > 右侧更大值；将当前节点挂到 右侧最大值的左孩子
            else if (left[i] == -1 || (right[i] != -1 && nums[left[i]] > nums[right[i]]))
            {
                nodes[right[i]]->left = nodes[i];
            }
            // 右侧无更大值；将当前节点挂到左侧更大值得右节点
            else
            {
                nodes[left[i]]->right = nodes[i];
            }
        }

        return root;
    }
};