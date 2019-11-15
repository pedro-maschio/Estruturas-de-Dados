#include <stdio.h>
#include <stdlib.h>

typedef struct ab_int {
    int dado;
    struct ab_int *esq;
    struct ab_int *dir;
} ab_int;


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

ab_int* criaNo(int dado) {
    ab_int* novo = (ab_int *) malloc(sizeof(ab_int));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = dado;

    return novo;
}

ab_int* insere(ab_int* raiz, int dado) {
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

void rotaciona_direita(ab_int **raiz) {

}

void comprime(ab_int **p_raiz, int rotacoes) {
    /* Insira o código aqui. */
    ab_int *raiz = *p_raiz;

    int i = 0;
    while(i < rotacoes && raiz != NULL) {
        rotaciona_direita(&raiz);
        i++;
        raiz = raiz->esq;
    }
}
int main() {
    ab_int *root = NULL;

    int i, n, v;

    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &v);
        if(i == 0) 
            root = insere(root, v);
        else 
            insere(root, v);
    }

    return 0;
}