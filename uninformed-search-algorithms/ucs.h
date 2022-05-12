#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value = -1;
};

void UCS(string start, string goal,
         map<string, vector<pair<string, int>>> graph) {
  map<string, Node> dist;
  set<pair<int, string>> q;
  map<string, string> parent;

  q.insert({0, start});
  parent[start] = "";

  while (!q.empty()) {
    pair<int, string> front = *(q.begin());
    q.erase(front);
    auto p = front;
    int d = p.first;
    string node = p.second;

    if (dist[node].value != -1) continue;

    dist[node].value = d;

    for (auto child : graph[node])
      if (dist[child.first].value == -1) {
        q.insert({d + child.second, child.first});
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

  cout << endl << "Cost: " << dist[goal].value << endl;
}