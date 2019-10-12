#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int topo;
    char elemento[1001][101];
} Pilha;


void push(Pilha *pilha, char elemento[]) {
    sprintf(pilha->elemento[++pilha->topo], "%s", elemento);
}

void print(Pilha *pilha) {
    while(pilha->topo > -1) {
        printf("%s\n", pilha->elemento[pilha->topo--]);
    }
}

void empilha(Pilha *num, Pilha *palavras, char entrada[]) {
    int i, count = 0;

    for(i = 0; i < strlen(entrada); i++) {
        if(entrada[i] >= 48 && entrada[i] <= 57)
            count++;
    }
    if(count == strlen(entrada))
        push(num, entrada);
    else 
        push(palavras, entrada);
}

int main() {
    char entrada[1001];

    Pilha *numeros = malloc(sizeof(Pilha));
    Pilha *palavras = malloc(sizeof(Pilha));
    numeros->topo = -1;
    palavras->topo = -1;

    while(strcmp(entrada, "end") != 0) {
        scanf("%s", entrada);
        if(strcmp(entrada, "end") != 0) {
            empilha(numeros, palavras, entrada);
        }
    }
    printf("Palavras:\n");
    print(palavras);
    printf("Numeros:\n");
    print(numeros);
    return 0;
}