#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../data_structures/Graph.h"
#include "../data_structures/createGraphs.h"
#include "ex1.cpp"
#include "ex2.cpp"
#include "ex3.cpp"
#include "ex4.cpp"
#include "ex5.cpp"

using testing::Eq;
using testing::UnorderedElementsAre;

TEST(TP1_Ex1, test_dfs) {
    // Create a graph
    Graph<int> graph;
    // Create a graph with 7 vertices
    for(unsigned int i = 1; i <= 7; i++) {
        graph.addVertex(i);
    }
    // Add edges
    graph.addEdge(1,2,0);
    graph.addEdge(1,3,0);
    graph.addEdge(1,4,0);
    graph.addEdge(2,5,0);
    graph.addEdge(5,6,0);
    graph.addEdge(5,1,0);
    graph.addEdge(3,6,0);
    graph.addEdge(3,7,0);
    graph.addEdge(6,2,0);

    std::vector<int> vs = dfs(&graph, 1);
    unsigned int ids[] = {1, 2, 5, 6, 3, 7, 4};
    EXPECT_EQ(vs.size(), 7);
    for (unsigned int i = 0; i < vs.size(); i++) {
        EXPECT_EQ(vs[i], ids[i]);
    }
}

TEST(TP1_Ex1, test_bfs) {
    // Create a graph
    Graph<int> graph;
    // Create a graph with 7 vertices
    for(unsigned int i = 1; i <= 7; i++) {
        graph.addVertex(i);
    }
    // Add edges
    graph.addEdge(1,2,0);
    graph.addEdge(1,3,0);
    graph.addEdge(1,4,0);
    graph.addEdge(2,5,0);
    graph.addEdge(5,6,0);
    graph.addEdge(5,1,0);
    graph.addEdge(3,6,0);
    graph.addEdge(3,7,0);
    graph.addEdge(6,2,0);

    std::vector<int> vs = bfs(&graph, 1);
    unsigned int ids[] = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(vs.size(), 7);
    for (unsigned int i = 0; i < vs.size(); i++) {
        EXPECT_EQ(vs[i], ids[i]);
    }
}

template <typename T>
void expectTopSort(const Graph<T>* graph, std::vector<int> topOrder){
    for(auto u: graph->getVertexSet()) {
        auto itrU = std::find(topOrder.begin(), topOrder.end(), u->getInfo());
        unsigned int indexU = std::distance(topOrder.begin(), itrU);
        for(auto edge: u->getAdj()) {
            auto v = edge->getDest();
            auto itrV = std::find(topOrder.begin(), topOrder.end(), v->getInfo());
            unsigned int indexV = std::distance(topOrder.begin(), itrV);
            EXPECT_LT(indexU,indexV);
        }
    }
}

TEST(TP1_Ex2, test_topsort) {
    Graph<int> myGraph;
    myGraph.addVertex(1); myGraph.addVertex(2); myGraph.addVertex(3); myGraph.addVertex(4);
    myGraph.addVertex(5); myGraph.addVertex(6); myGraph.addVertex(7);

    myGraph.addEdge(1, 2, 0);
    myGraph.addEdge(1, 4, 0);
    myGraph.addEdge(1, 3, 0);
    myGraph.addEdge(2, 5, 0);
    myGraph.addEdge(2, 4, 0);
    myGraph.addEdge(3, 6, 0);
    myGraph.addEdge(4, 3, 0);
    myGraph.addEdge(4, 6, 0);
    myGraph.addEdge(4, 7, 0);
    myGraph.addEdge(5, 4, 0);
    myGraph.addEdge(5, 7, 0);
    myGraph.addEdge(7, 6, 0);

    std::vector<int> topOrder = topsort(&myGraph);
    EXPECT_EQ(topOrder.size(), 7);
    expectTopSort(&myGraph, topOrder); // example of two valid topsorts: "1 2 5 4 3 7 6" and "1 2 5 4 7 3 6"

    // to test including a cycle in the graph
    myGraph.addEdge(3, 1, 0);

    topOrder = topsort(&myGraph);
    EXPECT_EQ(topOrder.size(), 0);
}

TEST(TP1_Ex3, test_isDAG) {
    Graph<int> myGraph;

    for( int i = 0; i < 6; i++) {
        myGraph.addVertex(i);
    }

    myGraph.addEdge(1, 2, 0);
    myGraph.addEdge(2, 5, 0);
    myGraph.addEdge(5, 4, 0);
    myGraph.addEdge(3, 1, 0);
    myGraph.addEdge(0, 4, 0);

    EXPECT_EQ(isDAG(&myGraph), true);

    myGraph.addEdge(4, 1, 0);

    EXPECT_EQ(isDAG(&myGraph), false);
}

TEST(TP1_Ex4, test_SCC_kosaraju) {
    Graph<int> graph0;
    for( int i = 0; i <= 7; i++) {
        graph0.addVertex(i);
    }
    graph0.addEdge(0,1,0);
    graph0.addEdge(1,2,0);
    graph0.addEdge(2,0,0);
    graph0.addEdge(2,3,0);
    graph0.addEdge(3,4,0);
    graph0.addEdge(4,7,0);
    graph0.addEdge(4,5,0);
    graph0.addEdge(5,6,0);
    graph0.addEdge(6,7,0);
    graph0.addEdge(6,4,0);
    vector<vector<int>> sccs_graph0 = SCCkosaraju(& graph0);
    EXPECT_EQ(sccs_graph0.size(), 4);

    Graph<int> graph1;
    for(unsigned int i = 1; i <= 7; i++) {
        graph1.addVertex(i);
    }
    graph1.addEdge(1,2,0);
    graph1.addEdge(1,3,0);
    graph1.addEdge(1,4,0);
    graph1.addEdge(2,5,0);
    graph1.addEdge(5,6,0);
    graph1.addEdge(5,1,0);
    graph1.addEdge(3,6,0);
    graph1.addEdge(3,7,0);
    graph1.addEdge(6,2,0);
    vector<vector<int>> sccs_graph1 = SCCkosaraju(&graph1);

    EXPECT_EQ(sccs_graph1.size(), 3);
    EXPECT_THAT(sccs_graph1,  ::testing::UnorderedElementsAre(::testing::UnorderedElementsAre(1,2,3,5,6), ::testing::UnorderedElementsAre(4), ::testing::UnorderedElementsAre(7)));

    Graph<int> graph2;
    for(unsigned int i = 1; i <= 5; i++) {
        graph2.addVertex(i);
    }
    graph2.addEdge(1,3,0);
    graph2.addEdge(1,4,0);
    graph2.addEdge(2,1,0);
    graph2.addEdge(3,2,0);
    graph2.addEdge(4,5,0);
    vector<vector<int>> sccs_graph2 = SCCkosaraju(&graph2);

    EXPECT_EQ(sccs_graph2.size(), 3);
    EXPECT_THAT(sccs_graph2,  ::testing::UnorderedElementsAre(::testing::UnorderedElementsAre(1,2,3), ::testing::UnorderedElementsAre(4), ::testing::UnorderedElementsAre(5)));

}

TEST(TP1_Ex5, test_SCC_Tarjan) {
    Graph<int> graph0;
    for( int i = 0; i <= 7; i++) {
        graph0.addVertex(i);
    }
    graph0.addEdge(0,1,0);
    graph0.addEdge(1,2,0);
    graph0.addEdge(2,0,0);
    graph0.addEdge(2,3,0);
    graph0.addEdge(3,4,0);
    graph0.addEdge(4,7,0);
    graph0.addEdge(4,5,0);
    graph0.addEdge(5,6,0);
    graph0.addEdge(6,7,0);
    graph0.addEdge(6,4,0);
    vector<vector<int>> sccs_graph0 = sccTarjan(& graph0);
    EXPECT_EQ(sccs_graph0.size(), 4);

    Graph<int> graph1;
    for(unsigned int i = 1; i <= 7; i++) {
        graph1.addVertex(i);
    }
    graph1.addEdge(1,2,0);
    graph1.addEdge(1,3,0);
    graph1.addEdge(1,4,0);
    graph1.addEdge(2,5,0);
    graph1.addEdge(5,6,0);
    graph1.addEdge(5,1,0);
    graph1.addEdge(3,6,0);
    graph1.addEdge(3,7,0);
    graph1.addEdge(6,2,0);

    vector<vector<int>> sccs_graph1 = sccTarjan(&graph1);

    EXPECT_EQ(sccs_graph1.size(), 3);
    EXPECT_THAT(sccs_graph1,  ::testing::UnorderedElementsAre(::testing::UnorderedElementsAre(1,2,3,5,6), ::testing::UnorderedElementsAre(4), ::testing::UnorderedElementsAre(7)));

    Graph<int> graph2;

    for(unsigned int i = 1; i <= 5; i++) {
        graph2.addVertex(i);
    }

    graph2.addEdge(1,3,0);
    graph2.addEdge(1,4,0);
    graph2.addEdge(2,1,0);
    graph2.addEdge(3,2,0);
    graph2.addEdge(4,5,0);

    vector<vector<int>> sccs_graph2 = sccTarjan(&graph2);

    EXPECT_EQ(sccs_graph2.size(), 3);
    EXPECT_THAT(sccs_graph2,  ::testing::UnorderedElementsAre(::testing::UnorderedElementsAre(1,2,3), ::testing::UnorderedElementsAre(4), ::testing::UnorderedElementsAre(5)));

}

void PrintNodesList(vector<int> v){
    int n = v.size();
    cout << "{";
    if(n > 0){
        cout << v[0];
        for (int i=1; i < n; i++){
            cout << "," << v[i];
        }
    }
    cout << "}" << endl;
}

/*
TEST(TP1_extratests, test_extratests) {
    vector<int> res;
    Graph<int> myGraph;

    myGraph = createGraphs::graph1(); // You can test with other graphs created in createGraphs.cpp

    std::cout << "DFS (undirected)!" << std::endl;
    res =  dfs(&myGraph, 0); // You can test with other source nodes
    PrintNodesList(res);

    std::cout << "BFS !" << std::endl;
    res = bfs(&myGraph, 0); // You can test with other source nodes
    PrintNodesList(res);

    std::cout << "Top Sorting!" << std::endl;
    res = topsort(&myGraph);
    PrintNodesList(res);
}
 */