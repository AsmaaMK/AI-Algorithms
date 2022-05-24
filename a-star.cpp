#include <bits/stdc++.h>

#include "represent-graph.h"
using namespace std;

map<string, int> hn;

struct Node {
  int value = -1;
};

int heuristic(string node) { return hn[node]; }

void init_heuristic() {
  fstream heuristic_file;
  heuristic_file.open("h.in", ios::in);

  string key;
  int value;
  while (heuristic_file >> key >> value) {
    hn[key] = value;
  }

  heuristic_file.close();
}

void a_star(string start, string goal,
            map<string, vector<pair<string, int>>> graph) {
  map<string, Node> dist;
  set<pair<int, string>> q;
  map<string, string> parent;
  init_heuristic();

  q.insert({0, start});
  dist[start].value = 0;
  parent[start] = "";

  while (!q.empty()) {
    pair<int, string> front = *(q.begin());
    q.erase(front);
    auto p = front;
    int d = p.first;
    string node = p.second;

    if (node == goal) break;

    for (auto child : graph[node]) {
      int g_cost = dist[node].value + child.second;

      if (dist[child.first].value == -1 || g_cost < dist[child.first].value) {
        dist[child.first].value = g_cost;
        int f_cost = g_cost + heuristic(child.first);
        q.insert({f_cost, child.first});
        parent[child.first] = node;
      }
    }
  }

  print_path(goal, parent);
  cout << endl << "Cost: " << dist[goal].value << endl;
}

int main() {
  auto graph = build_graph_with_weights();
  a_star("arad", "bucharest", graph);
}
