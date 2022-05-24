#include <bits/stdc++.h>

#include "represent-graph.h"
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

  print_path(goal, parent);
  cout << endl << "Cost: " << dist[goal].value << endl;
}

int main() {
  auto graph = build_graph_with_weights();
  UCS("arad", "bucharest", graph);
}