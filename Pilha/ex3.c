#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int topo;
    int anilhas[1001];
} Pilha;

void criaPilha(Pilha *pilha) {
    pilha->topo = -1;
}
void empilha(Pilha *pilha, int peso) {
    pilha->anilhas[++pilha->topo] = peso;
}
void retirar(Pilha *pilha, int retira) {
    int pesoTotal = 0, tam = pilha->topo;

    while(pilha->anilhas[tam] >= 0 && pilha->anilhas[tam] != retira) {
        printf("Peso retirado: %d\n", pilha->anilhas[tam]);
        pesoTotal += pilha->anilhas[tam];
        tam--;
    }
    printf("Anilhas retiradas: %d\n", pilha->topo-tam);
    printf("Peso retirado: %d\n", pesoTotal);
}

int main() {
    Pilha *pilha = malloc(sizeof(Pilha));
    criaPilha(pilha);
    int d, retira;

    while(1) {
        scanf("%d", &d);
        if(d == 0)
            break;
        empilha(pilha, d);

    }
    scanf("%d", &retira);
    retirar(pilha, retira);

    return 0;
}