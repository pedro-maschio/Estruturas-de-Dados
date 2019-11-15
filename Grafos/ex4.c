#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAMANHO 100

typedef struct {
    int dia, mes, ano;
    char descricao[50];
} data_t;

typedef struct {
    char chave;
    data_t data;
} vertice_t; 


typedef struct {
    vertice_t vertices[TAMANHO];
    unsigned int arestas[TAMANHO][TAMANHO];
    unsigned int ordem;
} grafo_t;

vertice_t* vertice(grafo_t* g, char chave) {
    if(!g)
        return NULL;
    if(chave < 65 || chave > 122)
        return NULL;
    
    int i;
    for(i = 0; i < TAMANHO; i++) {
        if(g->vertices[i].chave == chave)
            return &g->vertices[i];
    }
    return NULL;
}
int main() {

    grafo_t *g = malloc(sizeof(grafo_t));
    assert(NULL == vertice(g, 0));

    return 0;
}