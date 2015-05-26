#include <stdio.h>
#include <stdlib.h>
#include "digraph.h"

Digraph initDigraph(int V) {
    Digraph G = malloc(sizeof *G);
    G->V = V;
    G->adj = malloc(V * sizeof(link));
    for (Vertex v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void printDigraph(Digraph G) {
    for (Vertex v = 0; v < G->V; v++)
        for (link e = G->adj[v]; e != NULL; e = e->next)
            printf("%d %d\n", v, e->v);
}

void freeDigraph(Digraph G) {
  for (Vertex v = 0; v < G->V; v++) {
        link e = G->adj[v];
        while (e != NULL) {
            link aux = e;
            e = e->next;
            free(aux);
        }
    }
    free(G->adj);
    free(G);
}
