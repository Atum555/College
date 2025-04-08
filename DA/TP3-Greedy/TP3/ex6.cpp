#include "../data_structures/Graph.h"
#include <limits>

// Function to perform DFS and find an augmenting path
template <class T>
bool dfsFindAugmentingPath(Vertex<T> *v, Vertex<T> *t, double &flow) {
    // TODO
    return false;
}

// Ford-Fulkerson algorithm
template <class T>
void fordFulkerson(Graph<T> *g, int source, int target) {
    // TODO
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex6, test_fordFulkerson) {
    Graph<int> myGraph;

    for (int i = 1; i <= 6; i++) myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 3);
    myGraph.addEdge(1, 3, 2);
    myGraph.addEdge(2, 5, 4);
    myGraph.addEdge(2, 4, 3);
    myGraph.addEdge(2, 3, 1);
    myGraph.addEdge(3, 5, 2);
    myGraph.addEdge(4, 6, 2);
    myGraph.addEdge(5, 6, 3);

    fordFulkerson(&myGraph, 1, 6);

    std::stringstream ss;
    for (auto v : myGraph.getVertexSet()) {
        ss << v->getInfo() << "-> (";
        for (const auto e : v->getAdj())
            ss << (e->getDest())->getInfo() << "[Flow: " << e->getFlow() << "] ";
        ss << ") || ";
    }

    std::cout << ss.str() << std::endl << std::endl;

    EXPECT_EQ(
        "1-> (2[Flow: 3] 3[Flow: 2] ) || 2-> (5[Flow: 1] 4[Flow: 2] 3[Flow: 0] ) || 3-> (5[Flow: "
        "2] ) || 4-> (6[Flow: 2] ) || 5-> (6[Flow: 3] ) || 6-> () || ",
        ss.str()
    );
}
