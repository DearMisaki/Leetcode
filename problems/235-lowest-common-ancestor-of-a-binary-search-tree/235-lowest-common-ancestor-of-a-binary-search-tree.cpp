#include <TreeNode.h>

// 详见 ⭐236-lowest-common-ancestor-of-a-binary-tree


// 二叉搜索树相比二叉树多了一个有序的特性
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;

        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            // 第一次找到 root.val 介于 p.val 和 q.val 之间的 root 节点
            // 这个节点就是最近公共祖先
            return root;
        }
    }
};