// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "../data_structures/Graph.h"
#include "MSTTestAux.h"

template <typename T>
std::vector<Vertex<T> *> prim(Graph<T> *g) {
    // Init priority queue
    // This will store vertexes according to their distance value
    MutablePriorityQueue<Vertex<T>> queue;

    for (Vertex<T> *v : g->getVertexSet()) {
        // Mark all vertex as processing
        v->setProcessing(true);

        // Set all vertex as infinitely far from the start
        v->setDist(INF);

        // Remove all paths
        v->setPath(nullptr);

        // Add Vertex to the queue
        queue.insert(v);
    }

    // Mark first node as the start (zero distance from root)
    // And notify the queue of the update
    g->getVertexSet().front()->setDist(0);
    queue.decreaseKey(g->getVertexSet().front());

    // Process all vertex in the queue
    while (not queue.empty()) {
        // Extract closest vertex to the MST
        Vertex<T> *v = queue.extractMin();

        // Mark vertex as not processing anymore
        v->setProcessing(false);

        // For every connected vertex
        for (Edge<T> *e : v->getAdj()) {
            Vertex<T> *outer_vertex = e->getDest();

            // If the vertex is still in the queue (processing, not part of the MST)
            // And if the edge weight is less than the current distante
            // (needed in case there are multiple edges for the same vertex)
            if (outer_vertex->isProcessing() and e->getWeight() < outer_vertex->getDist()) {
                // Update vertex path, distance, and signal update to the queue
                outer_vertex->setPath(e);
                outer_vertex->setDist(e->getWeight());
                queue.decreaseKey(outer_vertex);
            }
        }
    }

    return g->getVertexSet();
}

/// TESTS ///
#include <chrono>
#include <gtest/gtest.h>

TEST(TP3_Ex1, test_prim) {
    Graph<int>                 graph = createMSTTestGraph<int>();
    std::vector<Vertex<int> *> res   = prim(&graph);

    std::stringstream ss;
    for (const auto v : res) {
        ss << v->getInfo() << "<-";
        if (v->getPath() != nullptr) { ss << v->getPath()->getOrig()->getInfo(); }
        ss << "|";
    }
    // std::cout << ss.str() << std::endl;

    EXPECT_TRUE(isSpanningTree(res));
    EXPECT_EQ(spanningTreeCost(res), 11);
}

TEST(TP3_Ex1_performance, test_performance_prim) {
    // Change these const parameters as needed
    const int MIN_SIZE      = 10;
    const int MAX_SIZE      = 50; // Try with 100
    const int STEP_SIZE     = 10;
    const int N_REPETITIONS = 1;
    for (int n = MIN_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        Graph<int> g;
        generateRandomGridGraph(n, g);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= N_REPETITIONS; i++) prim(&g);
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed
            = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        // std::cout << "Processing grid (Prim) " << n << " x " << n
        //           << " average time (milliseconds)=" << (elapsed / N_REPETITIONS) << std::endl;
    }
}
