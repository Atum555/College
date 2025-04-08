#ifndef TEST_AUX_H_
#define TEST_AUX_H_
#endif // TEST_AUX_H_

#include "../data_structures/Graph.h"
#include <map>
#include <random>
#include <set>


template <class T>
std::vector<Vertex<T> *> prim();
template <class T>
std::vector<Vertex<T> *> kruskal();
template <class T>

void edmondsKarp(int source, int target);
template <class T>
void dfsKruskalPath(Vertex<T> *v);
template <class T>
void testAndVisit(std::queue<Vertex<T> *> &q, Edge<T> *e, Vertex<T> *w, double residual);
template <class T>

bool findAugmentingPath(Vertex<T> *s, Vertex<T> *t);
template <class T>

double findMinResidualAlongPath(Vertex<T> *s, Vertex<T> *t);
template <class T>

void augmentFlowAlongPath(Vertex<T> *s, Vertex<T> *t, double f);

template <class T>

Graph<T> createMSTTestGraph() {
    Graph<T> myGraph;

    for (int i = 1; i <= 7; i++) myGraph.addVertex(i);

    myGraph.addBidirectionalEdge(1, 2, 2);
    myGraph.addBidirectionalEdge(1, 4, 7);
    myGraph.addBidirectionalEdge(2, 4, 3);
    myGraph.addBidirectionalEdge(2, 5, 5);
    myGraph.addBidirectionalEdge(3, 1, 2);
    myGraph.addBidirectionalEdge(3, 6, 5);
    myGraph.addBidirectionalEdge(4, 3, 1);
    myGraph.addBidirectionalEdge(4, 5, 1);
    myGraph.addBidirectionalEdge(4, 7, 4);
    myGraph.addBidirectionalEdge(5, 7, 2);
    myGraph.addBidirectionalEdge(6, 4, 3);
    myGraph.addBidirectionalEdge(7, 6, 4);

    return myGraph;
}

template <class T>
bool isSpanningTree(const std::vector<Vertex<T> *> &res) {
    std::map<T, std::set<T>> adj;

    // Build adjacency list from result set
    for (const Vertex<T> *v : res) {
        adj[v->getInfo()]; // Ensure vertex exists in adjacency map

        if (v->getPath() != nullptr) {
            Vertex<T> *u = v->getPath()->getOrig();
            adj[u->getInfo()].emplace(v->getInfo());
            adj[v->getInfo()].emplace(u->getInfo());
        }
    }

    // Perform BFS to check connectivity
    std::queue<T> q;
    std::set<T>   visited;
    q.push(res.at(0)->getInfo());

    while (!q.empty()) {
        T u = q.front();
        q.pop();
        if (visited.count(u)) continue;
        visited.insert(u);

        for (const T &v : adj[u]) { q.push(v); }
    }

    // Check if all vertices in res are visited
    for (const Vertex<T> *v : res) {
        if (!visited.count(v->getInfo())) return false;
    }

    return true;
}

template <class T>
double spanningTreeCost(const std::vector<Vertex<T> *> &res) {
    double totalCost = 0;

    for (const Vertex<T> *v : res) {
        if (v->getPath() == nullptr) continue;

        const Vertex<T> *u = v->getPath()->getOrig();

        for (const auto *e : u->getAdj()) {
            if (e->getDest()->getInfo() == v->getInfo()) {
                totalCost += e->getWeight();
                break;
            }
        }
    }
    return totalCost;
}

template <class T>
void generateRandomGridGraph(int n, Graph<T> &g) {
    std::random_device                 rd;
    std::mt19937                       gen(rd());
    std::uniform_int_distribution<int> dis(1, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g.addVertex(i * n + j);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i < n - 1) g.addBidirectionalEdge(i * n + j, (i + 1) * n + j, dis(gen));
            if (j < n - 1) g.addBidirectionalEdge(i * n + j, i * n + (j + 1), dis(gen));
        }
}
