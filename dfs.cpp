#include <bits/stdc++.h>

#include "represent-graph.h"
using namespace std;

map<string, string> parent;
map<string, bool> visited;

void DFS_until(string node, string goal, map<string, vector<string>> graph) {
  visited[node] = true;

  if (node == goal) return;

  for (auto child : graph[node]) {
    if (!visited[child]) {
      parent[child] = node;
      DFS_until(child, goal, graph);
    }
  }
}

void DFS(string start, string goal, map<string, vector<string>> graph) {
  DFS_until(start, goal, graph);
  parent[start] = "";
  print_path(goal, parent);
}

int main() {
  auto graph = build_graph_without_weights();
  DFS("arad", "bucharest", graph);
}