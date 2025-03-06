template <typename T>
bool edgesComparator(Edge<T> *a, Edge<T> *b) {
    return a->getWeight() < b->getWeight();
}

/**
 * Auxiliary function to set the "path" field to make a spanning tree.
 */
template <typename T>
void dfsKruskalPath(Vertex<T> *v) {
    int count = 0;

    // Mark vertex as visited
    v->setVisited(true);

    // For every edge that is selected
    // and child is not visited (reverse edge)
    for (Edge<T> *e : v->getAdj())
        if (e->isSelected() and not e->getDest()->isVisited()) {
            count++;
            e->getDest()->setPath(e);
            dfsKruskalPath(e->getDest());
        }
}

template <typename T>
std::vector<Vertex<T> *> kruskal(Graph<T> *g) {
    // Init disjoin sets
    UFDS sets(g->getNumVertex());

    // Init edge list
    std::vector<Edge<T> *> edges;

    // Add all edges to the list
    for (Vertex<T> *v : g->getVertexSet()) {
        std::vector<Edge<T> *> adjList = v->getAdj();
        edges.insert(edges.end(), adjList.begin(), adjList.end());
    }

    // Mark all edges as not selected
    for (Edge<T> *e : edges) e->setSelected(false);

    // Sort the list
    std::sort(edges.begin(), edges.end(), edgesComparator<T>);

    // For each edge
    for (Edge<T> *e : edges) {
        Edge<T> *reverse_e = e->getReverse();

        std::vector<Vertex<T> *> nodes = g->getVertexSet();

        // Find indexes of nodes in the vertex set of the graph itself
        // We could just do vertex.getInfo()
        // int node_a_idx = e->getOrig()->getInfo();
        // int node_b_idx = e->getDest()->getInfo();
        // However if the info in the vertex was random or not an int it would not work
        // This way it works what ever type T is
        int node_a_idx = std::find(nodes.begin(), nodes.end(), e->getOrig()) - nodes.begin();
        int node_b_idx = std::find(nodes.begin(), nodes.end(), e->getDest()) - nodes.begin();

        // If it connects 2 nodes in different sets
        // Mark edges as selected and join sets
        if (not sets.isSameSet(node_a_idx, node_b_idx)) {
            e->setSelected(true);
            reverse_e->setSelected(true);
            sets.linkSets(node_a_idx, node_b_idx);
        }
    }

    // Mark all vertex as not visited
    for (Vertex<T> *v : g->getVertexSet()) v->setVisited(false);

    // DFS each vertex only through edges marked as select
    // Setting it's path in the direction it came from.
    for (Vertex<T> *v : g->getVertexSet())
        if (not v->isVisited()) {
            v->setPath(nullptr);
            dfsKruskalPath(v);
        }

    return g->getVertexSet();
}
