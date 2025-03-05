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
