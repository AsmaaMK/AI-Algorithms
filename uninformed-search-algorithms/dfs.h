#include <bits/stdc++.h>
using namespace std;

void DFS_until(string node, string end, map<string, bool> &visited, bool printed, map<string, vector<pair<string, int>>> graph)
{
  visited[node] = true;

  if (!printed)
    cout << node << " ";

  if (node == end)
    printed = true;

  for (auto child : graph[node])
  {
    if (!visited[child.first])
      DFS_until(child.first, end, visited, printed, graph);
  }
}

void DFS(string start, string end, map<string, vector<pair<string, int>>> graph)
{
  map<string, bool> visited;
  cout << "Path: ";
  DFS_until(start, end, visited, false, graph);
}