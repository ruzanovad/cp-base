#include "cp_base.h"

#include <iostream>
#include <queue>
#include <stack>

void graph_theory::bfs(int node, vector<vector<int>>& graph) {
  int n = graph.size();
  queue<int> q;
  q.push(node);

  vector<int> d(n, -1), p(n);
  d[node] = 0;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : graph[v]) {
      if (d[u] == -1) {
        q.push(u);
        d[u] = d[v] + 1;
        p[u] = v;
      }
    }
  }
}

void graph_theory::dfs(int node, vector<vector<int>>& graph,
                       vector<bool>& visited, vector<int> path) {
  int n = graph.size();

  visited[node] = 1;
  path.push_back(node);
  for (auto& x : graph[node]) {
    if (~visited[x]) {
      graph_theory::dfs(x, graph, visited, path);
      path.push_back(node);
    }
  }
}