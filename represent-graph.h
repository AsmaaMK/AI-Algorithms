#include <bits/stdc++.h>
using namespace std;

map<string, vector<pair<string, int>>> build_graph()
{
  map<string, vector<pair<string, int>>> graph;
  freopen("romania.txt", "r", stdin);

  string from, to;
  int weight;

  while (cin >> from >> to >> weight)
  {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
  }

  return graph;
}

void print_graph(map<string, vector<pair<string, int>>> graph)
{
  for (auto i = graph.begin(); i != graph.end(); ++i)
  {
    string city = i->first;
    vector<pair<string, int>> childs = i->second;

    cout << city << " -> ";
    for (auto child : childs)
      cout << child.first << " " << child.second << ", ";

    cout << endl;
  }
}
