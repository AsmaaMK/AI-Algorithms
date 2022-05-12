#include <bits/stdc++.h>
using namespace std;

map<string, string> parent;

void DFS_until(string node, string goal, map<string, bool> &visited,
               bool printed, map<string, vector<pair<string, int>>> graph) {
  visited[node] = true;

  if (node == goal) printed = true;

  for (auto child : graph[node]) {
    if (!visited[child.first]) {
      parent[child.first] = node;
      DFS_until(child.first, goal, visited, printed, graph);
    }
  }
}

void DFS(string start, string goal,
         map<string, vector<pair<string, int>>> graph) {
  map<string, bool> visited;
  DFS_until(start, goal, visited, false, graph);

  parent[start] = "";
  string p = parent[goal];
  vector<string> path;
  path.push_back(goal);

  while (p != "") {
    path.push_back(p);
    p = parent[p];
  }

  reverse(path.begin(), path.end());

  cout << "Path: ";
  for (auto node : path) cout << node << " ";
}