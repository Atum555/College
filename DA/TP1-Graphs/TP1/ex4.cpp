#include "../data_structures/Graph.h"
#include "stack"
using namespace std;

// Kosaraju-Sharir algorithm
template <typename T>
vector<vector<T>> SCCkosaraju(Graph<T> *g) {
    // Init SCC list
    vector<vector<T>> sccs;

    // Mark all vertex as unvisited
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // Init postOrderStack
    stack<T> pOrderStack;

    // DFS Graph storing it in a stack in post order
    for (Vertex<T> *v : g->getVertexSet())
        if (not v->isVisited()) dfs_postOrder_aux(v, pOrderStack);

    // Create reverse Graph
    Graph<T> reverseGraph = getReverseGraph(g);

    // Mark all vertex as unvisited
    for (Vertex<T> *v : reverseGraph.getVertexSet()) v->setVisited(false);

    // While stack not empty
    while (not pOrderStack.empty()) {
        // Pop vertex from stack
        T vertexInfo = pOrderStack.top();
        pOrderStack.pop();

        // Get vertex pointer
        Vertex<T> *v = reverseGraph.findVertex(vertexInfo);

        // If vertex not visited
        if (not v->isVisited()) {
            // Init SCC
            vector<int> scc;

            // DFS search reverse graph creating SCC
            dfs_createSCC(v, scc);

            // Add SCC to SCCs list
            sccs.push_back(scc);
        }
    }

    return sccs;
}

template <typename T>
void dfs_postOrder_aux(Vertex<T> *v, stack<T> &pOrderStack) {
    // Mark vertex as visited
    v->setVisited(true);

    // For every non visited adjacent vertex, dfs search
    for (Edge<T> *edge : v->getAdj()) {
        Vertex<T> *child = edge->getDest();
        if (not child->isVisited()) dfs_postOrder_aux(child, pOrderStack);
    }

    // Push parent vertex to stack
    pOrderStack.push(v->getInfo());
}

template <typename T>
Graph<T> getReverseGraph(Graph<T> *g) {
    // Init reverse graph
    Graph<T> reverseGraph;

    // Add Vertexes
    for (Vertex<T> *v : g->getVertexSet()) reverseGraph.addVertex(v->getInfo());

    // For each Vertex
    for (Vertex<T> *v : g->getVertexSet()) {
        // Add each edge in reverse
        for (Edge<T> *edge : v->getAdj())
            reverseGraph.addEdge(edge->getDest()->getInfo(), v->getInfo(), edge->getWeight());
    }

    return reverseGraph;
}

template <typename T>
void dfs_createSCC(Vertex<T> *v, vector<int> &scc) {
    // Add vertex to scc
    scc.push_back(v->getInfo());

    // Mark vertex as visited
    v->setVisited(true);

    // DFS search adjacent vertexes if not visited
    for (Edge<T> *edge : v->getAdj()) {
        Vertex<T> *child = edge->getDest();
        if (not child->isVisited()) dfs_createSCC(child, scc);
    }
}
