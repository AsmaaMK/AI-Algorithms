#include <bits/stdc++.h>

#include "represent-graph.h"
using namespace std;

void BFS(string start, string goal, map<string, vector<string>> graph) {
  map<string, bool> visited;
  queue<string> q;
  map<string, string> parent;

  q.push(start);
  visited[start] = true;
  parent[start] = "";

  while (!q.empty()) {
    string node = q.front();
    q.pop();

    if (node == goal) break;

    for (auto child : graph[node])
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
        parent[child] = node;
      }
  }

  print_path(goal, parent);
}

int main() {
  auto graph = build_graph_without_weights();
  BFS("arad", "bucharest", graph);
}