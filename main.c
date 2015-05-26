#include <stdio.h>
#include <stdlib.h>
#include "algs.h"
#include "digraph.h"

int main() {
    int n, k;
    scanf("%d", &n);
    link *edges = (link *) malloc((n*(n - 1)/2) * sizeof(link));
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float aux;
            scanf("%f", &aux);
            if (i < j) {
                edges[k] = (link) malloc(sizeof *edges[k]);
                edges[k]->weight = aux;
                edges[k]->u = i;
                edges[k]->v = j;
                k++;
            }
        }
    }
    Digraph G = kruskalMST(edges, n);
    dfs(G);
    for (int i = 0; i < (n*(n - 1)/2); i++)
        if (edges[i] != NULL) free(edges[i]);
    free(edges);
    freeDigraph(G);
    return 0;
}
