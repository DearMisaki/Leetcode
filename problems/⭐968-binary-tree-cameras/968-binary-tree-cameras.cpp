#include <bits/stdc++.h>

#include <TreeNode.h>

using namespace std;

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;

        if (!root->left && !root->right)
            return 1;

        if (traversal(root, res) == 0)
            return res + 1;
        else 
            return res;
    }

    int traversal(TreeNode* node, int& res)
    {
        if (node == nullptr) return 2;

        int left = traversal(node->left, res);
        int right = traversal(node->right, res);

        if (left == 2 && right == 2)
            return 0;

        if (left == 0 || right == 0)
        {
            res++;
            return 1; 
        }

        if (left == 1 | right == 1)
        {
            return 2;
        }

        return -1;
    }
};

class Solution2 {
public:
    int minCameraCover(TreeNode* root) {
        vector<int> res = dfs(root);
        // 最后根节点如果是 c (未覆盖)，必须补一个相机（取 res[1] + 1 其实就是 res[0] 的逻辑，或者直接取 min(res[0], res[1])）
        // 根节点不能处于“未覆盖”状态，所以只能在“有相机”和“被覆盖”中选最小
        return min(res[0], res[1]);
    }

    // 返回值：vector<int> {有相机, 被覆盖, 未覆盖}
    vector<int> dfs(TreeNode* root) {
        // 空节点处理：
        // 相当于一种“被覆盖”的状态（不需要相机，也不需要被救）
        // 有相机：无穷大（不可能在空节点放相机）
        // 被覆盖：0（不需要代价）
        // 未覆盖：0（空节点不需要被覆盖，等同于被覆盖）
        if (!root) return {INT_MAX / 2, 0, 0}; 

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // --- 状态转移逻辑 ---

        // 1. 当前节点装相机 (res[0])
        // 既然我有相机，左右孩子可以是任意状态（除了不能是“我有相机但还需要父节点救”这种非法状态，但在DP里，
        // 只要我有相机，孩子不管是不是 c 状态都被我覆盖了，
        // 所以孩子取 min(有相机, 被覆盖, 未覆盖) 
        int withCam = 1 + *min_element(left.begin(), left.end()) + *min_element(right.begin(), right.end());

        // 2. 当前节点被覆盖 (res[1])
        // 我没相机，但我被覆盖了 -> 说明左右孩子至少有一个装了相机
        // 组合情况：
        // (左有, 右有) 或 (左有, 右被覆盖) 或 (左被覆盖, 右有)
        // 注意：孩子不能是“未覆盖(c)”状态，因为如果孩子未覆盖，我又没相机，那孩子就废了。
        // 所以孩子只能在 [0] 和 [1] 中选。
        int covered = min({
            left[0] + right[0],    // 两个孩子都有相机
            left[0] + right[1],    // 左孩子有，右孩子自己搞定
            left[1] + right[0]     // 左孩子自己搞定，右孩子有
        });

        // 3. 当前节点未覆盖 (res[2])
        // 我没相机，也没人救我（等父节点救）。
        // 这意味着我的孩子们必须自己搞定自己（状态 b），不能指望我。
        int uncovered = left[1] + right[1];

        return {withCam, covered, uncovered};
    }
};