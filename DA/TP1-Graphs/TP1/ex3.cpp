#include "../data_structures/Graph.h"
#include <iostream>

using namespace std;

/****************** isDAG  ********************/
/*
 * Performs a depth-first search in a graph, to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the stack of recursive calls.
 * Returns true if the graph is acyclic, and false otherwise.
 */
template <class T>
bool isDAG(Graph<T> *g) {
    // Mark all vertices as unvisited
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // Mark all vertices as not processing
    for (Vertex<T> *v : g->getVertexSet()) v->setProcessing(false);

    // For all non visited nodes, performe a DFS
    for (Vertex<T> *v : g->getVertexSet())
        if (not v->isVisited())
            // If cycle found, stop and rerturn empty list
            if (not dfsIsDAG_aux(v)) return false;

    return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool dfsIsDAG_aux(Vertex<T> *v) {
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
        if (not dfsIsDAG_aux(child)) return false;
    }

    // Mark vertex as visited
    v->setVisited(true);

    // No cycles found
    return true;
}
