#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Qua {
    char cor;
    struct Qua *next[4];
} Qua;

int k = 0;

Qua* alocaFolha(char c) {

    Qua *novo = (Qua *) malloc(sizeof(Qua));
    if(!novo)
        return NULL;
    novo->next[0] = novo->next[1] = novo->next[2] = novo->next[3] = NULL;
    novo->cor = c;

    return novo;
}

Qua* geraArvore(char str[], Qua *arvore, int *pos) {

    if(strlen(str) == *pos)
        return arvore;

    if(!arvore) {
        arvore = alocaFolha(str[*pos]);
        geraArvore(str, arvore, &(*pos++));
    }

}



void mostra_arvore(Qua *arvore) {
    printf("(");
    if(arvore) {
        printf("%c ", arvore->cor);
        mostra_arvore(arvore->next[0]);
        printf(" ");
        mostra_arvore(arvore->next[1]);
        printf(" ");
        mostra_arvore(arvore->next[2]);
        printf(" ");
        mostra_arvore(arvore->next[3]);
    }
    printf(")");
}

int main() {
    char str1[1001], str2[1001];
    int i = 0;

    Qua *arvore1 = NULL;
    Qua *arvore2 = NULL;

    scanf("%s", str1);
    arvore1 = geraArvore(str1, arvore1, &i);

    mostra_arvore(arvore1);

    return 0;
}