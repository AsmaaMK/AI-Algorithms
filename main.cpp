#include <bits/stdc++.h>
#include "./uninformed-search-algorithms/bfs.h"
#include "./uninformed-search-algorithms/dfs.h"
#include "./uninformed-search-algorithms/ucs.h"
#include "represent-graph.h"
using namespace std;

int main()
{
  map<string, vector<pair<string, int>>> graph = build_graph();
  // print_graph(graph);

  cout << "DFS" << endl;
  DFS("arad", "bucharest", graph);

  cout << endl
       << endl
       << "BFS" << endl;
  BFS("arad", "bucharest", graph);

  cout << endl
       << endl
       << "UCS" << endl;
  UCS("arad", "bucharest", graph);
}