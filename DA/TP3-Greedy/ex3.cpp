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
