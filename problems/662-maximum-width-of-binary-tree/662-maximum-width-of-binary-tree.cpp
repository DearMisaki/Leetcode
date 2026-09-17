#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if (root == nullptr)
      {
        return 0;
      }

      unsigned long long res = 0;

      queue<pair<TreeNode*, unsigned long long>> que;

      que.push({root, 1});

      while (!que.empty())
      {
        unsigned long long leftindex = que.front().second;
        unsigned long long rightindex = que.back().second;

        res = max(res, rightindex - leftindex + 1);

        int size = que.size();

        for (int i = 0; i < size; ++i)
        {
          auto node = que.front(); que.pop();

          if (node.first->left)
          {
            que.push({node.first->left, node.second * 2});
          }

          if (node.first->right)
          {
            que.push({node.first->right, node.second * 2 + 1});
          }
        }
      }

      return res;
    }
};