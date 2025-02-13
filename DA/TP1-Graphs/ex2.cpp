#include "../data_structures/Graph.h"
#include <iostream>

using namespace std;

/*
 * Performs a topological sorting of the vertices of a graph.
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 */
template <typename T>
vector<T> topsort(Graph<T> *g) {
    // Init reverse topological sort list, and result list
    vector<int> list;
    vector<int> result;

    // Mark all vertices as unvisited
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // Mark all vertices as not processing
    for (Vertex<T> *v : g->getVertexSet()) v->setProcessing(false);

    // For all non visited nodes, sort topologically
    for (Vertex<T> *v : g->getVertexSet())
        if (not v->isVisited())
            // If cycle found, stop and rerturn empty list
            if (not topsort_aux(v, list)) return result;

    // Reverse the list to sort topologically
    for (auto it = list.rbegin(); it != list.rend(); it++) result.push_back(*it);
    return result;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Adding each vertex to a list (res) in post-order.
 * Returns true on success, false when a cycle is found.
 */
template <typename T>
bool topsort_aux(Vertex<T> *v, vector<int> &list) {
    // Mark vertex as processing
    v->setProcessing(true);

    // For each connected vertex
    for (Edge<T> *edge : v->getAdj()) {
        Vertex<T> *child = edge->getDest();

        // If vertex already visited ignore
        if (child->isVisited()) continue;

        // If vertex processing, cycle found, abort
        if (child->isProcessing()) return false;

        // Process child
        if (not topsort_aux(child, list)) return false;
    }

    // Mark vertex as visited
    v->setVisited(true);

    // Add vertex to list
    list.push_back(v->getInfo());

    // No cycles found
    return true;
}
