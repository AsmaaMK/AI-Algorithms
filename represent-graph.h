#include <bits/stdc++.h>
using namespace std;

map<string, vector<pair<string, int>>> build_graph_with_weights() {
  map<string, vector<pair<string, int>>> graph;
  freopen("romania.in", "r", stdin);

  string from, to;
  int weight;

  while (cin >> from >> to >> weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
  }

  return graph;
}

map<string, vector<string>> build_graph_without_weights() {
  map<string, vector<string>> graph;
  freopen("romania.in", "r", stdin);

  string from, to, weight;

  while (cin >> from >> to >> weight) {
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  return graph;
}

void print_graph(map<string, vector<pair<string, int>>> graph) {
  for (auto i = graph.begin(); i != graph.end(); ++i) {
    string city = i->first;
    vector<pair<string, int>> childs = i->second;

    cout << city << " -> ";
    for (auto child : childs)
      cout << child.first << " " << child.second << ", ";

    cout << endl;
  }
}

void print_path(string goal, map<string, string> parent) {
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
  cout << "\n";
}