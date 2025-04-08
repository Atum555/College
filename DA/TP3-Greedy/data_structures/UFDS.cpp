/*
 * UFDS.cpp
 * A simple implementation of Union-Find Disjoint Set (UFDS), required by Kruskal's algorithm.
 *
 * Created on: 25/01/2022
 *      Author: Gonçalo Leão
 */

#include "UFDS.h"

UFDS::UFDS(unsigned int N) {
    path.resize(N);
    rank.resize(N);
    for (unsigned long i = 0; i < N; i++) {
        path[i] = i;
        rank[i] = 0;
    }
}

unsigned long UFDS::findSet(unsigned int i) {
    if (path[i] != i) path[i] = findSet(path[i]);
    return path[i];
}

bool UFDS::isSameSet(unsigned int i, unsigned int j) { return findSet(i) == findSet(j); }

void UFDS::linkSets(unsigned int i, unsigned int j) {
    if (!isSameSet(i, j)) {
        unsigned long x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) path[y] = x; // x becomes the root due to having a larger rank
        else {
            path[x] = y;   // y becomes the root due to having a larger rank, or ...
            if (rank[x] == rank[y])
                rank[y]++; // ... due to both nodes having the same rank (in order to break the tie)
        }
    }
}
