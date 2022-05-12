#include <bits/stdc++.h>
using namespace std;

// breadth-first search is optimal
// it always expands the shallowest unexpanded node
void BFS(string start, string end, map<string, vector<pair<string, int>>> graph)
{
  map<string, bool> visited;
  queue<string> q;

  q.push(start);
  visited[start] = true;

  cout << "Path: ";

  while (!q.empty())
  {
    string node = q.front();
    q.pop();

    cout << node << " ";

    if (node == end)
      return;

    for (auto child : graph[node])
      if (!visited[child.first])
      {
        q.push(child.first);
        visited[child.first] = true;
      }
  }
}
