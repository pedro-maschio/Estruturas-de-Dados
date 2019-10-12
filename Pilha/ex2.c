#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int topo;
    int x[1001];
    char tipo[1001][51], cor[1001][51];
} Pilha;

void cria(Pilha *pilha) {
    pilha->topo = -1;
}

void empilha(Pilha *pilha, char tipo[], char cor[], int x) {
    sprintf(pilha->tipo[++pilha->topo], "%s", tipo);
    sprintf(pilha->cor[pilha->topo], "%s", cor);
    pilha->x[pilha->topo] = x;
}
void print(Pilha *pilha) {
    int i, tam = pilha->topo;
    int tempo = 0;

    for(i = tam; i >= 0; i--) {
        printf("Tipo: %s Cor: %s\n", pilha->tipo[i], pilha->cor[i]);
        tempo += pilha->x[i];
    }
    printf("Total de roupas = %d\n", tam+1);
    printf("Total de tempo = %d\n", tempo);
}

int main() {
    Pilha *pilha = malloc(sizeof(Pilha));
    cria(pilha);

    int x;
    char tipo[51], cor[51];

    while(1) {
        scanf("%s", tipo);
        if(strcmp(tipo, "end") == 0)
            break;
        scanf("%s %d", cor, &x);
        empilha(pilha, tipo, cor, x);
        
    }
    print(pilha);
    return 0;
}