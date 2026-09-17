#include "TreeNode.h"
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return 0;
    }

    int ret = rootSum(root, targetSum);

    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);

    return ret;
  }

  int rootSum(TreeNode *root, int targetSum) {
    if (!root) {
      return 0;
    }

    int ret = 0;

    if (root->val == targetSum) {
      ++ret;
    }

    ret += rootSum(root->left, targetSum - root->val);
    ret += rootSum(root->right, targetSum - root->val);

    return ret;
  }
};

class Solution2 {
public:
  unordered_map<long long, int> mp;
  int pathSum(TreeNode *root, int targetSum) {

    // 对于 curr == targetSum 的情况，必须有 mp[0] = 1
    mp[0] = 1;
    int ret = traversal(root, 0, targetSum);

    return ret;
  }

  int traversal(TreeNode *node, long long curr, int targetSum) {
    if (!node) {
      return 0;
    }

    int ret = 0;

    curr += node->val;

    if (mp.count(curr - targetSum) > 0) {
      ret = mp[curr - targetSum];
    }

    mp[curr]++;
    ret += traversal(node->left, curr, targetSum);
    ret += traversal(node->right, curr, targetSum);
    mp[curr]--;

    return ret;
  }
};