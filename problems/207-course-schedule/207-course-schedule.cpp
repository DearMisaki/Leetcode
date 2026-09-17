#include <bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);

    vector<int> node_in(numCourses);
    vector<int> node_out(numCourses);

    for (auto const v : prerequisites) {
      graph[v[1]].push_back(v[0]);

      node_in[v[0]] += 1;
      node_out[v[1]] += 1;
    }

    vector<int> visited(numCourses, 0);

    bool has_circle = false;

    function<void(int)> dfs = [&](int course) -> void{
      if (has_circle) {
        return;
      }

      if (visited[course] == 1)
      {
        has_circle = true;
      }

      if (visited[course] == 2)
      {
        return;
      }

      visited[course] = 1;

      for (int next: graph[course]) {
        dfs(next);
      }

      visited[course] = 2;
    };

    for (int i = 0; i < numCourses; ++i) {
      if (visited[i] == 0) {
        dfs(i);  
      }
    }

    return !has_circle;
  }
};