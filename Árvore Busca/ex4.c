#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct ab_int {
    int dado;
    struct ab_int *esq, *dir;
} ab_int;
int altura(ab_int *raiz) {
    if(!raiz)   
        return 0;
    else {
        int alturaEsq =  altura(raiz->esq);
        int alturaDir = altura(raiz->dir);

        if(alturaEsq > alturaDir)
            return (alturaEsq + 1);
        else 
            return (alturaDir + 1);
    }
}

void mostra_arvore(ab_int* raiz) {
    printf("(");
    if(raiz) {
        printf("%d ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
    }
    printf(")");
}

void rotaciona_esquerda(ab_int **raiz) {

    if(*raiz == NULL)
        return;
    ab_int *node = *raiz;
    ab_int *temp;

    *raiz = node->dir;
    temp = (*raiz)->esq;
    (*raiz)->esq = node;
    node->dir = temp;

}

void em_lista(ab_int **p_raiz) {
    int i;

    if(p_raiz == NULL || (*p_raiz) == NULL)
        return;
    else {
        for(i = 0; (*p_raiz)->esq != NULL; i++)
            rotaciona_direita(p_raiz);
    }
    
    em_lista(&(*p_raiz)->dir);
}

void comprimir(ab_int **p_raiz, int gira) {
    if(!p_raiz || !(*p_raiz))
        return;
    else {
        int i = 0;
        while(i < gira) {
            rotaciona_esquerda(p_raiz);
            p_raiz = &((*p_raiz)->dir);

            i++;
        }
    }
}

void dsw(ab_int **p_raiz) {
    em_lista(p_raiz); 
    // num nos 2^h - 1, h altura
    int gira = (altura(*p_raiz)-1)/2;
    int i = 0;
    while(i < gira) {
        comprimir(p_raiz, gira);
        gira = gira / 2;
    }
}
int main() {
    

    return 0;
}