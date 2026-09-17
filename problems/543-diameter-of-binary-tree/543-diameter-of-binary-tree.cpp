#include <algorithm>
#include <bits/stdc++.h>

#include "TreeNode.h"

using namespace std;

/*
 * 思路是做深度优先搜索，将左右深度加起来
 */

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    depth(root);

    return m_ans;
  }

  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int L = depth(root->left);
    int R = depth(root->right);

    m_ans = max(m_ans, L + R);

    return max(L, R) + 1;
  }

  int m_ans = 0;
};