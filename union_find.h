#ifndef UNION_FIND_H_INCLUDED
#define UNION_FIND_H_INCLUDED

#include "digraph.h"

typedef struct subset subset;

struct subset {
    Vertex parent;
    int rank;
};

subset makeSet(Vertex v);

void Union(subset sets[], Vertex u, Vertex v);

Vertex findSet(subset sets[], Vertex v);

#endif
