#ifndef ALGS_H_INCLUDED
#define ALGS_H_INCLUDED

#include "digraph.h"

int comp(const void* a, const void* b);

Digraph kruskalMST(link edges[], int V);

void dfs(Digraph G);

void dfsVisit(Digraph G, Vertex u);

void printHamiltonianCircuit();

#endif
