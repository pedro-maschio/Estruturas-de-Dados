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

int grau_de_entrada(grafo_t* g, char vertice) {
    if(!g)
        return 0;
    if(vertice < 65 || vertice > 122)
        return 0;

    int indice = idx_vertice(g, vertice);

    if(indice == -1)
        return 0;

    int i, sum = 0;

    for(i = 0; i < TAMANHO; i++) {
        if(g->arestas[i][indice] == 1)
            sum++;
    }
    return sum;
}

int main() {


    return 0;
}