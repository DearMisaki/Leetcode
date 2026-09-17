#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          visited[i][j] = 1;
          island_count++;
          traversal(grid, visited, i, j);
        }
      }
    }

    return island_count;
  }

  void traversal(vector<vector<char>> &grid, vector<vector<int>> &visited,
                 int x, int y) {

    for (int i = 0; i < 4; ++i) {
      int next_x = x + dir[i][0];
      int next_y = y + dir[i][1];

      if (next_x < 0 || next_x > grid.size() - 1 || next_y < 0 ||
          next_y > grid[0].size() - 1) {
        continue;
      }

      if (!visited[next_x][next_y] && grid[next_x][next_y] == '1') {
        visited[next_x][next_y] = 1;
        traversal(grid, visited, next_x, next_y);
      }
    }
  }

  int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
  int island_count = 0;
};