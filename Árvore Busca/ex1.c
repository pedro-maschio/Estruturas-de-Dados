#include <stdio.h>
#include <stdlib.h>
typedef struct abb_int {
    int dado;
    struct abb_int *esq;
    struct abb_int *dir;
} abb_int;


void mostra_arvore(abb_int* raiz) {
    printf("(");
    if(raiz) {
        printf("%d ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
    }
    printf(")");
}

abb_int* criaNo(int dado) {
    abb_int* novo = (abb_int *) malloc(sizeof(abb_int));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = dado;

    return novo;
}

abb_int* insere(abb_int* raiz, int dado) {
    if(!raiz)
        return criaNo(dado);
    else {
        if(dado <= raiz->dado)   
            raiz->esq = insere(raiz->esq, dado);
        else 
            raiz->dir = insere(raiz->dir, dado);
    }

    return raiz;
}

void esvazia(abb_int* raiz) {
    if(raiz) {
        esvazia(raiz->esq);
        esvazia(raiz->dir);
        free(raiz);
    }
}

int main() {
    int n, i, v;
    abb_int* root = NULL;
    
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &v);
        if(i == 0)
            root = insere(root, v);
        else 
            insere(root, v);
    }
    mostra_arvore(root);

    return 0;
}