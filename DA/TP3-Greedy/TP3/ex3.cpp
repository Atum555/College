// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "../data_structures/Graph.h"
#include <queue> // Include queue for BFS

template <class T>
void unweightedShortestPath(Graph<T> *g, const int &origin) {
    // Mark all nodes as not visited
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // Sell all nodes paths to null and distance to infinite
    // (needed in case graph has more than 1 Connected Component)
    for (Vertex<T> *v : g->getVertexSet()) v->setPath(nullptr);
    for (Vertex<T> *v : g->getVertexSet()) v->setDist(INF);

    // Init processing queue
    std::queue<Vertex<T> *> q;

    // Set origin as visited, distance to 0 and push it to the queue
    Vertex<T> *originVertex = g->findVertex(origin);
    originVertex->setVisited(true);
    originVertex->setDist(0);
    q.push(originVertex);

    // Process every node in the queue
    while (not q.empty()) {
        // Get vertex from queue
        Vertex<T> *parent = q.front();
        q.pop();

        // Add Every, non visited, connected node to the queue and update it's path and distance
        for (Edge<T> *e : parent->getAdj()) {
            Vertex<T> *child = e->getDest();
            if (not child->isVisited()) {
                // Mark child as visited
                child->setVisited(true);

                // Set path to edge connecting the node it came from to the node itself
                child->setPath(e);
                child->setDist(parent->getDist() + 1);
                q.push(child);
            }
        }
    }
}

template <class T>
static std::vector<T> getPath(Graph<T> *g, const int &origin, const int &dest) {
    std::vector<T> res;

    // Start from the destination vertex
    Vertex<T> *v = g->findVertex(dest);

    // While we don't reach the origin vertex
    while (v->getInfo() != origin) {
        // Add Node value to the result list
        res.push_back(v->getInfo());

        // Update v to point to the previous node in the path
        v = v->getPath()->getOrig();
    }

    // Add the origin node to the result list
    res.push_back(origin);

    // Reverse the vector to start at the origin and end at the dest
    std::reverse(res.begin(), res.end());

    return res;
}

/// TESTS ///
#include <chrono>
#include <gtest/gtest.h>

template <class T>
static void checkAllPaths(Graph<T> &g, std::string expected) {
    std::stringstream        ss;
    std::vector<Vertex<T> *> vs = g.getVertexSet();
    for (unsigned int i = 0; i < vs.size(); i++) {
        ss << vs[i]->getInfo() << "<-";
        if (vs[i]->getPath() != nullptr) { ss << vs[i]->getPath()->getOrig()->getInfo(); }
        ss << "|";
    }
    EXPECT_EQ(expected, ss.str());
}

static void checkSinglePath(std::vector<int> path, std::string expected) {
    std::stringstream ss;
    for (unsigned int i = 0; i < path.size(); i++) { ss << path[i] << " "; }
    EXPECT_EQ(expected, ss.str());
}

TEST(TP3_Ex3, test_unweightedShortestPath) {
    Graph<int> myGraph;

    for (int i = 1; i <= 7; i++) myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 1);
    myGraph.addEdge(1, 4, 1);
    myGraph.addEdge(2, 4, 1);
    myGraph.addEdge(2, 5, 1);
    myGraph.addEdge(3, 1, 1);
    myGraph.addEdge(3, 6, 1);
    myGraph.addEdge(4, 3, 1);
    myGraph.addEdge(4, 5, 1);
    myGraph.addEdge(4, 6, 1);
    myGraph.addEdge(4, 7, 1);
    myGraph.addEdge(5, 7, 1);
    myGraph.addEdge(6, 4, 1);
    myGraph.addEdge(7, 6, 1);

    unweightedShortestPath(&myGraph, 3);
    checkAllPaths(myGraph, "1<-3|2<-1|3<-|4<-1|5<-2|6<-3|7<-4|");

    unweightedShortestPath(&myGraph, 1);
    checkAllPaths(myGraph, "1<-|2<-1|3<-4|4<-1|5<-2|6<-4|7<-4|");
    checkSinglePath(getPath(&myGraph, 1, 7), "1 4 7 ");

    unweightedShortestPath(&myGraph, 5);
    checkSinglePath(getPath(&myGraph, 5, 6), "5 7 6 ");

    unweightedShortestPath(&myGraph, 7);
    checkSinglePath(getPath(&myGraph, 7, 1), "7 6 4 3 1 ");
}
