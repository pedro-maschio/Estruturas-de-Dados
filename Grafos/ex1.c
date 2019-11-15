#include <stdio.h>
#include <stdlib.h>
typedef struct grafo_t {
    int vertices[TAMANHO];
    int arestas[TAMANHO][TAMANHO];
    int ordem[TAMANHO];
} grafo_t;