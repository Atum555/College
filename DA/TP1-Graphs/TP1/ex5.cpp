#include "../data_structures/Graph.h"
#include "stack"
using namespace std;

template <typename T>
vector<vector<T>> sccTarjan(Graph<T> *g) {
    // Init SCCs list
    vector<vector<T>> sccs;

    // Mark all vertexes as unvisitied
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // Reset all Vertex::num and Vertex::low
    for (Vertex<T> *v : g->getVertexSet()) v->setNum(-1);
    for (Vertex<T> *v : g->getVertexSet()) v->setLow(-1);

    // Init stack
    stack<T> st;

    // Init counter
    int counter = 0;

    // DFS graph constructing SCCs
    for (Vertex<T> *v : g->getVertexSet())
        if (not v->isVisited()) tarjan_aux(v, counter, st, sccs);

    return sccs;
}

template <typename T>
void tarjan_aux(Vertex<T> *parent, int &counter, stack<T> &st, vector<vector<T>> &sccs) {
    // Mark vertex as visited
    parent->setVisited(true);

    // Add vertex to stack
    st.push(parent->getInfo());

    // Set vertex::num and vertex::low, and increment it
    parent->setNum(counter);
    parent->setLow(counter++);

    // For each adjacent vertex
    for (Edge<T> *edge : parent->getAdj()) {
        Vertex<T> *child = edge->getDest();

        // If it hasn't been visited, connection is a tree edge
        if (not child->isVisited()) {
            // DFS child
            tarjan_aux(child, counter, st, sccs);

            // Update current vertex::low
            parent->setLow(min(parent->getLow(), child->getLow()));
        }

        // Else connection is a back edge
        parent->setLow(min(parent->getLow(), child->getNum()));
    }

    if (parent->getNum() != parent->getLow()) return;
    // If vertex::num equals vertex::low
    // Then vertex is a SCC root

    // Init SCC
    vector<T> scc;

    // Construct SCC, by popping from stack
    T value;
    do {
        // Pop value from Stack
        value = st.top();
        st.pop();
        scc.push_back(value);
    }
    // Stop after popping the root vertex (parent)
    while (value != parent->getInfo());

    // Add SCC to SCCs list
    sccs.push_back(scc);
}
