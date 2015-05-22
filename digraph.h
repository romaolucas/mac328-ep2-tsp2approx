#ifndef DIGRAPH_H_INCLUDED
#define DIGRAPH_H_INCLUDED
#define Vertex int

typedef struct node *link;

struct node {
    Vertex u;  //u e v sao as pontas do meu grafo
    Vertex v;
    link next;
    link antiparallel;
};

struct digraph {
    int V;
    link *adj;
};

typedef struct digraph *Digraph;

Digraph initDigraph(int V);

void printDigraph(Digraph G);

void freeDigraph(Digraph G);

#endif
