#include <bits/stdc++.h>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

using namespace std;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool can = false;

void tranversal(vector<vector<char>> &matrix, vector<vector<bool>> &visited,
                int i, int j) {

  visited[i][j] = true;
  if (i == matrix.size() - 1 && j == matrix[0].size() - 1)
    can = true;

  for (int k = 0; k < 4; ++k) {
    int nexti = i + dir[k][0];
    int nextj = j + dir[k][1];

    if (matrix[i][j] == '<')
      --nextj;
    else if (matrix[i][j] == '>')
      ++nextj;

    if (nexti < 0 || nexti >= matrix.size() || nextj < 0 ||
        nextj >= matrix[0].size()) {
      continue;
    }

    // 去重来过的 位置
    if (visited[nexti][nextj])
      continue;

    tranversal(matrix, visited, nexti, nextj);
  }
}

int main() {
  vector<vector<char>> matrix = {
      {'<', '>', '<', '>'},
      {'>', '>', '<', '<'},
  };

  vector<vector<bool>> visited(matrix.size(),
                               vector<bool>(matrix[0].size(), 0));

  tranversal(matrix, visited, 0, 0);

  cout << can << endl;
}