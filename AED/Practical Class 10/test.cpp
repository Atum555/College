#include <iostream>
#include "graph.h"

int main() {

  // Read one input graph
  Graph *g = Graph::readGraph();

  // read q pairs of integers to indicate the queries
  int q;
  std::cin >> q;
  for (int i=0; i<q; i++) {
    int a, b;
    std::cin >> a >> b;
    std::cout << "g->shortestPath(" << a << "," << b << ") =";
    std::list<int> path = g->shortestPath(a,b);
    if (path.size() == 0) std::cout << " EMPTY";
    else for (int v : path) std::cout << " " << v;
    std::cout << std::endl;
  }
  
  delete g;
  
  return 0;
}
