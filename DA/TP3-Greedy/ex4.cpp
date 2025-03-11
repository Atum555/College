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
