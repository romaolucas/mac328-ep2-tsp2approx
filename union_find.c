#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"

subset makeSet(Vertex v) {
    subset s;
    s.parent = v;
    s.rank = 0;
    return s;
}

void Union(subset sets[], Vertex u, Vertex v) {
    Vertex rootU = findSet(sets, u);
    Vertex rootV = findSet(sets, v);
    if (sets[rootU].rank > sets[rootV].rank) {
        sets[rootV].parent = rootU;
    }
    else if (sets[rootU].rank < sets[rootV].rank) {
        sets[rootU].parent = rootV;
    }
    else {
        sets[rootV].parent = rootU;
        sets[rootU].rank++;
    }
}
    
Vertex findSet(subset sets[], Vertex v) {
    if (sets[v].parent != v) 
        sets[v].parent = findSet(sets, sets[v].parent);
    return sets[v].parent;
}
