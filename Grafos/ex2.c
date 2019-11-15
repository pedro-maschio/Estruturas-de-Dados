#include <stdio.h>
#include <stdlib.h>
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

int main() {

}