#include <stdio.h>
#include <stdlib.h>
typedef struct ab_char {
    char dado;
    struct ab_char *esq;
    struct ab_char *dir;
} ab_char;

void mostra_arvore(ab_char* raiz) {
    printf("(");
    if(raiz) {
        printf("%c ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
    }
    printf(")");
}

int altura(ab_char *raiz) {
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

void insere(ab_char** p_raiz, ab_char* e) {
    if(!(*p_raiz)) {
        *p_raiz = e;
        return;
    }
    if(altura((*p_raiz)->dir) < altura((*p_raiz)->esq)) {
        insere(&((*p_raiz)->dir), e);
    } else {
        insere(&((*p_raiz)->esq), e);
    }
}
int main() {
    ab_char *e1 = (ab_char *) malloc(sizeof(ab_char));
    e1->esq = e1->dir = NULL;
    e1->dado = 'a';

    ab_char *raiz = NULL;

    insere(&raiz, e1); 
    mostra_arvore(raiz);
    return 0;
}