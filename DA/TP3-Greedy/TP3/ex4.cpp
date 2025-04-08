// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "../data_structures/Graph.h"
#include "../data_structures/MutablePriorityQueue.h"

using namespace std;

template <class T>
bool relax(Edge<T> *edge) {
    Vertex<T> *orig = edge->getOrig();
    Vertex<T> *dest = edge->getDest();

    // If edge causes a smaller distance update distance and path
    if (dest->getDist() > orig->getDist() + edge->getWeight()) {
        dest->setDist(orig->getDist() + edge->getWeight());
        dest->setPath(edge);
        return true;
    }

    return false;
}

template <class T>
void dijkstra(Graph<T> *g, const int &origin) {
    // Init priority queue
    // This will give the vertex with the smallest distance
    MutablePriorityQueue<Vertex<T>> queue;

    for (Vertex<T> *v : g->getVertexSet()) {
        // Set all vertex as infinitely far from the start
        v->setDist(INF);

        // Remove all paths
        v->setPath(nullptr);

        // Add Vertex to the queue
        queue.insert(v);
    }

    // Mark first node as the start (zero distance from root)
    // And notify the queue of the update
    g->findVertex(origin)->setDist(0);
    queue.decreaseKey(g->findVertex(origin));

    // Process all vertexes in increasing distance order
    while (not queue.empty()) {
        // Extract next smallest distance vertex
        Vertex<T> *parent = queue.extractMin();

        // Relax every connected edge and update priority queue
        for (Edge<T> *e : parent->getAdj())
            if (relax(e)) queue.decreaseKey(e->getDest());
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

TEST(TP3_Ex4, test_dijkstra) {
    Graph<int> myGraph;

    for (int i = 1; i <= 7; i++) myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 2);
    myGraph.addEdge(1, 4, 7);
    myGraph.addEdge(2, 4, 3);
    myGraph.addEdge(2, 5, 5);
    myGraph.addEdge(3, 1, 2);
    myGraph.addEdge(3, 6, 5);
    myGraph.addEdge(4, 3, 1);
    myGraph.addEdge(4, 5, 1);
    myGraph.addEdge(4, 6, 6);
    myGraph.addEdge(4, 7, 4);
    myGraph.addEdge(5, 7, 2);
    myGraph.addEdge(6, 4, 3);
    myGraph.addEdge(7, 6, 4);

    dijkstra(&myGraph, 3);
    checkAllPaths(myGraph, "1<-3|2<-1|3<-|4<-2|5<-4|6<-3|7<-5|");

    dijkstra(&myGraph, 1);
    checkAllPaths(myGraph, "1<-|2<-1|3<-4|4<-2|5<-4|6<-4|7<-5|");
    checkSinglePath(getPath(&myGraph, 1, 7), "1 2 4 5 7 ");

    dijkstra(&myGraph, 5);
    checkSinglePath(getPath(&myGraph, 5, 6), "5 7 6 ");

    dijkstra(&myGraph, 7);
    checkSinglePath(getPath(&myGraph, 7, 1), "7 6 4 3 1 ");
}
