#include <bits/stdc++.h>

#include "./../represent-graph.h"
using namespace std;

map<string, int> hn;

struct Node {
  int value = -1;
};

int heuristic(string node) { return hn[node]; }

void a_star(string start, string goal,
            map<string, vector<pair<string, int>>> graph) {
  map<string, Node> dist;
  set<pair<int, string>> q;
  map<string, string> parent;

  q.insert({0, start});
  dist[start].value = 0;
  parent[start] = "";

  // cout << endl << "push " << start << " with dist = " << 0 << endl;

  while (!q.empty()) {
    pair<int, string> front = *(q.begin());
    q.erase(front);
    auto p = front;
    int d = p.first;
    string node = p.second;

    // cout << "pop " << node << " with dist = " << d << endl;

    if (node == goal) break;

    for (auto child : graph[node]) {
      int g_cost = dist[node].value + child.second;

      if (dist[child.first].value == -1 || g_cost < dist[child.first].value) {
        dist[child.first].value = g_cost;
        int f_cost = g_cost + heuristic(child.first);
        q.insert({f_cost, child.first});
        parent[child.first] = node;

        // cout << endl
        //      << "push " << child.first
        //      << " with dist = " << d + child.second + heuristic(child.first) << endl
        //      << "dist[" << node << "] = " << d
        //      << " edge-cost = " << child.second << " h(" << child.first
        //      << ") = " << heuristic(child.first) << endl
        //      << endl;
      }
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

void init_heuristic() {
  hn["arad"] = 366;
  hn["bucharest"] = 0;
  hn["craiova"] = 160;
  hn["drobeta"] = 242;
  hn["eforie"] = 161;
  hn["fagaras"] = 176;
  hn["giurgiu"] = 77;
  hn["hirsova"] = 151;
  hn["iasi"] = 226;
  hn["lugoj"] = 244;
  hn["mehadia"] = 241;
  hn["neamt"] = 234;
  hn["oradea"] = 380;
  hn["pitesti"] = 100;
  hn["rimnicu-vilcea"] = 193;
  hn["sibiu"] = 253;
  hn["timisoara"] = 329;
  hn["urziceni"] = 80;
  hn["vaslui"] = 199;
  hn["zerind"] = 374;
  
  // freopen("h.txt", "r", stdin);
  // string key;
  // int value;
  // while (cin >> key >> value) {
  //   hn[key] = value;
  // }

  // hn["A"] = 10;
  // hn["B"] = 13;
  // hn["C"] = 4;
  // hn["D"] = 2;
  // hn["E"] = 4;
  // hn["F"] = 1;
  // hn["G"] = 0;
  // hn["S"] = 17;
}

int main() {
  // map<string, vector<pair<string, int>>> graph = build_graph("a-star.in");
  // init_heuristic();
  // a_star("S", "G", graph);

  map<string, vector<pair<string, int>>> graph = build_graph("../romania.in");
  init_heuristic();
  a_star("arad", "bucharest", graph);
}
