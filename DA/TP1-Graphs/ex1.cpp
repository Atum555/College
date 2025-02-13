#include "../data_structures/Graph.h"
#include <iostream>

using namespace std;

/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) in a graph from the source node.
 * Returns a vector with the contents of the vertices by dfs order.
 */
template <class T>
vector<T> dfs(Graph<T> *g, const T &source) {
    // Init result list
    vector<int> res;

    // Find start vertex
    Vertex<T> *startVertex = g->findVertex(source);

    // If vertex doesn't exist stop search
    if (startVertex == nullptr) return res;

    // Set all as unvisited
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // DFS Search
    dfsVisit(startVertex, res);

    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void dfsVisit(Vertex<T> *v, vector<T> &res) {
    // Add Vertex value to result list
    res.push_back(v->getInfo());

    // Mark Vertex as visited
    v->setVisited(true);

    // For each edge
    for (Edge<T> *edge : v->getAdj())
        // If vertex not visited
        if (not edge->getDest()->isVisited())
            // DFS Search
            dfsVisit(edge->getDest(), res);
}

/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph, starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */
template <typename T>
vector<T> bfs(Graph<T> *g, const T &source) {
    // Init result list
    vector<int> res;

    // Find start vertex
    Vertex<T> *startVertex = g->findVertex(source);

    // If vertex doesn't exist stop search
    if (startVertex == nullptr) return res;

    // Set all as unvisited
    for (Vertex<T> *v_ : g->getVertexSet()) v_->setVisited(false);

    // Add startVertex to result list
    res.push_back(startVertex->getInfo());

    // Set startVertex as Visited
    startVertex->setVisited(true);

    // Add first vertex to queue
    queue<Vertex<T> *> q;
    q.push(startVertex);

    // Process vertexes in queue
    while (not q.empty()) {
        // Pop parent from queue
        Vertex<T> *parent = q.front();
        q.pop();

        // For each edge
        for (Edge<T> *edge : parent->getAdj()) {
            Vertex<T> *child = edge->getDest();

            // If visited ignore
            if (child->isVisited()) continue;

            // Mark Child as visited
            child->setVisited(true);

            // Add Child to result list
            res.push_back(child->getInfo());

            // Add child to processing queue
            q.push(child);
        }
    }

    return res;
}
