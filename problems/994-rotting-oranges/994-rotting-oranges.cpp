#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {

    int ret = 0;

    int m = grid.size(), n = grid[0].size();

    queue<pair<int, int>> que;

    vector<vector<int>> distance(m, vector<int>(n, -1));

    int orange_cnt = 0;

    // 找出 多个起始点、好橘子总数
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2) {
          que.push({i, j});

          distance[i][j] = 0;
        }
        if (grid[i][j] == 1) {
          orange_cnt++;
        }
      }
    }

    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    while (!que.empty()) {
      auto orange = que.front();
      que.pop();

      int x = orange.first;
      int y = orange.second;

      for (int i = 0; i < 4; ++i) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n ||
            distance[nextx][nexty] != -1) {
          continue;
        }

        if (grid[nextx][nexty] == 1) {
          que.push({nextx, nexty});

          distance[nextx][nexty] = distance[x][y] + 1;

          orange_cnt--;

          ret = distance[nextx][nexty];
        }
      }
    }

    return orange_cnt == 0 ? ret : -1;
  }
};