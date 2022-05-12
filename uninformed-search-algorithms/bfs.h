#include <bits/stdc++.h>
using namespace std;

// breadth-first search is optimal
// it always expands the shallowest unexpanded node
void BFS(string start, string goal,
         map<string, vector<pair<string, int>>> graph) {
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
      if (!visited[child.first]) {
        q.push(child.first);
        visited[child.first] = true;
        parent[child.first] = node;
      }
  }

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
