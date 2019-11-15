#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 100
typedef struct {
    char vertices[TAMANHO];
    unsigned int arestas[TAMANHO][TAMANHO];
    unsigned int ordem;
} grafo_t;

int idx_vertice(grafo_t* g, char v) {
    if(!g)
        return -1;
    int i;
    for(i = 0; i < TAMANHO; i++) {
        if(g->vertices[i] == v)
            return i;
    }
    return -1;
}

_Bool aresta(grafo_t *g, char a, char b) {
    if(!g)
        return false;
    int l = idx_vertice(g, a);
    int c = idx_vertice(g, b);
    if(l == -1 || c == -1)
        return false;
    
    g->arestas[l][c] = 1;
    g->arestas[c][l] = 1;

    return true;
}

int main() {

}