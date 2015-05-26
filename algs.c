#include <stdio.h>
#include <stdlib.h>
#include "algs.h"
#include "digraph.h"
#include "union_find.h"

static Vertex* parent;
static int tempo, *d;

int comp(const void* a, const void* b) {
    link la = *(link *) a;
    link lb = *(link *) b;
    return la->weight >= lb->weight;
}

Digraph kruskalMST(link edges[], int V) {
    Digraph G = initDigraph(V);
    int vectorLen = V*(V - 1)/2;
    qsort(edges, vectorLen, sizeof(link), comp);
    subset sets[V];
    for (Vertex v = 0; v < V; v++)
        sets[v] = makeSet(v);
    for (int i = 0; i < vectorLen; i++) {
        if (findSet(sets, edges[i]->v) != findSet(sets, edges[i]->u)) {
            link edge = edges[i];
            printf("%d %d\n", edge->u, edge->v);
            link edge2 = (link) malloc(sizeof *edge2);
            edge2->u = edge->v;
            edge2->v = edge->u;
            edge->next = G->adj[edge->u];
            G->adj[edge->u] = edge;
            edge2->next = G->adj[edge->v];
            G->adj[edge->v] = edge2;
            Union(sets, edges[i]->v, edges[i]->u);
            edges[i] = NULL;
        } 
    }
    return G;
}

void dfs(Digraph G) { 
    parent = (Vertex *) malloc(G->V * sizeof(Vertex));
    d = (int *) malloc(G->V * sizeof(int));
    tempo = 0;
    for (Vertex v = 0; v < G->V; v++) 
        d[v] = -1;
    for (Vertex v = 0; v < G->V; v++) {
        if (d[v] == -1) {
            parent[v] = v;
            dfsVisit(G, v);
            printf("%d ", v);
        }
    }
    printf("\n");
    free(parent);
    free(d);
}

void dfsVisit(Digraph G, Vertex u) {
    d[u] = tempo++;
    printf("%d ", u);
    for (link e = G->adj[u]; e != NULL; e = e->next) {
        if (d[e->v] == -1) {
            parent[e->v] = u;
            dfsVisit(G, e->v);
        }
    }
}
