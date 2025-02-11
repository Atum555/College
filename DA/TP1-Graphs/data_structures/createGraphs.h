#ifndef SRC_CREATE_GRAPHS_H
#define SRC_CREATE_GRAPHS_H

#include "Graph.h"

using namespace std;

class createGraphs {
  public:
    static Graph<int> graph1();
    static Graph<int> graph2();
    static Graph<int> graph3();
    static Graph<int> graph4();
    static Graph<int> graph5();
    static Graph<int> graph6();
    static Graph<int> graph7();
    static Graph<int> graph8();
    static Graph<int> graph9();
    static Graph<int> graph10();
    static Graph<int> graph11();
    static Graph<int> graph12();
    static Graph<int> graph13();
    static Graph<int> graph14();
    static Graph<int> graph15();
    static Graph<int> graph16();
    static Graph<int> graph17();
    static Graph<int> graph18();
    static Graph<int> graph19();
    static Graph<int> graph20();

    static Graph<int> createGraphNumber(int n);

    static vector<int> findIsolatedNodesInGraph(Graph<int> g);
    static void        emitDOTFile(string fname, Graph<int> g);
};

#endif
